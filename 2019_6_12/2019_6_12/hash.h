#define _CRT_SECURE_NO_WARNINGS 
#pragma once
//��ɢ�У�����̽��
#include <vector>
using namespace std;
namespace CLOSED
{

	enum STATE { EMPTY, DELETE, EXIST }; //ö��

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
			//λ��ӳ��
			size_t index = kv.first % _table.size();
			while (_table[index]._state == EXIST)
			{
				//unorderedmap/set������key�ظ�
				if (_table[index]._kv.first == kv.first)//��ǰ�ڵ��K�����²���ڵ��K������ʧ�ܣ�
					return false;
				//������������������
				++index;
				if (index == _table.size())
					index = 0;
			}
			//Ԫ�صĲ���
			_table[index]._kv = kv;
			_table[index]._state = EXIST;//�޸�״̬
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
			//�ж��Ƿ�ﵽ����ֵ ����ֵһ��Ϊ������0.7-0.8
			if (_table.size() == 0
				|| _size * 10 / _table.size() >= 7)
			{
				size_t newC = _table.size() == 0 ? 10 : 2 * _table.size();//�����Ĵ�СΪ0�����һ��������������ǣ���ɱ�����
				HashTable<K, V> newHt(newC);
				//�����ɱ�����ݵ��±�
				for (size_t i = 0; i < _table.size(); i++)
				{
					if (_table[i]._state == EXIST)
					{
						newHt.Insert(_table[i]._kv);
					}
				}
				//���±��ó��Լ���
				_table.swap(newHt._table);
			}

		}

	private:
		vector<Node> _table;
		size_t _size;
	};
}

template <class V>
struct HashNode   //������
{

	HashNode<V>* _next;
	V _data;

	HashNode(const V& data)//���캯��
		:_next(nullptr)
		, _data(data)
	{}
};

//ǰ������
template <class K, class V, class KeyOfValue, class HashFun>//����
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
			//����������нڵ��ڱ��е�index
			KeyOfValue kov;
			size_t index = _ht->HashIndex(kov(_node->_data), _ht->_table.size());
			++index;
			//����������ҵ���һ���ǿ������ͷ�ڵ㣬��Ϊ��һ��Ԫ�ص�λ��
			for (; index < _ht->_table.size(); ++index)
			{
				if (_ht->_table[index])
				{
					_node = _ht->_table[index];
					break;
				}
			}
			//����ߵ���β��˵������ЧԪ��
			if (index == _ht->_table.size())
			{
				_node = nullptr;
			}
		}
		return *this;
	}

};

/*
KeyOfValue: �º����࣬��ȡdata��Ӧ��key
HashFun: �º����࣬ ��ȡkey��Ӧ��hashֵ�������Ϸ��ص�Ϊkeyת��֮�������ֵ
*/
template <class K, class V, class KeyOfValue, class HashFun>
class HashTable
{
public:
	typedef HashNode<V> Node;
	typedef Node* pNode;

	//������Ԫ��������������Ҫ���ʹ�ϣ���˽�г�Ա
	template <class K, class V, class KeyOfValue, class HashFun>
	friend struct __HIterator;

	typedef __HIterator<K, V, KeyOfValue, HashFun> iterator;

	iterator begin()
	{
		//begin: ��һ���ǿ������ͷ�ڵ�
		for (size_t i = 0; i < _table.size(); ++i)
		{
			if (_table[i])
				return iterator(_table[i], this);
		}
		//�ձ�
		return iterator(nullptr, this);
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}



	pair<iterator, bool> Insert(const V& data)
	{
		CheckCapacity();
		//ͨ��kov�º��������ȡdata��key
		//ͨ��hashFun�º���ת��key, ��������ֵ
		//����ֵ % _table.size() ����data�ڹ�ϣ���ж�Ӧ��λ��index
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
		//ͷ��
		cur->_next = _table[index];//�½ڵ��nextָ��ԭ����ͷ���
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
			//�½�һ�����ɱ�Ԫ�عҵ��±���
			newTable.resize(newC);
			KeyOfValue kov;
			//�����ɱ�
			for (size_t i = 0; i < _table.size(); i++)
			{
				pNode cur = _table[i];
				while (cur)
				{
					pNode next = cur->_next;
					//λ�����¼���
					size_t index = HashIndex(kov(cur->_data), newTable.size());
					//ͷ��
					cur->_next = newTable[index];
					newTable[index] = cur;

					cur = next;
				}
				_table[i] = nullptr;
			}
			//�ɱ��±���
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
					//ɾ�����������ͷ�ڵ㣬����ͷ�ڵ�
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
		//��keyת��Ϊ����
		HashFun hfun;
		return hfun(key) % sz;
	}

private:
	vector<pNode> _table;
	size_t _size = 0;
};



