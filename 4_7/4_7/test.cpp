#define _CRT_SECURE_NO_WARNINGS


//˫�˶��е����������
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
			first = *node;//��һ�ν����ú������һ�λ�������һ��Ԫ�صĵ�ַ���ڶ��ν����ú������һ�λ�������һ��Ԫ�ص�ֵ
			last = first + bufferLen;
			cur = first;
		}
		return *this;
	}
private:
	T* first;
	T* last;
	T* cur;
	T** node;//ָ���пصĶ���ָ��

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
	iterator _start;//��ͨ����װ�ĵ�������
	iterator _finish;//��ͨ����װ�ĵ�������
	T** map;//�пأ�ָ�����飩
};