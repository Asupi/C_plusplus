#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
using namespace std;

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//
//// Display --> Person
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	//cout << s._stuNum << endl;
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
//};
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " ���� :" << Person::_count << endl;
//	//Student::_count = 0;
//	cout << " ���� :" << Person::_count << endl;
//	cout << s1._count << endl;
//	cout << Student::_count << endl;
//	cout << "static address: " << endl;
//	cout << &Person::_count << endl;
//	cout << &s1._count << endl;
//	cout << &s2._count << endl;
//	cout << &s3._count << endl;
//	cout << &s4._count << endl;
//
//}
//
//int main()
//{
//	TestPerson();
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // ����
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//void Test()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	// ��������
//	Assistant a;
//	a.Student::_name = "peter";
//	a.Teacher::_name = "James";
//	//a._name = "ag";
//}
//
//
//int main()
//{
//	Test();
//	return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//class B : virtual public A
////class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
////class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}

//class Base1 {
//public:
//	int _b1;
//};
//class Base2 {
//public:
//	int _b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//	int _d;
//};
//int main()
//{
//	// A. p1 == p2 == p3
//	// B. p1 < p2 < p3
//	// C. p1 == p3 != p2
//	// D. p1 != p2 != p3
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	return 0;
//}

//��̬ǰ�᣺ �̳�
// 1.  ���ú��������ͱ�����ָ���������
// 2.  �����ú�������Ϊ�麯�������ұ���д��������������������ֵȫ����ͬ��
// 3.  ������д: Э�䣺 ����ֵ�����Ϳ����Ǽ̳й�ϵ

class A
{};
class B : public A
{

};

class Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
};
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
};

class S2 : public Student
{
public:
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
};
void Func(Person& p)
{
	p.BuyTicket();
}

void Func2(Student& p)
{
	p.BuyTicket();
}

int main()
{
	Person p;
	Student s;
	S2 s2;
	/*p.BuyTicket();
	s.BuyTicket();*/
	//��̬��ʵ��ָ��Ķ��󣬵��ö����Ӧ���͵Ĵ���
	//�Ƕ�̬������
	Func(p);
	Func(s);

	Func2(s2);

	return 0;
}