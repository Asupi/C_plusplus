#define _CRT_SECURE_NO_WARNINGS 

#include<list>
#include <queue>
#include <iostream>
#include <functional>
using namespace std;
//class Date
// //����Զ������ͣ������Լ�ȥ���ش��ں�С��
//{
//public:
//	Date(int y, int m, int d)
//		:_y(y)
//		, _m(m)
//		, _d(d)
//	{}
// //����
////��С��С���������С��С��������ȣ���С��С
//	bool operator<(const Date& d) const
//	{
//		return _y < d._y || (_y == d._y && _m < d._m)
//			|| (_y == d._y && _m == d._m && _d < d._d);
//	}
//
//	bool operator>(const Date& d) const
//	{
//		return _y > d._y || (_y == d._y && _m > d._m)
//			|| (_y == d._y && _m == d._m && _d > d._d);
//	}
//
//	friend ostream& operator<<(ostream& _cout, const Date& d);//������Ԫ
//	
//
//private:
//	int _y;
//	int _m;
//	int _d;
//};
//
//
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._y << '-' << d._m << '-' << d._d << endl;
//	return _cout;
//}

//int main()
//{
//	priority_queue<int, vector<int>, greater<int>> pq;
//	pq.push(100);
//	pq.push(50);
//	pq.push(3);
//	pq.push(1);
//	pq.push(18);
//	pq.push(19);
//	while (!pq.empty())
//	{
//		cout << pq.top() << endl;
//		pq.pop();
//	}
//	return 0;
//}

//int main()
//{
//	priority_queue<Date> pq;
//	pq.push(Date(2018, 9, 10));
//	pq.push(Date(2018, 3, 10));
//	pq.push(Date(2018, 7, 5));
//	while (!pq.empty())
//	{
//		cout << pq.top() << endl;
//		pq.pop();
//	}
//	return 0;
//}


//stack��ģ��ʵ��
//template <class T, class Container = deque<T>>
//class Stack
//{
//public:
//	void Push(const T& x)
//	{
//		_con.push_back(x);
//	}
//
//	void Pop() 
//	{
//		_con.pop_back();
//	}
//
//	T& Top()
//	{
//		return _con.back();
//	}
//
//	const T& Top() const
//	{
//		_con.back();
//	}
//
//	size_t Size()
//	{
//		return _con.size();
//	}
//
//	bool Empty()
//	{
//		return _con.empty();
//	}
//private:
//	Container _con;
//};



//int main()
//{
// ���������ڵڶ���ģ���������ʹ�ò�ͬ��������Ȼ���������ɵ�stackЧ����һ���ġ�
//Stack<int, deque<int>> st;
//Stack<int, vector<int>> st;
//Stack<int, list<int>> st;

//	Stack<int> st;
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//	st.Push(5);
//	while (!st.Empty())
//	{
//		cout << st.Top() << " ";
//		st.Pop();
//	}
//	cout << endl;
//	return 0;
//}


//queue��ģ��ʵ��
//template <class T, class Container = deque<T>>
//class Queue
//{
//public:
//	void Push(const T& x)
//	{
//		_con.push_back();
//	}
//	void Pop()
//	{
//		_con.pop_front();
//	}
//	T& Front()
//	{
//		return _con.front();
//	}
//	size_t Size()
//	{
//		return _con.size();
//	}
//	bool Empty()
//	{
//		return _con.empty();
//	}
//	T& Back()
//	{
//		return _con.back();
//	}
//private:
//	Container _con;
//};
//
//int main()
//{

// ���������ڵڶ���ģ���������ʹ�ò�ͬ��������Ȼ���������ɵ�queueЧ����һ���ġ�
//Queue<int, deque<int>> q;
//Queue<int, list<int>> q;

//	Queue<int, deque<int>> q;
//	q.Push(1);
//	q.Push(2);
//	q.Push(3);
//	q.Push(4);
//	q.Push(5);
//	while (!q.Empty())
//	{
//		cout << q.Front() << " ";
//		q.Pop();
//	}
//	cout << endl;
//	return 0;
//}

// �º����� ��������: ����"()"�����
template <class T>
class Greater
{
public:
	bool operator()(const T& a, const T& b)
	{
		return a > b;
	}
};
template <class T>
class Less
{
public:
	bool operator()(const T& a, const T& b)
	{
		return a < b;
	}
};

//int main()
//{
//	Greater<int> g;
//	Less<int> l;
//	//cout << g.operator()(2, 3) << endl;
//	/*cout << g(2, 3) << endl;
//	cout << l(2, 3) << endl;*/
//
//���ȶ��д�����Ƿº��������ͣ�ȷ�����ȶ��е�Ԫ�رȽϹ���
//	priority_queue<int, vector<int>, Less<int>> d;
//	d.push(1);
//	d.push(2);
//	d.push(3);
//	d.push(4);
//	d.push(5);
//	while (!d.empty())
//	{
//		cout << d.top() << endl;
//		d.pop();
//	}
//	return 0;
//}

template <class T, class Container = vector<T>, class Compare = Greater<T>>
class PriortyQueue
{
public:
	void Push(const T& val)
	{
		//�Ȱ�Ԫ�طŵ���������һ��λ��
		_con.push_back(val);
		//���ϵ�����ʹ������ѵ�����
		shiftUp(_con.size() - 1);
	}

	void shiftUp(size_t child)
	{
		//����һ���º�������ͨ���º�������ıȽϹ���Զ�Ԫ�ؽ��е���
		Compare _cmp;
		//�͸��ڵ�Ƚϴ�С
		size_t parent = (child - 1) / 2;
		while (child > 0)
		{
			/*if (_con[child] < _con[parent])*/
			if (_cmp(_con[child], _con[parent]))
			{
				swap(_con[child], _con[parent]);
				//���¸��ӽڵ�λ��
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

	void shiftDown(size_t parent)
	{
		Compare _cmp;
		size_t child = 2 * parent + 1;
		while (child < _con.size())
		{
			//����Һ��Ӵ��ڣ���ֵ�������ӵ�ֵ��ȡ�Һ��ӵ�ֵ
			//if (child + 1 < _con.size() && _con[child + 1] < _con[child])
			if (child + 1 < _con.size() && _cmp(_con[child + 1], _con[child]))
				child++;

			//if (_con[child] < _con[parent])
			if (_cmp(_con[child], _con[parent]))
			{
				swap(_con[child], _con[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
			{
				//�ѵ������Ѿ����㣬��������
				break;
			}
		}

	}
	void Pop()
	{
		//������Ԫ�غ����һ��Ҷ�ӽڵ�Ԫ��
		swap(_con[0], _con[_con.size() - 1]);
		//ɾ�����һ��Ԫ��
		_con.pop_back();
		//�Ӹ������µ�����ʹ������ѵ�����
		shiftDown(0);
	}
	T& Top()
	{
		return _con[0];
	}
	bool Empty()
	{
		return _con.empty();
	}
	size_t Size()
	{
		return _con.size();
	}
public:
	Container _con;

};

int main()
{
	PriortyQueue<int, vector<int>, Less<int>> pq;
	pq.Push(1);
	pq.Push(2);
	pq.Push(3);
	pq.Push(4);
	pq.Push(5);

	while (!pq.Empty())
	{
		cout << pq.Top() << endl;
		pq.Pop();
	}
	system("pause");
	return 0;
}