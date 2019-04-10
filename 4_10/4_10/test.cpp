#define _CRT_SECURE_NO_WARNINGS 
//vector�ĵ�����ʧЧ����
//��vector�е�����ʧЧ������insert��erase�С�
//�����ȿ�insert����vector�в���Ԫ�أ�����Ԫ�غ󵱷��ֿ��ٵĿռ䲻���ˣ��ͻῪ�ٸ����
//�ռ������п������ݣ����ʱ��ԭ����start��finish��endofstorage���ᷢ���仯��
//����Ҫ����λ���Ѿ��仯������������λ�û���ԭ����λ�ã��ͻ���ֲ���Խ�硣
//����취�ǣ������ڲ���ǰ����������start����Ծ��룬��ô������ʱ�������ü���ľ���
//��ԭpos���в��룬Ȼ�󷵻ز������Ԫ�ص�λ�õĵ�����

Iterator Insert(Iterator position, const T& value)
{

	assert(position < End() && position >= Begin());
	size_t off = position - start;
	if (finish == endofstorage)
	{
		Expand(Capacity() * 2);
	}

	position = off + start; // ע�������ʧЧ
	for (Iterator i = End(); i != position; --i)
	{
		*i = *(i - 1);
	}
	*position = value;
	++finish;
	return position;
}

//�ٿ�erase�����ĵ�����ʧЧ���⡣
//erase������ʧЧ����ɾ��һ��Ԫ�ص�ʱ�򣬺����Ԫ��Ҫ��ǰŲ�������Ե�����ָ���λ��
//�ͻᱻǰ��ĸ��ǣ���ʱ��++���������ͻ�����ɾ��Ԫ�صĺ�һ����
//����취������ʹ�÷���ֵ������ɾ����ԭ����λ�á��õ���ʱ�򣬵�ɾ������շ��صĵ�������

Iterator Erase(ConIterator position) //����ֵ��ֹ������ʧЧ
{
	assert(position < End() && position >= Begin());
	size_t i = position - Begin();
	for (; i < Size(); ++i)
	{
		*(start + i) = *(start + i + 1);
	}
	--finish;
	return (Iterator)position; // ע�������ʧЧ����
}

//list������ʧЧ������

//��list�е�����ʧЧҲ�Ƿ�����ierase�С�
//
//erase�ĵ�����ʧЧ�ǣ���Ҫɾ����Ԫ�ر�ɾ���󣬵�����++�ͻ��������Ϊ����Ҫ++ ����ͨ����ǰ
//�ڵ��ҵ���һ�����ڵ㣬��ǰ�ڵ��Ѿ����ͷ����Ծ�û���ˣ���ʱ��ͨ��������++ �ͻ�ʧЧ��
//����취����ʵ��erase��ʱ��᷵��ɾ����ĺ����Ԫ�صĵ�������

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
		it = l.erase(it);  //��Ϊ��׼���erase����ֵ�ǵ�����,�����صĵ������Ǳ�ɾ��Ԫ�ص���һ��������.����Ҳ�Ͳ�����Ұָ���������.
	}
	else
	{
		++it;
	}
}