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
		// �׳����������������
	}
	catch (const Exception& e) // ���ﲶ�������Ϳ���
	{
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	return 0;
}