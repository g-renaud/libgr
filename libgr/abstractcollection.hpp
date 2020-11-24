/*
 * This file is part of the libgr
 *
 * This abstract class provides basic functionalities for operating on any
 * iterable collection that derives this abstract class. Functionalities for
 * specific types of collections should be implemented in derived classes by
 * using these basic functionalities, plus any necessary instructions proper
 * to those derived classes. For example, a linked list should use this add
 * method for initializing the node to be added and updating the counts for
 * the size and the number of modifications of that linked list, but the
 * instructions for linking those nodes between them should remain in the
 * linked list class that derives this abstract class.
 *
 * Copyright 2019, 2020 (c) Guillaume Renaud
 *
 */
#ifndef ABSTRACTCOLLECTION_HPP
#define ABSTRACTCOLLECTION_HPP
#include "i_collection.hpp"
//#include <memory>
namespace gr
{
	template<typename E>
	class AbstractCollection : public i_Collection<E>
	{
		private:
			//std::allocator<AnyItem> al;

		protected:
			unsigned int _size = 0;
			unsigned int _modCount = 0;
			E* _root = nullptr;

		public:
			unsigned int getSize(void);
			bool isEmpty(void);
			E* add(void);
			void remove(E*);
	};

	template<typename E>
	unsigned int AbstractCollection<E>::getSize(void)
	{
		return this->_size;
	}

	template<typename E>
	bool AbstractCollection<E>::isEmpty(void)
	{
		return (this->_size == 0);
	}

	template<typename E>
	E* AbstractCollection<E>::add(void)
	{
		if(this->isEmpty() == true)
		{
			this->_root = new E();
			this->_size++;
			this->_modCount++;
			return this->_root;
		}
		else
		{
			this->_size++;
			this->_modCount++;
			return new E();
		}
	}

	template<typename E>
	void AbstractCollection<E>::remove(E* p)
	{
		delete p;
		this->_size--;
		this->_modCount++;
	}
}
#endif // !ABSTRACTCOLLECTION_HPP

