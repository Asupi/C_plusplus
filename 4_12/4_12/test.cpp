#include <iostream>
#include <fstream>
#include "a.h"

using namespace std;

//int main()
//{
//	//int d;
//	////����ʲô���ͣ������õ�ͬһ����������Ҫָ������������
//	//scanf("%d", &d);
//	//char c;
//	//scanf("%c", &c);
//	//// cin ���ͣ� istream
//	//// istream  ������>>�����
//	//// ���ڲ�ͬ���������ͣ� cin ���õ��ǲ�ͬ��>>��������غ����� ����Ҫָ������������
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
	//�ֽ�����д�����ڴ���ʽ��д��
	void ReadBin(Info& info)
	{
		ifstream fin(_filename.c_str());
		//seekg: �����ļ�ָ���λ��
		fin.seekg(0, ifstream::end);
		// tellg:�ļ�ָ��������ļ���ʼλ��(0)��ƫ����, ��ӻ�ȡ�ļ���С
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
	//�ַ�����д
	void WriteText(Info& info)
	{
		ofstream fout(_filename.c_str());
		fout << info.ip << endl;
		fout << info.port << endl;

	}

	void ReadText(Info& info)
	{
		ifstream fin(_filename.c_str());
		fin >> info.ip; // endl  www.baidu.com\0��������������80
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

