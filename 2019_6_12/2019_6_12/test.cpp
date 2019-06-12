#define _CRT_SECURE_NO_WARNINGS 
#include"hash.h"
#include"UnorderedMapSet.h"
#include<iostream>
//void testHash()
//{
//	HashTable<int, int> ht;
//	ht.Insert(make_pair(1, 1));
//	ht.Insert(make_pair(2, 2));
//	ht.Insert(make_pair(3, 3));
//	ht.Insert(make_pair(4, 4));
//	ht.Insert(make_pair(5, 5));
//	ht.Insert(make_pair(6, 6));
//
//	auto ret = ht.Find(6);
//	ret = ht.Find(10);
//}
void testUnordered()
{
	UnorderedMap<int, int>uMap;
	UnorderedSet<int>uSet;
	uMap.Insert(make_pair(4, 0));
	uMap.Insert(make_pair(8, 1));
	uMap.Insert(make_pair(16, 2));

	uSet.Insert(0);
	uSet.Insert(1);
	uSet.Insert(2);




}
int main()
{
	//testHash();
	testUnordered();
	return 0;
}
