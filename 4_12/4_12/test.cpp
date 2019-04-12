#include <iostream>
#include <fstream>
#include "a.h"

using namespace std;

//int main()
//{
//	//int d;
//	////无论什么类型，都调用的同一个函数，需要指明变量的类型
//	//scanf("%d", &d);
//	//char c;
//	//scanf("%c", &c);
//	//// cin 类型： istream
//	//// istream  重载了>>运算符
//	//// 对于不同的内置类型， cin 调用的是不同的>>运算符重载函数， 不需要指定变量的类型
//	//cin >> d;
//	//cin >> c;
//	//cin.operator>>(d);
//
//	cout << "cout";
//	cerr << "cerr";
//	clog << "clog";
//	//cin.operator>>(c);
//	return 0;
//}

// fopen    fwrite    fread
struct Info
{
	char ip[20];
	int port;
};


class Config
{
public:
	Config(string filename)
		:_filename(filename)
	{}
	//字节流读写（按内存形式读写）
	void ReadBin(Info& info)
	{
		ifstream fin(_filename.c_str());
		//seekg: 设置文件指针的位置
		fin.seekg(0, ifstream::end);
		// tellg:文件指针相对于文件起始位置(0)的偏移量, 间接获取文件大小
		size_t byteNum = fin.tellg();
		cout << "byteNum : " << byteNum << endl;
		fin.read((char*)&info, sizeof(info));
		fin.close();
		cout << info.ip << endl;
		cout << info.port << endl;
	}

	void WriteBin(Info& info)
	{
		ofstream fout(_filename.c_str());
		/*fout.tellp();
		fout.seekp();*/

		fout.write((char*)&info, sizeof(info));
		fout.close();

	}
	//字符流读写
	void WriteText(Info& info)
	{
		ofstream fout(_filename.c_str());
		fout << info.ip << endl;
		fout << info.port << endl;

	}

	void ReadText(Info& info)
	{
		ifstream fin(_filename.c_str());
		fin >> info.ip; // endl  www.baidu.com\0汤汤汤汤汤汤汤80
		//fin.operator >>(info.ip);
		fin >> info.port;
		//fin.operator >>(info.port);
	}


private:
	string _filename;
};

int main()
{
	Info info;
	strcpy(info.ip, "www.baidu.com");
	info.port = 80;
	Config cfg("Config.txt");
	Info ReadInfo;
	cfg.WriteBin(info);
	//cfg.ReadBin(ReadInfo);
	cfg.ReadBin(ReadInfo);
	return 0;
}

