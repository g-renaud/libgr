#ifndef I_ITERATOR_HPP
#define I_ITERATOR_HPP

namespace gr
{
	template <typename AnyItem> class i_Iterator
	{
		public:
			virtual bool hasNext(void) = 0;
			virtual bool hasPrevious(void) = 0;
			virtual void remove(void) = 0;
			virtual AnyItem next(void) = 0;
	};
}

#endif // !I_ITERATOR_HPP