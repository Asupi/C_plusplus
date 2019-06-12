#define _CRT_SECURE_NO_WARNINGS 
#pragma once
//闭散列：线性探测
#include <vector>
using namespace std;
namespace CLOSED
{

	enum STATE { EMPTY, DELETE, EXIST }; //枚举

	template <class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		STATE _state = EMPTY;
	};

	template <class K, class V>
	class HashTable
	{
	public:
		typedef HashNode<K, V> Node;
		typedef Node* pNode;

		HashTable(size_t N = 5)
		{
			_table.resize(N);   // []
			_size = 0;

		}

		bool Insert(const pair<K, V>& kv)
		{
			CheckCapacity();
			//位置映射
			size_t index = kv.first % _table.size();
			while (_table[index]._state == EXIST)
			{
				//unorderedmap/set不允许key重复
				if (_table[index]._kv.first == kv.first)//当前节点的K等于新插入节点的K，插入失败，
					return false;
				//如果不相等则继续向后走
				++index;
				if (index == _table.size())
					index = 0;
			}
			//元素的插入
			_table[index]._kv = kv;
			_table[index]._state = EXIST;//修改状态
			++_size;
			return true;
		}

		pNode Find(const K& key)
		{
			size_t index = key % _table.size();
			while (_table[index]._state != EMPTY)
			{
				if (_table[index]._state == EXIST
					&& _table[index]._kv.first == key)
					return &_table[index];
				++index;
				if (index == _table.size())
					index = 0;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			pNode ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_size;
				return true;
			}
			return false;
		}

		void CheckCapacity()
		{
			//判断是否达到负载值 负载值一般为容量的0.7-0.8
			if (_table.size() == 0
				|| _size * 10 / _table.size() >= 7)
			{
				size_t newC = _table.size() == 0 ? 10 : 2 * _table.size();//如果表的大小为0，则给一个常量，如果不是，则成倍增加
				HashTable<K, V> newHt(newC);
				//拷贝旧表的内容到新表
				for (size_t i = 0; i < _table.size(); i++)
				{
					if (_table[i]._state == EXIST)
					{
						newHt.Insert(_table[i]._kv);
					}
				}
				//将新表置成自己的
				_table.swap(newHt._table);
			}

		}

	private:
		vector<Node> _table;
		size_t _size;
	};
}

template <class V>
struct HashNode   //单链表
{

	HashNode<V>* _next;
	V _data;

	HashNode(const V& data)//构造函数
		:_next(nullptr)
		, _data(data)
	{}
};

//前置声明
template <class K, class V, class KeyOfValue, class HashFun>//定义
class HashTable;

template <class K, class V, class KeyOfValue, class HashFun>
struct __HIterator
{
	typedef HashNode<V> Node;
	typedef Node* pNode;

	typedef __HIterator<K, V, KeyOfValue, HashFun> Self;
	typedef HashTable<K, V, KeyOfValue, HashFun> HashT;

	pNode _node;
	HashT* _ht;

	__HIterator(pNode node, HashT* ht)
		:_node(node)
		, _ht(ht)
	{}

	V& operator*()
	{
		return _node->_data;
	}

	V* operator->()
	{
		return &operator*();
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Self& operator++()
	{
		if (_node->_next)
			_node = _node->_next;
		else
		{
			//计算迭代器中节点在表中的index
			KeyOfValue kov;
			size_t index = _ht->HashIndex(kov(_node->_data), _ht->_table.size());
			++index;
			//向后搜索，找到第一个非空链表的头节点，即为下一个元素的位置
			for (; index < _ht->_table.size(); ++index)
			{
				if (_ht->_table[index])
				{
					_node = _ht->_table[index];
					break;
				}
			}
			//如果走到表尾，说明无有效元素
			if (index == _ht->_table.size())
			{
				_node = nullptr;
			}
		}
		return *this;
	}

};

/*
KeyOfValue: 仿函数类，获取data对应的key
HashFun: 仿函数类， 获取key对应的hash值，本质上返回的为key转换之后的整数值
*/
template <class K, class V, class KeyOfValue, class HashFun>
class HashTable
{
public:
	typedef HashNode<V> Node;
	typedef Node* pNode;

	//泛型友元声明，迭代器需要访问哈希表的私有成员
	template <class K, class V, class KeyOfValue, class HashFun>
	friend struct __HIterator;

	typedef __HIterator<K, V, KeyOfValue, HashFun> iterator;

	iterator begin()
	{
		//begin: 第一个非空链表的头节点
		for (size_t i = 0; i < _table.size(); ++i)
		{
			if (_table[i])
				return iterator(_table[i], this);
		}
		//空表
		return iterator(nullptr, this);
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}



	pair<iterator, bool> Insert(const V& data)
	{
		CheckCapacity();
		//通过kov仿函数对象获取data的key
		//通过hashFun仿函数转换key, 返回整数值
		//整数值 % _table.size() 计算data在哈希表中对应的位置index
		KeyOfValue kov;
		size_t index = HashIndex(kov(data), _table.size());
		pNode cur = _table[index];
		while (cur)
		{
			if (kov(cur->_data) == kov(data))
				return make_pair(iterator(cur, this), false);
			cur = cur->_next;
		}

		cur = new Node(data);
		//头插
		cur->_next = _table[index];//新节点的next指向原来的头结点
		_table[index] = cur;

		++_size;
		return make_pair(iterator(cur, this), true);

	}


	size_t getNextPrime(const size_t prime)
	{
		static const int PRIMECOUNT = 28;
		static const size_t primeList[PRIMECOUNT] =
		{
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
			49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
			1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
			50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
			1610612741ul, 3221225473ul, 4294967291ul
		};

		for (size_t i = 0; i < PRIMECOUNT; ++i)
		{
			if (primeList[i] > prime)
				return primeList[i];
		}

		return primeList[PRIMECOUNT - 1];
	}

	void CheckCapacity()
	{
		if (_size == _table.size())
		{
			//size_t newC = _table.size() == 0 ? 1 : 2 * _table.size();
			size_t newC = getNextPrime(_table.size());
			vector<pNode> newTable;
			//新建一个表，旧表元素挂到新表当中
			newTable.resize(newC);
			KeyOfValue kov;
			//遍历旧表
			for (size_t i = 0; i < _table.size(); i++)
			{
				pNode cur = _table[i];
				while (cur)
				{
					pNode next = cur->_next;
					//位置重新计算
					size_t index = HashIndex(kov(cur->_data), newTable.size());
					//头插
					cur->_next = newTable[index];
					newTable[index] = cur;

					cur = next;
				}
				_table[i] = nullptr;
			}
			//旧表新表交换
			_table.swap(newTable);
		}
	}

	iterator Find(const K& key)
	{
		size_t index = HashIndex(key, _table.size());
		pNode cur = _table[index];
		KeyOfValue kov;
		while (cur)
		{
			if (kov(cur->_data) == key)
				return iterator(cur, this);
			cur = cur->_next;
		}

		return end();
	}

	bool Erase(const K& key)
	{
		size_t index = HashIndex(key, _table.size());
		pNode cur = _table[index];
		pNode prev = nullptr;
		KeyOfValue kov;
		while (cur)
		{
			if (kov(cur->_data) == key)
			{
				if (prev)
					prev->_next = cur->_next;
				else
					//删除的是链表的头节点，更新头节点
					_table[index] = cur->_next;

				delete cur;
				--_size;
				return true;
			}
			prev = cur;
			cur = cur->_next;
		}
		return false;
	}


	size_t HashIndex(const K& key, size_t sz)
	{
		//把key转换为整数
		HashFun hfun;
		return hfun(key) % sz;
	}

private:
	vector<pNode> _table;
	size_t _size = 0;
};



