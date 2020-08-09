#ifndef ABSTRACTLIST_HPP
#define ABSTRACTLIST_HPP
#include "abstractcollection.hpp"

namespace gr
{
	template<typename AnyItem> class AbstractList : public AbstractCollection<AnyItem> // AnyItem are nodes of AnyType
	{
		protected:
			unsigned int _modCount;
			AbstractList(void);
			~AbstractList(void);
	};

	template<typename AnyItem> AbstractList<AnyItem>::AbstractList(void) : _modCount(0)
	{

	}

	template<typename AnyItem> AbstractList<AnyItem>::~AbstractList(void)
	{

	}
}

#endif // !ABSTRACTLIST_HPP

