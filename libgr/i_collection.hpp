#ifndef I_COLLECTION_HPP
#define I_COLLECTION_HPP
#include "i_iterable.hpp"

namespace gr
{
	template<typename AnyItem> class i_Collection : public i_Iterable<AnyItem>
	{
		protected:
			virtual AnyItem* add(void) = 0;
			virtual void remove(AnyItem*) = 0;
			//virtual void clear(void) = 0;
			//virtual unsigned int hashCode(void) = 0;
			virtual unsigned int size(void) = 0;

		public:
			virtual bool isEmpty(void) = 0;
	};
}

#endif // !I_COLLECTION_HPP
