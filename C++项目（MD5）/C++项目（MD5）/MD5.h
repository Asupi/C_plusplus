
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
	void calculateMD5(size_t* chunk);//����MD5��ֵ����������ݿ����ĸ��ֽ�Ϊ��λ
	void calculateMD5Final();//�������һ�����ݣ���䣨�������8���ֽڣ�
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
	//ѭ������
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
	size_t _sft[N];//ѭ�����ƶ���λ
	
	const size_t _chunkByte;//ÿ��Ҫ�������ݿ�Ĵ�С
    unsigned char _chunk[N];//����һ���飬ȥ������ݿ�
	size_t _lastByte;//���һ�����ݿ�
	unsigned long long _totalByte;//���һ�����ݿ�����64λ����¼ԭ�ĵĳ��ȣ����ϱ仯��
};