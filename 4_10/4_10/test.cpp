#define _CRT_SECURE_NO_WARNINGS 
//vector的迭代器失效问题
//在vector中迭代器失效发生在insert和erase中。
//我们先看insert，在vector中插入元素，插入元素后当发现开辟的空间不够了，就会开辟更大的
//空间来进行拷贝数据，这个时候原来的start、finish、endofstorage都会发生变化，
//所以要插入位置已经变化，而传过来的位置还是原来的位置，就会出现插入越界。
//解决办法是：我们在插入前计算出相对与start的相对距离，那么当插入时候我们用计算的距离
//还原pos进行插入，然后返回插入后新元素的位置的迭代器

Iterator Insert(Iterator position, const T& value)
{

	assert(position < End() && position >= Begin());
	size_t off = position - start;
	if (finish == endofstorage)
	{
		Expand(Capacity() * 2);
	}

	position = off + start; // 注意跌掉器失效
	for (Iterator i = End(); i != position; --i)
	{
		*i = *(i - 1);
	}
	*position = value;
	++finish;
	return position;
}

//再看erase函数的迭代器失效问题。
//erase迭代器失效是在删除一个元素的时候，后面的元素要向前挪动，所以迭代器指向的位置
//就会被前面的覆盖，这时候++迭代器，就会跳过删除元素的后一个。
//解决办法：我们使用返回值，返回删除后原来的位置。用到的时候，当删除后接收返回的迭代器。

Iterator Erase(ConIterator position) //返回值防止迭代器失效
{
	assert(position < End() && position >= Begin());
	size_t i = position - Begin();
	for (; i < Size(); ++i)
	{
		*(start + i) = *(start + i + 1);
	}
	--finish;
	return (Iterator)position; // 注意迭代器失效问题
}

//list迭代器失效的问题

//在list中迭代器失效也是发生在ierase中。
//
//erase的迭代器失效是，当要删除的元素被删除后，迭代器++就会崩溃，因为迭代要++ 还是通过当前
//节点找到下一个个节点，当前节点已经被释放所以就没有了，这时候通过迭代器++ 就会失效。
//解决办法：在实现erase的时候会返回删除后的后面的元素的迭代器。

Iterator Erase(Iterator pos)
{
	assert(pos._pNode);
	Node* pre = pos._pNode->prev;
	Node* nex = pos._pNode->next;

	pre->next = nex;
	nex->prev = pre;

	delete pos._pNode;
	return nex;
}

list<int>::iterator it = l.begin();
while (it != l.end())
{
	if (*it % 2 == 0)
	{
		it = l.erase(it);  //因为标准库的erase返回值是迭代器,而返回的迭代器是被删除元素的下一个迭代器.这样也就不会有野指针的问题了.
	}
	else
	{
		++it;
	}
}