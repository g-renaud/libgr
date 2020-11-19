#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "abstractlist.hpp"
#include "llnode.hpp"
#include "i_iterator.hpp"
namespace gr
{
	template<typename T>
	class LinkedList : public AbstractList<LLNode<T>>
	{
		private:
			LLNode<T>* _head;
			LLNode<T>* _tail;

		public:
			LinkedList(void);
			~LinkedList(void);
			void add(T);
			void clear(void);
			class Iterator : public i_Iterator<LLNode<T>>
			{
				private:
					LinkedList<T>* _llPtr;
					LLNode<T>* _previous;
					LLNode<T>* _current;
					LLNode<T>* _next;

				public:
					Iterator(LinkedList<T>*);
					bool hasPrevious(void);
					bool hasNext(void);
					void remove(void);
					LLNode<T>* previous(void);
					LLNode<T>* current(void);
					LLNode<T>* next(void);
			};
			Iterator* iterator(void);
	};

	template<typename T>
	LinkedList<T>::LinkedList(void) : _head(nullptr), _tail(nullptr)
	{

	}

	template<typename T>
	LinkedList<T>::~LinkedList(void)
	{
		if((this->_head != nullptr) && this->_size > 0) 
		{
			LLNode<T>* currentNode;
			LLNode<T>* nextNode;
			do
			{
				currentNode = this->_head;
				nextNode = this->_head->getNext();
				AbstractCollection<LLNode<T>>::remove(currentNode);
				this->_head = nextNode;
			}
			while(this->_head != nullptr);
		}
	}

	template<typename T>
	void LinkedList<T>::add(T data)
	{
		if(this->_head == nullptr && this->_tail == nullptr)
		{
			LLNode<T>* node = AbstractCollection<LLNode<T>>::add();
			node->setData(data);
			node->setPrev(nullptr);
			node->setNext(nullptr);
			this->_head = this->_tail = node;
		}
		else
		{
			LLNode<T>* node = AbstractCollection<LLNode<T>>::add();
			node->setData(data);
			node->setPrev(this->_tail);
			node->setNext(nullptr);
			this->_tail->setNext(node);
			this->_tail = node;
		}
	}

	template<typename T>
	void LinkedList<T>::clear(void)
	{
		
	}

	template<typename T>
	typename LinkedList<T>::Iterator* LinkedList<T>::iterator(void)
	{
		return new LinkedList<T>::Iterator(this);
	}
////////////////////////////////////////////////////////////////////////////////
	template<typename T>
	LinkedList<T>::Iterator::Iterator(LinkedList<T>* parent)
	{
		this->_llPtr = parent;
		this->_current = this->_llPtr->_head;
		this->_previous = this->_current->getPrev();
		this->_next = this->_current->getNext();
	}

	template<typename T>
	bool LinkedList<T>::Iterator::hasNext(void)
	{
		if(!(this->_current->getNext() == nullptr))
			return true;
		else
			return false;
	}

	template<typename T>
	bool LinkedList<T>::Iterator::hasPrevious(void)
	{
		if(!(this->_current->getPrev() == nullptr))
			return true;
		else
			return false;
	}

	template<typename T>
	void LinkedList<T>::Iterator::remove(void)
	{
		if(!(this->_current == nullptr))
		{
			if(!(this->_previous == nullptr) && !(this->_next == nullptr))
			{
				delete this->_current;
				// Relinking nodes
				this->_next->setPrev(this->_previous);
				this->_previous->setNext(this->_next);
				// Moving the iterator backwards
				this->_current = this->_previous;
				this->_previous = this->_current->getPrev();
			}
			else if((this->_previous == nullptr) && !(this->_next == nullptr))
			{
				delete this->_current;
				// Relinking nodes
				this->_next->setPrev(nullptr);
				// Moving the iterator forwards
				this->_current = this->_next;
				this->_previous = this->_current->getPrev();
				this->_next = this->_current->getNext();
				// Moving the head since it points now at a deleted pointer
				this->_llPtr->_head = this->_current;
			}
			else if(this->_llPtr->_size > 1)
			{
				delete this->_current;
				// Relinking nodes
				this->_previous->setNext(nullptr);
				// Moving the iterator backwards
				this->_current = this->_previous;
				this->_previous = this->_current->getPrev();
				this->_next = this->_current->getNext();
				// Updating the tail since it points now at a deleted pointer
				this->_llPtr->_tail = this->_current;
			}
			else
			{
				delete this->_current;
			}
			this->_llPtr->_modCount++;
			this->_llPtr->_size--;
		}
	}

	template<typename T>
	LLNode<T>* LinkedList<T>::Iterator::previous(void)
	{
		if(this->hasPrevious())
		{
			this->_next = this->_current;
			this->_current = this->_current->getPrev();
			this->_previous = this->_current->getPrev();
			return this->_current;
		}
		else
		{
			return this->_current;
		}
	}

	template<typename T>
	LLNode<T>* LinkedList<T>::Iterator::current(void)
	{
		return this->_current;
	}

	template<typename T>
	LLNode<T>* LinkedList<T>::Iterator::next(void)
	{
		if(this->hasNext())
		{
			this->_previous = this->_current;
			this->_current = this->_current->getNext();
			this->_next = this->_current->getNext();
			return this->_current;
		}
		else
		{
			return this->_current;
		}
	}
}
#endif // !LINKEDLIST_HPP

