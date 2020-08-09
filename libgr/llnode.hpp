#ifndef LLNODE_HPP
#define LLNODE_HPP

namespace gr
{
	template<typename AnyType> class llnode
	{
		private:
			AnyType _data;
			llnode<AnyType>* _prev;
			llnode<AnyType>* _next;

		public:
			llnode(void);
			llnode(AnyType);
			~llnode(void);
			void setData(AnyType);
			void setPrev(llnode*);
			void setNext(llnode*);
			AnyType getData(void);
			llnode<AnyType>* getPrev(void);
			llnode<AnyType>* getNext(void);
	};

	template<typename AnyType> llnode<AnyType>::llnode(void) : _prev(nullptr), _next(nullptr)
	{

	}

	template<typename AnyType> llnode<AnyType>::llnode(AnyType data) : _prev(nullptr), _next(nullptr), _data(data)
	{

	}

	template<typename AnyType> llnode<AnyType>::~llnode(void)
	{

	}

	template<typename AnyType> void llnode<AnyType>::setData(AnyType data)
	{
		this->_data = data;
	}

	template<typename AnyType> void llnode<AnyType>::setPrev(llnode* prev)
	{
		this->_prev = prev;
	}

	template<typename AnyType> void llnode<AnyType>::setNext(llnode* next)
	{
		this->_next = next;
	}

	template<typename AnyType> AnyType llnode<AnyType>::getData(void)
	{
		return this->_data;
	}

	template<typename AnyType> llnode<AnyType>* llnode<AnyType>::getPrev(void)
	{
		return this->_prev;
	}

	template<typename AnyType> llnode<AnyType>* llnode<AnyType>::getNext(void)
	{
		return this->_next;
	}
}

#endif // !LLNODE_HPP

