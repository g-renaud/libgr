#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "abstractlist.hpp"
#include "llnode.hpp"

namespace gr
{
	template<typename AnyType> class LinkedList : public AbstractList<llnode<AnyType>>
	{
		private:
			llnode<AnyType>* _head;
			llnode<AnyType>* _tail;

		public:
			LinkedList(void);
			~LinkedList(void);
			void addNode(AnyType);
	};

	template<typename AnyType> LinkedList<AnyType>::LinkedList(void) : _head(nullptr), _tail(nullptr)
	{

	}

	template<typename AnyType> LinkedList<AnyType>::~LinkedList(void)
	{
		if(this->_head != nullptr && this->_tail != nullptr)
		{
			llnode<AnyType>* currentNode;
			llnode<AnyType>* nextNode;
			do
			{
				currentNode = this->_head;
				nextNode = this->_head->getNext();
				AbstractCollection<llnode<AnyType>>::remove(currentNode);
				this->_head = nextNode;
			}
			while(this->_head != nullptr);
		}
	}

	template<typename AnyType> void LinkedList<AnyType>::addNode(AnyType data)
	{
		if(this->_head == nullptr && this->_tail == nullptr)
		{
			llnode<AnyType>* newNode = AbstractCollection<llnode<AnyType>>::add();
			newNode->setData(data);
			this->_head = this->_tail = newNode;
			this->_size++;
			this->_modCount++;
		}
		else
		{
			llnode<AnyType>* newNode = AbstractCollection<llnode<AnyType>>::add();
			newNode->setData(data);
			this->_tail->setNext(newNode);
			newNode->setPrev(this->_tail);
			this->_tail = newNode;
			this->_size++;
			this->_modCount++;
		}
	}
}

#endif // !LINKEDLIST_HPP

