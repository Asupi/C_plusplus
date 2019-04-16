#include <iostream>
#include <string>
using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	s.Print();
//	Teacher t;
//	t.Print();
//	return 0;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
////protected:
//public:
//	string _name; // 姓名
//private:
//	int _age; // 年龄
//protected:
//	int _id;
//};
//
////class Student : protected Person
////class Student : private Person
//class Student : public Person
//{
//public:
//	void fun1()
//	{
//		_id = 123;
//		//_name = "hllo";
//		//_age = 18;
//	}
//public:
//	int _stunum; // 学号
//
////private:
//	//string _name; // 姓名
////不可见:
////int _age; // 年龄
////protected:
////	int _id;
//};

// private: 在类外和子类都无法访问
// protected: 在类外无法访问，但是在子类内部可以访问
// public继承： 不改变基类成员在子类中的访问权限
// protected继承：基类成员在子类中的最低访问权限为protected
// private继承：基类成员在子类中的最低访问权限为private

///* Person:
//public:
//string _name; // 姓名
//private:
//int _age; // 年龄
//protected:
//int _id;
//*/
//
//_name	  _age		 _id
//A	Public		B	Protected	C  Private  D 不可见
//Student : 
//Public继承:  ACB   ADB   ABD  ABD			ADB
//Protected继承: ABC  BDB   BBD   BBD			BDB
//Private继承: CCC  CDC   CCD   CCD			CDC



//int main()
//{
//	Student s;
//	//s._name = "hello";
//	//s._id = 234;
//	s._name = "hello";
//	Person p;
//	p._name = "123";
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	float b = 1.5;
//	//隐式类型转换：类型相似的变量可以进行相互赋值，通过隐式类型转换
//	a = b;
//	int* pa = &a;
//	int c = 10;
//	//强制类型转换
//	pa = (int*)c;
//
//	Person p;
//	Student s;
//	//切片： 子类对象可以赋给父类对象
//	p = s;
//	//父类对象不能赋值给子类对象
//	//s = p;
//	//子类指针可以赋给父类指针
//	Person* ptr = &s;
//	//子类可以赋给父类引用： 引用的底层就是指针
//	Person& ref = s;
//	//父类的指针不能赋给子类指针：可能会发生访问越界
//	//Student* ptr2 = &p;
//	
//	Student* ptr2 = (Student*)ptr;
//}

