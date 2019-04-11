#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
using namespace std;
//����ģ�����
//template <class T1, typename T2>
//T1 Add(const T1& a, const T2& b)
//{
//	return a + b;
//}
////������ģ���������Ϊ����ʹ��
////
//template <class T,  size_t N>
//class Array
//{
//private:
//	T a[N];
//};
//
//int main()
//{
//	Array<int, 10> arr1;
//	Array<double, 100> arr2;
//	return 0;
//}

//template <class T>
//bool isEqual(T& a, T& b)
//{
//	return a != b;
//}
//
////const ���δ�λ�� const ->  a, b
//template <class T>
//bool isGreater(const T& a, const T& b)
//{
//	return a > b;
//}/*
// 1. ��Ҫ��һ���Ѿ����ڵ�ͨ��ģ�庯��
// 2. ģ�����Ϊ��
// 3. ��������Ҫ��ʾд��Ҫ�ػ�������
// 4. �ػ������͵ĸ�ʽҪ��ͨ�õ�ģ�������ʽһ��
// 5. һ�㲻ȥд����ģ����ػ��汾������ģ����ػ��Ƚϸ��ӣ��ᱨ��һЩ��ֵĴ���
//    ������ں���ģ�崦���˻��߱�������ͣ�ȥʵ��һ����Ӧ���͵���ͨ����*/
//template <>
//bool isGreater<char*&>(char*& const a, char*& const b)
//{
//	if (strcmp(a, b) > 0)
//		return true;
//	return false;
//}
//
//
//bool isGreater(char* a, char* b)
//{
//	if (strcmp(a, b) > 0)
//		return true;
//	return false;
//}
//int main()
//{
//	int a = 10, b = 20;
//	
//	char* str2 = "world";
//	char* str1 = "hello";
//	
//	cout << isEqual(a, b) << endl;
//	cout << isEqual(str1, str2) << endl;  // bool isEqual(char*& a, char*& b)
//	cout << isGreater(a, b) << endl;
//	cout << isGreater(str1, str2) << endl;
//	return 0;
//}
//
// ��ģ���ػ�
//      1. ȫ�ػ�
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
////ȫ�ػ�
//template<>
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//	int _d1;
//	char _d2;
//};
//
//// ���ػ�
//// 1. �����ػ�
//template<class T>
//class Data<T, char>
//{
//public:
//	Data() { cout << "Data<T, char>" << endl; }
//private:
//	int _d1;
//	char _d2;
//};
//
//// ���ػ�
//// 2. ��ģ���������һ������
//template<class T1, class T2>
//class Data<T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//	T1* _d1;
//	T2* _d2;
//};
//
//// ���ػ�
//// 2. ��ģ���������һ������
//template<class T1, class T2>
//class Data<T1&, T2&>
//{
//public:
//	Data() { cout << "Data<T1&, T2&>" << endl; }
//private:
//	T1* _d1;
//	T2* _d2;
//};
//
//
//
//
//int main()
//{
//	Data<int, int> d1;  // Data<T1, T2>
//	Data<int, char> d2; // Data<int, char>
//	Data<char, char> d3;// Data<T, char>
//	Data<int*, int*> d4; //Data<T1*, T2*>
//	Data<int&, int&> d5;  // Data<T1&��T2&>
//	return 0;
//}

 //�������ݣ� ����
 // memcpy: һƬ�ڴ濽����Ч�ʸ� : O(1)
 // ��ֵ���� =�� ÿ��Ԫ�����ο�����Ч�ʽϵ�  : O(n)
 // STL ��������·�� 
 //        1. �������ͣ� memcpy
 //        2. �Զ������ͣ���ֵ����
 // POD : Plain Old Data --> ��������
template <class T>
void Copy(T* dst, const T* src, size_t sz, bool isPODtype)
{
	if (isPODtype)
	{
		memcpy(dst, src, sizeof(T)* sz);
	}
	else
	{
		for (int i = 0; i < sz; i++)
		{
			dst[i] = src[i];
		}
	}
}

// RTTI :  Run Time Type Information / Identification ����ʱ�ж�����
// RTTI:   typeid   typeid(a).name
// bool isPODType(const char* tp): ȱ�ݣ�Ч�ʽϵͣ�ʱ�临�Ӷ�O(n^2)
bool isPODType(const char* tp)
{
	static char* typyArr[] = { "int", "double", "float", "char", "..." };
	for (int i = 0; i < sizeof(typyArr) / sizeof(typyArr[0]); i++)
	{
		if (strcmp(tp, typyArr[i]))
			return true;
	}
	return false;
}

//template <class T>
//void Copy(T* dst, const T* src, size_t sz)
//{
//	if (isPODtype(typeid(T).name()))
//	{
//		memcpy(dst, src, sizeof(T)* sz);
//	}
//	else
//	{
//		for (int i = 0; i < sz; i++)
//		{
//			dst[i] = src[i];
//		}
//	}
//}

//struct TrueType
//{
//	static bool Get()
//	{
//		return true;
//	}
//};
//
//struct FalseType
//{
//	static bool Get()
//	{
//		return false;
//	}
//};
//
////������ȡ
//template <class T>
//struct TypeTraits
//{
//	typedef FalseType _isPodType;
//};
//
////ģ���ػ�
//template <>
//struct TypeTraits<char>
//{
//	typedef TrueType _isPodType;
//};
//
//template <>
//struct TypeTraits<int>
//{
//	typedef TrueType _isPodType;
//};
//
//template <>
//struct TypeTraits<double>
//{
//	typedef TrueType _isPodType;
//};
//
//template <>
//struct TypeTraits<float>
//{
//	typedef TrueType _isPodType;
//};
//
////.........
//
//
//
//template <class T>
//void Copy(T* dst, const T* src, size_t sz)
//{
//	if (TypeTraits<T>::_isPodType::Get())
//	{
//		cout << typeid(T).name() << ": memcpy()" << endl;
//		memcpy(dst, src, sizeof(T)* sz);
//	}
//	else
//	{
//		cout << typeid(T).name() << ": operator=()" << endl;
//		for (int i = 0; i < sz; i++)
//		{
//			dst[i] = src[i];
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	int arr2[7];
//	Copy(arr2, arr, 7);
//	string str1[] = { "123", "345", "hello", "world" };
//	string str2[4];
//	Copy(str2, str1, 4);
//	return 0;
//}

// STL ������ȡ��Ʒ���
struct TrueType
{
};

struct FalseType
{
};

//������ȡ
template <class T>
struct TypeTraits
{
	typedef FalseType _isPodType;
};

//ģ���ػ�
template <>
struct TypeTraits<char>
{
	typedef TrueType _isPodType;
};

template <>
struct TypeTraits<int>
{
	typedef TrueType _isPodType;
};

template <>
struct TypeTraits<double>
{
	typedef TrueType _isPodType;
};

template <>
struct TypeTraits<float>
{
	typedef TrueType _isPodType;
};

//.........

//ͨ�����һ���������Ͳ�ͬ�γɺ�������
template <class T>
void Copy(T* dst, const T* src, size_t sz, TrueType)
{
	cout << typeid(T).name() << ": memcpy()" << endl;
	memcpy(dst, src, sizeof(T)* sz);
}


template <class T>
void Copy(T* dst, const T* src, size_t sz, FalseType)
{
	cout << typeid(T).name() << ": operator=()" << endl;
	for (int i = 0; i < sz; i++)
	{
		dst[i] = src[i];
	}
}

template <class T>
void Copy(T* dst, const T* src, size_t sz)
{
	Copy(dst, src, sz, TypeTraits<T>::_isPodType());
}



//void fun(int a, int)
//{}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	int arr2[7];
//	Copy(arr2, arr, 7);
//	string str1[] = { "123", "345", "hello", "world" };
//	string str2[4];
//	Copy(str2, str1, 4);
//	return 0;
//}

// ��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?
//B:C

//����ʱ�ݹ�
template <size_t N>
struct Sum
{
	enum{ Ret = N + Sum<N - 1>::Ret };
};
// Sum<10>  Ret  10 + Sum<9> --> 10 + 9 + Sum<8> --> 10 + 9 + 8 +....
template <>
struct Sum<1>
{
	enum{ Ret = 1 };
};
int main()
{
	cout << Sum<500>::Ret << endl;
	return 0;
}