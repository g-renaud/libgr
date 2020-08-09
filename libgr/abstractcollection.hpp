#ifndef ABSTRACTCOLLECTION_HPP
#define ABSTRACTCOLLECTION_HPP
#include "i_collection.hpp"
//#include <memory>

namespace gr
{
	template<typename AnyItem> class AbstractCollection : public i_Collection<AnyItem>
	{
		private:
			//std::allocator<AnyItem> al;

		protected:
			unsigned int _size;
			AbstractCollection(void);
			~AbstractCollection(void);
			AnyItem* add(void);
			void remove(AnyItem*);
			unsigned int size(void);

		public:
			bool isEmpty(void);
	};

	

	template<typename AnyItem> AbstractCollection<AnyItem>::AbstractCollection(void) : _size(0)
	{

	}

	template<typename AnyItem> AbstractCollection<AnyItem>::~AbstractCollection(void)
	{

	}

	template<typename AnyItem> AnyItem* AbstractCollection<AnyItem>::add(void)
	{
		return new AnyItem();
	}

	template<typename AnyItem> void AbstractCollection<AnyItem>::remove(AnyItem* p)
	{
		delete p;
	}

	template<typename AnyItem> unsigned int AbstractCollection<AnyItem>::size(void)
	{
		return this->_size;
	}

	template<typename AnyItem> bool AbstractCollection<AnyItem>::isEmpty(void)
	{
		return (this->_size == 0);
	}
}

#endif // !ABSTRACTCOLLECTION_HPP

