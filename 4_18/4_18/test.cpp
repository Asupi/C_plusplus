#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
using namespace std;
//class Person
//{
//	public:
//	string _name = "小李子"; // 姓名
//	int _id = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_id << endl;
//		cout << " 学号:" << _StudentNum << endl;
//	}
//	public:
//	int _StudentNum = 999; // 学号
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	cout << p._id << endl;
//	cout << s.Student::_StudentNum << endl;
//	cout << s.Person::_id << endl;
//
//	return 0;
//}

//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "fun(int i)->" << i << endl;
//	}
//};
//void Test()
//{
//	B b;
//	b.fun(10); 
//	b.A::fun();
//};

// fun    fun(int i)
//A 重载    // 函数在同一个作用域中，函数名形同， 参数不同
//B 重定义  // 重定义/隐藏：子类函数和父类函数名相同
//C 覆盖    // 覆盖/重写
//D 重写
//E 隐藏


//class Person
//{
//public:
//	Person(const char* name = "hello")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)  // Person(Person* this, const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person() // ~destructor
//	{
//		cout << "~Person()" << endl;
//	}
//	
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	//父类的成员变量不能直接在子类的构造和拷贝构造中直接初始化，
//	//必须调用父类的构造和拷贝构造进行初始化
//
//	//子类构造函数先调用父类构造函数，在执行子类构造函数
//	Student(const char* name = "helo")
//		:_id(10)
//		,Person(name)
//	{
//		cout << "Student(const char* name)" << endl;
//	}
//	// 如果子类不显示调用父类的拷贝构造，则调用父类的默认构造函数
//	// 如果子类显示调用父类的拷贝构造，就不会再去调用父类的默认构造函数
//	Student(const Student& s)  // (Student* this, const Student& s)
//		:Person(s)
//		,_id(10)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	//父类的成员变量可以在子类的赋值运算符重载函数中直接赋值
//	//如果是编译器默认生成的子类赋值运算符重载函数，会调用父类的赋值运算符重载函数进行赋值
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			//_name = s._name;
//			//建议直接显示调用父类的赋值运算符重载函数，代码复用
//			Person::operator=(s);
//			_id = 10;
//		}
//		return *this;
//	}
//	//析构函数：不允许显式调用父类的析构函数
//	~Student()  // ~destructor  同名隐藏，编译器底层对析构函数的名字做了修改，为了使用多态
//	{
//		cout << "~Student()" << endl;
//		//Person::~Person();
//	}
//private:
//	int _id;
//};
//
//
//
//int main()
//{
//	Student s;
//	Student cpy(s);
//	Student s2 = s;  //拷贝构造
//	//s2 = s;  //赋值运算符重载
//	//构造和析构的调用顺序：
//	//构造顺序： 基类构造-->派生类构造
//	//析构顺序： 派生类析构-->基类析构
//	return 0;
//}

//class NonInherit
//{
//public:
//	static NonInherit GetInstance()
//	{
//		return NonInherit();
//	}
//private:
//	NonInherit()
//	{}
//};
//
//class A : public NonInherit
//{};
//
//int main()
//{
//	NonInherit noi = NonInherit::GetInstance();
//	//A a;
//	return 0;
//}
