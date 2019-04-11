#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
using namespace std;
//类型模板参数
//template <class T1, typename T2>
//T1 Add(const T1& a, const T2& b)
//{
//	return a + b;
//}
////非类型模板参数，作为常量使用
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
////const 修饰错位， const ->  a, b
//template <class T>
//bool isGreater(const T& a, const T& b)
//{
//	return a > b;
//}/*
// 1. 需要有一个已经存在的通用模板函数
// 2. 模板参数为空
// 3. 函数名后要显示写出要特化的类型
// 4. 特化的类型的格式要和通用的模板参数格式一致
// 5. 一般不去写函数模板的特化版本，函数模板的特化比较复杂，会报出一些奇怪的错误
//    建议对于函数模板处理不了或者报错的类型，去实现一个对应类型的普通函数*/
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
// 类模板特化
//      1. 全特化
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
////全特化
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
//// 半特化
//// 1. 部分特化
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
//// 半特化
//// 2. 对模板参数做进一步限制
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
//// 半特化
//// 2. 对模板参数做进一步限制
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
//	Data<int&, int&> d5;  // Data<T1&，T2&>
//	return 0;
//}

 //容器增容： 拷贝
 // memcpy: 一片内存拷贝，效率高 : O(1)
 // 赋值拷贝 =： 每个元素依次拷贝，效率较低  : O(n)
 // STL 拷贝分两路： 
 //        1. 内置类型： memcpy
 //        2. 自定义类型：赋值拷贝
 // POD : Plain Old Data --> 内置类型
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

// RTTI :  Run Time Type Information / Identification 进行时判断类型
// RTTI:   typeid   typeid(a).name
// bool isPODType(const char* tp): 缺陷：效率较低，时间复杂度O(n^2)
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
////类型萃取
//template <class T>
//struct TypeTraits
//{
//	typedef FalseType _isPodType;
//};
//
////模板特化
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

// STL 类型萃取设计方法
struct TrueType
{
};

struct FalseType
{
};

//类型萃取
template <class T>
struct TypeTraits
{
	typedef FalseType _isPodType;
};

//模板特化
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

//通过最后一个参数类型不同形成函数重载
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

// 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?
//B:C

//编译时递归
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