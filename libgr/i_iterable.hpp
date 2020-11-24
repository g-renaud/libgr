/*
 * This file is part of the libgr
 *
 * This interface should be used for any implementation of any collection
 * of items upon which one wants to iterate on. Those collections of items
 * can be any data structure that implements such collections, such as
 * vectors, lists, trees, stacks, queues, and so on. By providing an
 * iterator, one can access, remove or add data nodes in the collection
 * without traversing the whole collection from the beginning, as long
 * as the iterator is already at the desired location.
 *
 * Copyright 2019, 2020 (c) Guillaume Renaud
 *
 */
#ifndef I_ITERABLE_HPP
#define I_ITERABLE_HPP
#include "i_iterator.hpp"
namespace gr
{
	template<typename T>
	class i_Iterable
	{
		public:
			virtual i_Iterator<T>* iterator(void) = 0;
	};
}
#endif // !I_ITERABLE_HPP
