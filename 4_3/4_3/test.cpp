
#include <iostream>
using namespace std;


template <class T>
struct ListNode //定义链表节点
{
	ListNode(const T& val = T())//缺省的构造函数
	:_next(nullptr)
	, _prev(nullptr)
	, _data(val)
	{}
	ListNode<T>* _next;//ListNode的三个成员之一
	ListNode<T>* _prev;//ListNode的三个成员之一
	T _data;//ListNode的三个成员之一
};

//可读可写的迭代器
template <class T, class Ref, class Ptr>//泛型的template里面可以跟多个类型的声明
                       //引用     //指针 
struct ListIterator
{
	typedef ListNode<T>* pNode;
	typedef ListIterator<T, Ref, Ptr> self;//self类似于ListIterator的一个别名
	pNode _node;

	ListIterator(pNode node)
		:_node(node)
	{}

	// ++iterator
	self& operator++()//无int这样一个标记所以是前置加加
	{
		_node = _node->_next;
		return *this;
	}

	//iterator++
	//移动到下一个节点的位置
	self operator++(int)//有int这样一个标记所以是后置加加
	{
		self tmp(*this);//值拷贝
		_node = _node->_next;
		return tmp;
	}

	self& operator--()//无int这样一个标记所以是前置减减
	{
		_node = _node->_prev;
		return *this;//返回的是改变之后的东西
	}
	// it--, 返回没有变之前的值，然后自身--
	self operator--(int)  //有int这样一个标记所以是后置减减
	{
		self tmp(*this); //拷贝未改变之前的东西
		_node = _node->_prev;
		return tmp; //返回的是未改变之前的东西
	}
	//*iterator
	//获取节点的data，解引用
	Ref operator*()
	{
		return _node->_data;//获取当前节点存放的值
	}

	// struct a{int b, int c, int d}   a *pa, pa->b,
	// iterator->->
	Ptr operator->()
	{
		return &_node->_data;
	}

	// iterator != l.end()
	//比较两个迭代器封装的节点是否一样
	bool operator!=(const self& it)
	{
		return _node != it._node;
	}
};

//const迭代器（不能修改元素的值，所以和一般迭代器的区别在于const T& operator*()，const T* operator->()这两个接口）

//template <class T>
//struct ConstListIterator
//{
//	typedef ListNode<T>* pNode;
//	typedef ConstListIterator<T> self;
//	pNode _node;
//
//	ConstListIterator(pNode node)
//		:_node(node)
//	{}
//
//	// ++iterator
//	self& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//
//	//iterator++
//	//移动到下一个节点的位置
//	self operator++(int)
//	{
//		self tmp(*this);
//		_node = _node->_next;
//		return tmp;
//	}
//
//	self& operator--()
//	{
//		_node = _node->_prev;
//		return *this;
//	}
//	// it--, 返回没有变之前的值，然后自身--
//	self operator--(int)
//	{
//		self tmp(*this);
//		_node = _node->_prev;
//		return tmp;
//	}
//	//*iterator
//	//获取节点的data
//	const T& operator*()
//	{
//		return _node->_data;
//	}
//
//	// struct a{int b, int c, int d}   a *pa, pa->b,
//	// iterator->->
//	const T* operator->()
//	{
//		return &_node->_data;
//	}
//
//	// iterator != l.end()
//	//比较两个迭代器封装的节点是否一样
//	bool operator!=(const self& it)
//	{
//		return _node != it._node;
//	}
//};


template <class T>
class List// 定义链表
{
public:
	typedef ListNode<T> Node;//定义的别名
	typedef Node* pNode;
	typedef ListIterator<T, T&, T*> iterator;//定义迭代器 
	//const对象不能调用非const成员函数，只能调用const成员函数，
	//但是const成员函数operator++， operator--，就不能修改成员_node的值，
	//导致const迭代器无法执行++，--操作,故如下定义const迭代器不行
	//typedef const ListIterator<T> const_iterator;

	// *it  ->
	typedef ListIterator<T, const T&, const T*> const_iterator;//定义const迭代器 
	List(const T& val = T())//缺省的构造函数
		:_head(new Node(val))
	{
		_head->_next = _head;//初始化链表
		_head->_prev = _head;//初始化链表
	}

	//深拷贝
	List(const List<T>& lst)
	{
		//首先创建头指针
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
		//拷贝每一个节点,迭代器从头开始遍历每一个节点
		//插入到当前list对象中去
		for (const auto& e : lst)
		{
			PushBack(e);
		}
	}


	//赋值运算符重载
	//传统写法
	//List<T>& operator=(const List<T>& lst)
	//{
	//	if (this != &lst)
	//	{
	//		//释放原有节点
	//		Clear();
	//		for (const auto& e : lst)
	//		{
	//			PushBack(e);
	//		}
	//	}
	//	return *this;
	//}
	//现代写法
	list<T>& operator=(List<T> lst)
	{
		swap(_head, lst._head);//把他的头指针和临时对象头指针交换，让临时对象指向原有空间，他的头指针指向拷贝之后的空间
		return *this;       //出了作用域后临时对象调用析构函数，释放原有空间
	}
	//尾插
	void PushBack(const T& val	{
		/*pNode curNode = new Node(val);//为新节点开辟一个新的空间
		pNode prev = _head->_prev;
		prev->_next = curNode;
		curNode->_prev = prev;
		curNode->_next = _head;
		_head->_prev = curNode;*/
		Insert(end(), val);//end迭代器位于链表的头结点   //头结点的前面插入一个位置，就相当于链表的尾插
	}
	void PushFront(const T& val)
	{
		Insert(begin(), val);
	}

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}

	const_iterator end() const
	{
		return const_iterator(_head);
	}

	void Insert(iterator pos, const T& val)
	{
		pNode newnode = new Node(val);//为新节点开辟一个新的空间
		pNode cur = pos._node;//拿到当前位置节点
		pNode prev = cur->_prev;//拿到当前位置节点的上一个节点
		prev->_next = newnode;//上一个节点的下一个指向新节点
		newnode->_prev = prev;//新节点的上一个指向上一个节点
		newnode->_next = cur;//新节点的下一个是当前节点
		cur->_prev = newnode;//当前节的前一个指向新节点
	}

	void PopFront()
	{
		Erase(begin());
	}

	void PopBack()
	{
		Erase(--end());//尾删 因为end是最后一个位置的下一个，所以要--一下
	}

	//清空链表
	void Clear()
	{
		if (_head)
		{
			pNode cur = _head->_next;
			while (cur != _head)
			{
				pNode next = cur->_next;
				delete cur;
				cur = next;
			}
			_head->_next = _head;
			_head->_prev = _head;
		}
	}



	//Erase： 迭代器失效
	//获取Erase的返回值(当前被删除的节点的下一个位置)，更新迭代器
	iterator Erase(iterator pos)
	{
		if (pos != end())
		{
			pNode cur = pos._node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			//更新迭代器,指向下一个位置
			pos = iterator(next);
		}
		return pos;
	}


	
	~List()
	{
		Clear();
		if (_head)
		{
			delete _head;
			_head = nullptr;
		}

	}


private:
	pNode _head;//存放的是ListNode的每一个节点，可以存放任意类型的数据
};


class Date
{
public:
	int _year;
	int _month;
	int _day;
};

//int main()
//{
//	List<int> lst;
//	lst.PushBack(1);
//	lst.PushBack(2);
//	lst.PushBack(3);
//	lst.PushBack(4);
//
//	auto lit = lst.begin();
//	while (lit != lst.end())
//	{
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;
//
//	return 0;
//}

//调用const迭代器写打印函数
template <class T>
void PrintList(const List<T>& lt)
{
	auto lit = lt.begin();
	while (lit != lt.end())
	{
		//*lit = 10;
		cout << *lit << " ";
		++lit;
	}
	cout << endl;
}

//void testList2()
//{
//	List<Date> lst;
//	lst.PushBack(Date());
//	lst.PushBack(Date());
//	lst.PushBack(Date());
//	auto lit = lst.begin();
//	while (lit != lst.end())
//	{
//		// &Date->_year
//		lit.operator->()->_year = 2018;
//		lit->_year = 2018;
//		lit->_month = 1;
//		lit->_day = 1;
//		cout << (*lit)._year << endl;//先做解引用操作，再用点的形式去访问
//		cout << lit->_year <<"-"<<lit->_month <<"-"<<lit->_day << " ";
//		++lit;
//	}
//	cout << endl;
//
//}

void testList3()
{
	List<int> lst;
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);
	lst.PushBack(4);
	lst.Erase(lst.begin());

	PrintList(lst);

	lst.Erase(--lst.end());
	PrintList(lst);

	List<int> copy(lst);
	PrintList(copy);

}

int main()
{
	testList3();
	return 0;
}
