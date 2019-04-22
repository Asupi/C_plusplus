//deque接口应用实例

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

	
// 测试deque的构造函数
void TestDeque1()
{
		// 构造空的双端队列
		std::deque<int> d1;

	// 用10个值为5的元素构造双端队列
	std::deque<int> d2(10, 5);
	PrintDeque(d2);
	// 用数组的区间构造双端队列
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::deque<int> d3(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d3);
	// 用d3拷贝构造d4
	std::deque<int> d4(d3);
	PrintDeque(d4);
}

// 测试deque中的迭代器
void TestDeque2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::deque<int> d(array, array + sizeof(array) / sizeof(array[0]));

	// 利用正向迭代器打印deque中的元素
	for (auto it = d.cbegin(); it != d.cend(); ++it)
		cout << *it << " ";
	cout << endl;
	auto cit = d.cbegin();
	//*it = 100; 该条语句编译失败，it为const迭代器，其指向空间元素值不能修改

	// 利用反向迭代器逆向打印deque中的元素
	for (auto it = d.crbegin(); it != d.crend(); ++it)
		cout << *it << " ";
	cout << endl;
}
void TestDeque3()
{
	// 列表方式初始化，C++11语法
	deque<int> d1{ 3, 4, 5 };
	// 在deque的尾部插入5，头部插入1，并打印
	d1.push_back(6);
	d1.push_front(2);
	PrintDeque(d1);
	cout << d1.size() << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;
	// 在deque的尾部构造6，头部构造0
	// 注意：如果是内置类型元素，
	// emplace_back与push_back emplace_front与push_front的效率形同
	// 如果是自定义类型元素
	// emplace_back/emplace_front的效率更高，这两个操作直接在尾部或者头部构造元素
	// push_back/push_front的效率低，该操作时先将元素构造好，然后拷贝到尾部或头部
		d1.emplace_back(7);
	d1.emplace_front(1);
	PrintDeque(d1);
	// 在deque的begin位置插入元素0
	d1.insert(d1.begin(), 0);
	PrintDeque(d1);
	// 删除deque首部与尾部元素
	d1.pop_front();
	d1.pop_back();
	d1.erase(d1.begin());
	PrintDeque(d1);
	// 将deque中的元素清空
	d1.clear();
	cout << d1.size() << endl;
}
