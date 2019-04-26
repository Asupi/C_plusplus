#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
using namespace std;
class Exception
{
protected:
	string _errmsg;
	int _id;
	//list<StackInfo> _traceStack;
	// ...
};
class SqlException : public Exception
{};
class CacheException : public Exception
{};
class HttpServerException : public Exception
{};
int main()
{
	try{
		// server.Start();
		// 抛出对象都是派生类对象
	}
	catch (const Exception& e) // 这里捕获父类对象就可以
	{
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	return 0;
}