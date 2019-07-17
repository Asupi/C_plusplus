#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"MD5.h"

//测试文件
//int main(int argc, char* argv[])//命令行工具
//{
//	if (argc != 2)
//	{
//		std::cout << argv[0]<<"\tfilename" << std::endl;
//		return 0;
//	}
//	MD5 md5;
//	std::cout << md5.getFileMd5(argv[1]) << std::endl;
//	return 0;
//}


int main(int argc, char* argv[])//命令行工具
{
	if (argc != 3)
	{
		std::cout << "eg:" << std::endl;
		std::cout << argv[0] << "\t0\tfilename" << std::endl;
		std::cout << argv[0] << "\t1\tstring" << std::endl;
		return 0;
	}
	MD5 md5;
	char option = *argv[1];
	switch (option)
	{
	case'0':
	
		std::cout << md5.getFileMd5(argv[2]) << std::endl;
		break;
	case'1':
		std::cout << md5.getStringMd5(argv[2]) << std::endl;
		break;
	}
	
	return 0;
}

