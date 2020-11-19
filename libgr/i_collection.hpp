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
