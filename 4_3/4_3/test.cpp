
#include <iostream>
using namespace std;


template <class T>
struct ListNode //��������ڵ�
{
	ListNode(const T& val = T())//ȱʡ�Ĺ��캯��
	:_next(nullptr)
	, _prev(nullptr)
	, _data(val)
	{}
	ListNode<T>* _next;//ListNode��������Ա֮һ
	ListNode<T>* _prev;//ListNode��������Ա֮һ
	T _data;//ListNode��������Ա֮һ
};

//�ɶ���д�ĵ�����
template <class T, class Ref, class Ptr>//���͵�template������Ը�������͵�����
                       //����     //ָ�� 
struct ListIterator
{
	typedef ListNode<T>* pNode;
	typedef ListIterator<T, Ref, Ptr> self;//self������ListIterator��һ������
	pNode _node;

	ListIterator(pNode node)
		:_node(node)
	{}

	// ++iterator
	self& operator++()//��int����һ�����������ǰ�üӼ�
	{
		_node = _node->_next;
		return *this;
	}

	//iterator++
	//�ƶ�����һ���ڵ��λ��
	self operator++(int)//��int����һ����������Ǻ��üӼ�
	{
		self tmp(*this);//ֵ����
		_node = _node->_next;
		return tmp;
	}

	self& operator--()//��int����һ�����������ǰ�ü���
	{
		_node = _node->_prev;
		return *this;//���ص��Ǹı�֮��Ķ���
	}
	// it--, ����û�б�֮ǰ��ֵ��Ȼ������--
	self operator--(int)  //��int����һ����������Ǻ��ü���
	{
		self tmp(*this); //����δ�ı�֮ǰ�Ķ���
		_node = _node->_prev;
		return tmp; //���ص���δ�ı�֮ǰ�Ķ���
	}
	//*iterator
	//��ȡ�ڵ��data��������
	Ref operator*()
	{
		return _node->_data;//��ȡ��ǰ�ڵ��ŵ�ֵ
	}

	// struct a{int b, int c, int d}   a *pa, pa->b,
	// iterator->->
	Ptr operator->()
	{
		return &_node->_data;
	}

	// iterator != l.end()
	//�Ƚ�������������װ�Ľڵ��Ƿ�һ��
	bool operator!=(const self& it)
	{
		return _node != it._node;
	}
};

//const�������������޸�Ԫ�ص�ֵ�����Ժ�һ�����������������const T& operator*()��const T* operator->()�������ӿڣ�

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
//	//�ƶ�����һ���ڵ��λ��
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
//	// it--, ����û�б�֮ǰ��ֵ��Ȼ������--
//	self operator--(int)
//	{
//		self tmp(*this);
//		_node = _node->_prev;
//		return tmp;
//	}
//	//*iterator
//	//��ȡ�ڵ��data
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
//	//�Ƚ�������������װ�Ľڵ��Ƿ�һ��
//	bool operator!=(const self& it)
//	{
//		return _node != it._node;
//	}
//};


template <class T>
class List// ��������
{
public:
	typedef ListNode<T> Node;//����ı���
	typedef Node* pNode;
	typedef ListIterator<T, T&, T*> iterator;//��������� 
	//const�����ܵ��÷�const��Ա������ֻ�ܵ���const��Ա������
	//����const��Ա����operator++�� operator--���Ͳ����޸ĳ�Ա_node��ֵ��
	//����const�������޷�ִ��++��--����,�����¶���const����������
	//typedef const ListIterator<T> const_iterator;

	// *it  ->
	typedef ListIterator<T, const T&, const T*> const_iterator;//����const������ 
	List(const T& val = T())//ȱʡ�Ĺ��캯��
		:_head(new Node(val))
	{
		_head->_next = _head;//��ʼ������
		_head->_prev = _head;//��ʼ������
	}

	//���
	List(const List<T>& lst)
	{
		//���ȴ���ͷָ��
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
		//����ÿһ���ڵ�,��������ͷ��ʼ����ÿһ���ڵ�
		//���뵽��ǰlist������ȥ
		for (const auto& e : lst)
		{
			PushBack(e);
		}
	}


	//��ֵ���������
	//��ͳд��
	//List<T>& operator=(const List<T>& lst)
	//{
	//	if (this != &lst)
	//	{
	//		//�ͷ�ԭ�нڵ�
	//		Clear();
	//		for (const auto& e : lst)
	//		{
	//			PushBack(e);
	//		}
	//	}
	//	return *this;
	//}
	//�ִ�д��
	list<T>& operator=(List<T> lst)
	{
		swap(_head, lst._head);//������ͷָ�����ʱ����ͷָ�뽻��������ʱ����ָ��ԭ�пռ䣬����ͷָ��ָ�򿽱�֮��Ŀռ�
		return *this;       //�������������ʱ������������������ͷ�ԭ�пռ�
	}
	//β��
	void PushBack(const T& val	{
		/*pNode curNode = new Node(val);//Ϊ�½ڵ㿪��һ���µĿռ�
		pNode prev = _head->_prev;
		prev->_next = curNode;
		curNode->_prev = prev;
		curNode->_next = _head;
		_head->_prev = curNode;*/
		Insert(end(), val);//end������λ�������ͷ���   //ͷ����ǰ�����һ��λ�ã����൱�������β��
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
		pNode newnode = new Node(val);//Ϊ�½ڵ㿪��һ���µĿռ�
		pNode cur = pos._node;//�õ���ǰλ�ýڵ�
		pNode prev = cur->_prev;//�õ���ǰλ�ýڵ����һ���ڵ�
		prev->_next = newnode;//��һ���ڵ����һ��ָ���½ڵ�
		newnode->_prev = prev;//�½ڵ����һ��ָ����һ���ڵ�
		newnode->_next = cur;//�½ڵ����һ���ǵ�ǰ�ڵ�
		cur->_prev = newnode;//��ǰ�ڵ�ǰһ��ָ���½ڵ�
	}

	void PopFront()
	{
		Erase(begin());
	}

	void PopBack()
	{
		Erase(--end());//βɾ ��Ϊend�����һ��λ�õ���һ��������Ҫ--һ��
	}

	//�������
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



	//Erase�� ������ʧЧ
	//��ȡErase�ķ���ֵ(��ǰ��ɾ���Ľڵ����һ��λ��)�����µ�����
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
			//���µ�����,ָ����һ��λ��
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
	pNode _head;//��ŵ���ListNode��ÿһ���ڵ㣬���Դ���������͵�����
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

//����const������д��ӡ����
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
//		cout << (*lit)._year << endl;//���������ò��������õ����ʽȥ����
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
