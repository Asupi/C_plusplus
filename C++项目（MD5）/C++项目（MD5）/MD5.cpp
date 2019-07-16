#define _CRT_SECURE_NO_WARNINGS 
#include"MD5.h"
#include<string>
#include<fstream>
#include<math.h>

void MD5::calculateMD5(size_t* chunk)
{
	size_t a = _a;
	size_t b = _b;
	size_t c = _c;
	size_t d = _d;

	//chunk[g]  f:哈希函数的返回值
	size_t f, g;
	//64次变换，4轮操作，每一轮操作：16次自操作
	for (size_t i = 0; i < 64; i++)
	{
		if (i >= 0 && i < 16)
		{

		}
		if (i >= 16 && i < 32)
		{

		}
		if (i >= 32 && i < 48)
		{

		}
		if (i >= 48 && i < 64)
		{

		}
	}
}
std::string MD5::getFileMd5(const char* filename)
{
	std::ifstream fin(filename, std::ifstream::binary);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.read((char*)_chunk, _chunkByte);
			if (_chunkByte != fin.gcount())
				break;

			_totalByte += _chunkByte;
		}
	}
}

std::string MD5:: getStringMd5(const std::string& str)
{
	if (str.empty())
		return "";
	else
	{
		unsigned char* pstr = (unsigned char*)str.c_str();
		size_t numChunk = str.size() / _chunkByte;
		
	}
}