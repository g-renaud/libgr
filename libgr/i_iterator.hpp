/*
 * This file is part of the libgr
 *
 * This interface should be used for any implementation of an iterator on a
 * collection of items of the same data type. The data type can be a superclass
 * of the derived classes of the elements in the collection. For example, a
 * collection of shapes (superclass) can contain squares (derived class) and
 * triangles (derived class). Any iterator implemented with this interface
 * will be capable of iterating on a such a collection, like the above example.
 *
 * Copyright 2019, 2020 (c) Guillaume Renaud
 *
 */
#ifndef I_ITERATOR_HPP
#define I_ITERATOR_HPP
namespace gr
{
	template<typename T>
	class i_Iterator
	{
		public:
			virtual bool hasPrevious(void) = 0;
			virtual bool hasNext(void) = 0;
			virtual void remove(void) = 0;
			virtual T* previous(void) = 0;
			virtual T* current(void) = 0;
			virtual T* next(void) = 0;
	};
}
#endif // !I_ITERATOR_HPP