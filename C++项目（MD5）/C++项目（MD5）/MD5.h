
#pragma once
#define  N 64
#include<string>
class MD5
{
public:
	MD5();
	std::string getFileMd5(const char* filename);
	std::string getStringMd5(const std::string& str);
private:

	void init();
	void calculateMD5(size_t* chunk);//计算MD5的值，这里的数据块以四个字节为单位
	void calculateMD5Final();//处理最后一块数据，填充（最少填充8个字节）
	std::string changeHex(size_t num);

	size_t F(size_t x, size_t y, size_t z)
	{
		return (x & y) | ((~x) & z);
	}

	size_t G(size_t x, size_t y, size_t z)
	{
		return (x & z) | (y & (~z));
	}
	size_t H(size_t x, size_t y, size_t z)
	{
		return x ^ y ^ z;
	}
	size_t I(size_t x, size_t y, size_t z)
	{
		return y ^ (x | (~z));
	}
	//循环左移
	size_t shiftLeftRotate(size_t num, size_t n)
	{
		return (num << n) | (num >> (32 - n));
	}
private:
	size_t _a;
	size_t _b;
	size_t _c;
	size_t _d;

	size_t _k[N];
	size_t _sft[N];//循环左移多少位
	
	const size_t _chunkByte;//每个要运算数据块的大小
    unsigned char _chunk[N];//定义一个块，去存放数据块
	size_t _lastByte;//最后一个数据块
	unsigned long long _totalByte;//最后一个数据块的最后64位，记录原文的长度（不断变化）
};