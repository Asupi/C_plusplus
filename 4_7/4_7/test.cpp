#define _CRT_SECURE_NO_WARNINGS


//双端队列迭代器的设计
#include <iostream>
using namespace std;

template<class T,class Ref, class Ptr>
class DequeIterator
{
public:
	typedef DequeIterator<T, Ref, Ptr>self;
	ref operator*()
	{
		return *cur;
	}
	DequeIterator<T, Ref, Ptr>& operator++()
	{
		cur++;
		if (cur == last)
		{
			node++;
			first = *node;//第一次解引用后就是下一段缓冲区第一个元素的地址，第二次解引用后就是下一段缓冲区第一个元素的值
			last = first + bufferLen;
			cur = first;
		}
		return *this;
	}
private:
	T* first;
	T* last;
	T* cur;
	T** node;//指向中控的二级指针

};
template <class>
class Deque
{
public:
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}
private:
	iterator _start;//（通过封装的迭代器）
	iterator _finish;//（通过封装的迭代器）
	T** map;//中控（指针数组）
};