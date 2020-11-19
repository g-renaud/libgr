#ifndef LLNODE_HPP
#define LLNODE_HPP
namespace gr
{
	template<typename T>
	class LLNode
	{
		private:
			T _data;
			LLNode<T>* _prev;
			LLNode<T>* _next;

		public:
			LLNode(void);
			LLNode(T);
			~LLNode(void);
			void setData(T);
			void setPrev(LLNode*);
			void setNext(LLNode*);
			T getData(void);
			LLNode<T>* getPrev(void);
			LLNode<T>* getNext(void);
	};

	template<typename T>
	LLNode<T>::LLNode(void) : _prev(nullptr), _next(nullptr)
	{
		
	}

	template<typename T>
	LLNode<T>::LLNode(T d) : _prev(nullptr), _next(nullptr), _data(d)
	{

	}

	template<typename T>
	LLNode<T>::~LLNode(void)
	{
		this->_prev = nullptr;
		this-> _next = nullptr;
	}

	template<typename T>
	void LLNode<T>::setData(T d)
	{
		this->_data = d;
	}

	template<typename T>
	void LLNode<T>::setPrev(LLNode* p)
	{
		this->_prev = p;
	}

	template<typename T>
	void LLNode<T>::setNext(LLNode* n)
	{
		this->_next = n;
	}

	template<typename T>
	T LLNode<T>::getData(void)
	{
		return this->_data;
	}

	template<typename T>
	LLNode<T>* LLNode<T>::getPrev(void)
	{
		return this->_prev;
	}

	template<typename T>
	LLNode<T>* LLNode<T>::getNext(void)
	{
		return this->_next;
	}
}
#endif // !LLNODE_HPP

