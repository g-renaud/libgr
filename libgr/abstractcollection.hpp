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

