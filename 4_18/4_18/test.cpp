#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
using namespace std;
//class Person
//{
//	public:
//	string _name = "С����"; // ����
//	int _id = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_id << endl;
//		cout << " ѧ��:" << _StudentNum << endl;
//	}
//	public:
//	int _StudentNum = 999; // ѧ��
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
//A ����    // ������ͬһ���������У���������ͬ�� ������ͬ
//B �ض���  // �ض���/���أ����ຯ���͸��ຯ������ͬ
//C ����    // ����/��д
//D ��д
//E ����


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
//	string _name; // ����
//};
//
//class Student : public Person
//{
//public:
//	//����ĳ�Ա��������ֱ��������Ĺ���Ϳ���������ֱ�ӳ�ʼ����
//	//������ø���Ĺ���Ϳ���������г�ʼ��
//
//	//���๹�캯���ȵ��ø��๹�캯������ִ�����๹�캯��
//	Student(const char* name = "helo")
//		:_id(10)
//		,Person(name)
//	{
//		cout << "Student(const char* name)" << endl;
//	}
//	// ������಻��ʾ���ø���Ŀ������죬����ø����Ĭ�Ϲ��캯��
//	// ���������ʾ���ø���Ŀ������죬�Ͳ�����ȥ���ø����Ĭ�Ϲ��캯��
//	Student(const Student& s)  // (Student* this, const Student& s)
//		:Person(s)
//		,_id(10)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	//����ĳ�Ա��������������ĸ�ֵ��������غ�����ֱ�Ӹ�ֵ
//	//����Ǳ�����Ĭ�����ɵ����ำֵ��������غ���������ø���ĸ�ֵ��������غ������и�ֵ
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			//_name = s._name;
//			//����ֱ����ʾ���ø���ĸ�ֵ��������غ��������븴��
//			Person::operator=(s);
//			_id = 10;
//		}
//		return *this;
//	}
//	//������������������ʽ���ø������������
//	~Student()  // ~destructor  ͬ�����أ��������ײ���������������������޸ģ�Ϊ��ʹ�ö�̬
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
//	Student s2 = s;  //��������
//	//s2 = s;  //��ֵ���������
//	//����������ĵ���˳��
//	//����˳�� ���๹��-->�����๹��
//	//����˳�� ����������-->��������
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
