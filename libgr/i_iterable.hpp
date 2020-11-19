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
