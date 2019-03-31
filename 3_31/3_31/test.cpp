#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
template<class T>
class Vector
{
public:
	//������
	typedef T* iterator;
	typedef const T* const_iterator;
	Vector()
		: _start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}
	const_iterator begin() const
	{
		return _start;
	}
	const_iterator end() const
	{
		return _finish;
	}
	


	Vector(const Vector<T>& v)
	{
		//���ٿռ�
		T* _start = new T[v.Capacity()];
		//�������ݣ����
		for (int i = 0; i < v.Size(); i++)
		{
			_start[i] = v[i];
		}
		//����
		_finish = _start + v.Size();
		_endOfStorage = _start + v.Capacity();
	}
	//���������
	T& operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}

	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStorage, v._endOfStorage);
	}
	size_t Size() const
	{
		return  _finish - _start;
	}
	size_t Capacity() const
	{
		return  _endOfStorage - _start;
	}
	void PushBack(const T&val)
	{
		if (_finish == _endOfStorage)
		{
			size_t newC = (_start == nullptr?  1:2*Capacity());
			Reserve(newC);
		}
		*_finish = val;
		++_finish;
	}
	void Reserve(size_t n)
	{
		if (n > Capacity())
		{
			size_t sz = Size();
			//�����µĿռ�
			T* tmp = new T[n];
			//���ռ��Ƿ�Ϊ��
			if (_start)
			{
				//����ԭ�пռ�����, ǳ����
				//memcpy(tmp, _start, sizeof(T)* sz);
				//���������T���͵ĸ�ֵ�����������ɿ���
				for (int i = 0; i < sz; i++)
				{
					tmp[i] = _start[i];
				}

				//�ͷ�ԭ�пռ�
				delete[] _start;
			}
			//����size, capacity
			_start = tmp;
			//����size
			_finish = _start + sz;
			//��������
			_endOfStorage = _start + n;
		}
	}

	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}

	const T& operator[](size_t pos) const
	{
		assert(pos < Size());
		return _start[pos];
	}
	//insert ����
	//insert, erase ���ڵ�����ʧЧ����
	//insert: ���ݵ��µ�����ʧЧ�� ������֮����µ�����
	void Insert(iterator pos, const T& val)
	{
		assert(pos >= _start && pos <= _finish);
		size_t len = pos - _start;
		if (_finish == _endOfStorage)
		{
			size_t newC = (_start == nullptr ? 1 : 2 * Capacity());
			Reserve(newC);
		}
		//�����Ժ���µ�����
		pos = _start + len;
		iterator end = _finish;
		//�Ӻ���ǰŲ��Ԫ��
		while (end > pos)
		{
			*end = *(end - 1);
			--end;
		}
		//��posλ�ò���Ԫ��val
		*pos = val;
		//����_finishָ��
		++_finish;
	}

	//eraseɾ��
	iterator Erase(iterator pos)
	{
		// Ų�����ݽ���ɾ��
		iterator begin = pos + 1;
		while (begin < _finish)
		{
			*(begin - 1) = *begin;
			++begin;
		}
		--_finish;
		return pos;
	}
	//resize
	void Resize(size_t n, const T& val = T())
	{
		// 1.���nС�ڵ�ǰ��size�������ݸ�����С��n
		if (n <= Size())
		{
			_finish = _start + n;
			return;
		}
		// 2.�ռ䲻��������
		if (n > Capacity())
		{
			Reserve(n);
		}
		// 3.��size����n
		while (_finish != _start + n)
		{
			*_finish = val;
			++_finish;
		}
	}
	//����
	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	}

private:
	T* _start;
	T* _finish;
	T* _endOfStorage;
};
template <class T>
void PrintVector(const Vector<T>& v)
{
	for (int i = 0; i < v.Size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

template <class T>
void PrintVectorFor(const Vector<T>& v)
{
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
//int main()
//{
//	Vector<string> v2;
//	/*Vector<int> v1;
//	v1.PushBack(1);
//	v1.PushBack(1);
//	v1.PushBack(1);
//	v1.PushBack(1);
//	v1.PushBack(1);*/
//	v2.PushBack("1");
//	v2.PushBack("1");
//	v2.PushBack("1");
//	v2.PushBack("1");
//
//	return 0;
//}

void testVector1()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(56);

	PrintVectorFor(v);

	Vector<string> v2;
	v2.PushBack("hello");
	v2.PushBack("world");
	v2.PushBack("bite");
	v2.PushBack("tech");
	v2.PushBack("school");
	PrintVectorFor(v2);

}

void testVector2()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	//v.PushBack(56);
	Vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		if (*vit % 2 == 0)
			v.Erase(vit);
		else
			vit++;
	}
	PrintVectorFor(v);
}
#include <vector>
void testVector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//v.PushBack(56);
	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		if (*vit % 2 == 0)
			vit = v.erase(vit);
		else
			vit++;
	}
}

void testVector4()
{
	Vector<string> v2;
	v2.PushBack("hello");
	v2.PushBack("world");
	v2.PushBack("bite");
	v2.PushBack("tech");
	v2.PushBack("school");
	PrintVectorFor(v2);
	string s = "abc";  // string(const char* str)
	v2.Resize(18, "abc");
	PrintVectorFor(v2);
}

int main()
{
	testVector4();
	system("pause");
	return 0;
}

