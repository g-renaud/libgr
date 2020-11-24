/*
 * This file is part of the libgr
 *
 * This interface should be used for any implementation of data structures
 * that models collection of objects upon which one can iterate upon, such
 * as lists. However, this interface should not be used for collections that
 * are not iterable, such as associative collections like maps or dictionaries.
 * The add/remove functionalities provided by this interface should always act
 * upon data nodes of the collection, like adding/removing nodes from a linked
 * list.
 * 
 * Copyright 2019, 2020 (c) Guillaume Renaud
 *
 */
#ifndef I_COLLECTION_HPP
#define I_COLLECTION_HPP
#include "i_iterable.hpp"
namespace gr
{
	template<typename E>
	class i_Collection : public i_Iterable<E>
	{
		public:
			virtual unsigned int getSize(void) = 0;
			virtual bool isEmpty(void) = 0;
			virtual E* add(void) = 0;
			virtual void remove(E*) = 0;
			virtual void clear(void) = 0;
	};
}
#endif // !I_COLLECTION_HPP
