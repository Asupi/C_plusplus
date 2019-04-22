//deque�ӿ�Ӧ��ʵ��

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
using namespace std;
void PrintDeque(const std::deque<int>& d)
{
	for (const auto& e : d)
		cout << e << " ";
	cout << endl;
}

	
// ����deque�Ĺ��캯��
void TestDeque1()
{
		// ����յ�˫�˶���
		std::deque<int> d1;

	// ��10��ֵΪ5��Ԫ�ع���˫�˶���
	std::deque<int> d2(10, 5);
	PrintDeque(d2);
	// ����������乹��˫�˶���
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::deque<int> d3(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d3);
	// ��d3��������d4
	std::deque<int> d4(d3);
	PrintDeque(d4);
}

// ����deque�еĵ�����
void TestDeque2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::deque<int> d(array, array + sizeof(array) / sizeof(array[0]));

	// ���������������ӡdeque�е�Ԫ��
	for (auto it = d.cbegin(); it != d.cend(); ++it)
		cout << *it << " ";
	cout << endl;
	auto cit = d.cbegin();
	//*it = 100; ����������ʧ�ܣ�itΪconst����������ָ��ռ�Ԫ��ֵ�����޸�

	// ���÷�������������ӡdeque�е�Ԫ��
	for (auto it = d.crbegin(); it != d.crend(); ++it)
		cout << *it << " ";
	cout << endl;
}
void TestDeque3()
{
	// �б�ʽ��ʼ����C++11�﷨
	deque<int> d1{ 3, 4, 5 };
	// ��deque��β������5��ͷ������1������ӡ
	d1.push_back(6);
	d1.push_front(2);
	PrintDeque(d1);
	cout << d1.size() << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;
	// ��deque��β������6��ͷ������0
	// ע�⣺�������������Ԫ�أ�
	// emplace_back��push_back emplace_front��push_front��Ч����ͬ
	// ������Զ�������Ԫ��
	// emplace_back/emplace_front��Ч�ʸ��ߣ�����������ֱ����β������ͷ������Ԫ��
	// push_back/push_front��Ч�ʵͣ��ò���ʱ�Ƚ�Ԫ�ع���ã�Ȼ�󿽱���β����ͷ��
		d1.emplace_back(7);
	d1.emplace_front(1);
	PrintDeque(d1);
	// ��deque��beginλ�ò���Ԫ��0
	d1.insert(d1.begin(), 0);
	PrintDeque(d1);
	// ɾ��deque�ײ���β��Ԫ��
	d1.pop_front();
	d1.pop_back();
	d1.erase(d1.begin());
	PrintDeque(d1);
	// ��deque�е�Ԫ�����
	d1.clear();
	cout << d1.size() << endl;
}
