#define _CRT_SECURE_NO_WARNINGS 
# pragma once
#include "hash.h"

struct Str2Int
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& e : str)
		{
			hash = hash * 131 + e;
		}
		return hash;
	}
};

template <class K>
struct HFun
{
	const K& operator()(const K& a)
	{

		return a;
	}
};

template <>
struct HFun<string>
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& e : str)
		{
			hash = hash * 131 + e;
		}
		return hash;
	}
};

template <class K, class V, class HashFun = HFun<K>>
class UnorderedMap
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};
public:
	typedef typename HashTable<K, pair<K, V>, MapKeyOfValue, HashFun>::iterator iterator;
	pair<iterator, bool> Insert(const pair<K, V>& data)
	{
		return _ht.Insert(data);
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
		return ret.first->second;
	}

	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}

	iterator Find(const K& key)
	{
		return _ht.Find(key);
	}

	bool Erase(const K& key)
	{
		return _ht.Erase(key);
	}

private:
	HashTable<K, pair<K, V>, MapKeyOfValue, HashFun> _ht;
};

template <class K, class HashFun = HFun<K>>
class UnorderedSet
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& data)
		{
			return data;
		}
	};
public:
	typedef typename HashTable<K, K, SetKeyOfValue, HashFun>::iterator iterator;
	pair<iterator, bool> Insert(const K& data)
	{
		return _ht.Insert(data);
	}

	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}

private:
	HashTable<K, K, SetKeyOfValue, HashFun> _ht;
};