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
//	string _name = "peter"; // ����
//	int _age = 18; // ����
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
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
//	string _name; // ����
//private:
//	int _age; // ����
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
//	int _stunum; // ѧ��
//
////private:
//	//string _name; // ����
////���ɼ�:
////int _age; // ����
////protected:
////	int _id;
//};

// private: ����������඼�޷�����
// protected: �������޷����ʣ������������ڲ����Է���
// public�̳У� ���ı�����Ա�������еķ���Ȩ��
// protected�̳У������Ա�������е���ͷ���Ȩ��Ϊprotected
// private�̳У������Ա�������е���ͷ���Ȩ��Ϊprivate

///* Person:
//public:
//string _name; // ����
//private:
//int _age; // ����
//protected:
//int _id;
//*/
//
//_name	  _age		 _id
//A	Public		B	Protected	C  Private  D ���ɼ�
//Student : 
//Public�̳�:  ACB   ADB   ABD  ABD			ADB
//Protected�̳�: ABC  BDB   BBD   BBD			BDB
//Private�̳�: CCC  CDC   CCD   CCD			CDC



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
//	//��ʽ����ת�����������Ƶı������Խ����໥��ֵ��ͨ����ʽ����ת��
//	a = b;
//	int* pa = &a;
//	int c = 10;
//	//ǿ������ת��
//	pa = (int*)c;
//
//	Person p;
//	Student s;
//	//��Ƭ�� ���������Ը����������
//	p = s;
//	//��������ܸ�ֵ���������
//	//s = p;
//	//����ָ����Ը�������ָ��
//	Person* ptr = &s;
//	//������Ը����������ã� ���õĵײ����ָ��
//	Person& ref = s;
//	//�����ָ�벻�ܸ�������ָ�룺���ܻᷢ������Խ��
//	//Student* ptr2 = &p;
//	
//	Student* ptr2 = (Student*)ptr;
//}

