
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
//用代码打印单继承虚表中的函数
class Base
{
public:
	virtual void func1(){ cout << "Base::func1<<endl"; }
	virtual void func2(){ cout << "Base::func2<<endl"; }
private:
	int a;
};
class Drive :public Base
{
public:
	virtual void func1(){ cout << "Drive::func1<<endl"; }
	virtual void func3(){ cout << "Drive::func3<<endl"; }
	virtual void func4(){ cout << "Drive::func4<<endl"; }
private:
	int b;
};

//int main()
//{
//	Base b;
//	Drive d;
//	return 0;
//}

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	//依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
		cout << endl;
	}
	cout << endl;
}
int main()
{
	Base b;
	Drive d;
	// 思路：取出b、d对象的头4bytes，就是虚表的指针，前面我们说了虚函数表本质是一个存虚函数指针的
	//指针数组，这个数组最后面放了一个nullptr
	// 1.先取b的地址，强转成一个int*的指针
	// 2.再解引用取值，就取到了b对象头4bytes的值，这个值就是指向虚表的指针
	// 3.再强转成VFPTR*，因为虚表就是一个存VFPTR类型(虚函数指针类型)的数组。
	// 4.虚表指针传递给PrintVTable进行打印虚表
	// 5.需要说明的是这个打印虚表的代码经常会崩溃，因为编译器有时对虚表的处理不干净，虚表最后面没有
	//放nullptr，导致越界，这是编译器的问题。我们只需要点目录栏的 - 生成 - 清理解决方案，再编译就好了。

	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);
	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);
	return 0;
}




//class Base1
//{
//public:
//	virtual void func1(){ cout << "Base1::func1" << endl; }
//	virtual void func2(){ cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//class Base2
//{
//public:
//	virtual void func1(){ cout << "Base2::func1" << endl; }
//	virtual void func2(){ cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//////子类的虚表和父类的个数相同，子类自己定义的虚函数放在第一个直接父类的虚表中
//class Drive :public Base1, public Base2
//{
//	virtual void func1(){ cout << "Drive::func1" << endl; }
//	virtual void func3(){ cout << "Drive::func3" << endl; }
//private:
//	int d1;
//};
//int main()
//{
//	Base1 b1;
//	Base2 b2;
//	Drive d;
//	return 0;
//}
////定义一个函数指针， 表示一类返回值为void,参数个数为0的函数
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	cout << " 虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//int main()
//{
//	Base1 b1;
//	Base2 b2;
//	Drive d;
//	Base2* pb2 = &d;
//	VFPTR* vTableb1 = (VFPTR*)(*(int*)&b1);
//	PrintVTable(vTableb1);
//	VFPTR* vTableb2 = (VFPTR*)(*(int*)&b2);
//	PrintVTable(vTableb2);
//	VFPTR* vTableb3 = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTableb3);
//	VFPTR* vTableb4 = (VFPTR*)(*(int*)pb2);
//	//VFPTR* vTableb4 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
//	PrintVTable(vTableb4);
//	return 0;
//}
