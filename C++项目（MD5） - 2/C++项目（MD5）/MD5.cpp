#define _CRT_SECURE_NO_WARNINGS 
#include"MD5.h"
#include<cstring>
#include<fstream>
#include<math.h>



//初始化列表
MD5::MD5()
:_chunkByte(N)
{
	init();
	memset(_chunk, 0, _chunkByte);
	_totalByte = _lastByte = 0;
}
void MD5::init()
{
	// 初始化A,B,C,D
	_a = 0x67452301;
	_b = 0xefcdab89;
	_c = 0x98badcfe;
	_d = 0x10325476;

	size_t s[] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
		12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
		15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };
	memcpy(_sft, s, sizeof(s));

	//k[i]  2^32*abs(sin(i))
	for (int i = 0; i < 64; i++) 
	{
		_k[i] = (size_t)(abs(sin(i + 1)) * pow(2, 32));
	}
}



//计算MD5
void MD5::calculateMD5(size_t* chunk)//计算MD5的值，这里的数据块以四个字节为单位
//类外定义，需要加类的作用域
{
	size_t a = _a;
	size_t b = _b;
	size_t c = _c;
	size_t d = _d;

	//chunk[g]:当前循环要用的那一块数据  f:哈希函数的返回值
	size_t f, g;

	/*
	F(x, y, z) = (x & y) | ((~x) & z)
	G(x, y, z) = (x & z) | (y & (~z))
	H(x, y, z) = x ^ y ^ z
	I(x, y, z) = y ^ (x | (~z))
	*/

	/*
	if (0 <= i < 16) g = i;
	if (16 <= i < 32) g = (5 * i + 1) % 16;
	if (32 <= i < 48) g = (3 * i + 5) % 16;
	if(48 <= i < 63) g = (7 * i) % 16;
	*/
	

	//64次变换，4轮操作，每一轮操作：16次自操作
	for (size_t i = 0; i < 64; i++)
	{
		if (i >= 0 && i < 16)
		{
			f = F(b, c, d);
			g = i;
		}
		else if (i >= 16 && i < 32)
		{
			f = G(b, c, d);
			g = (5 * i + 1) % 16;
		}
		else if (i >= 32 && i < 48)
		{
			f = H(b, c, d);
			g = (3 * i + 5) % 16;
		}
		else 
		{
			f = I(b, c, d);
			g = (7 * i) % 16;
		}
		//64次操作，每一次计算完哈希函数的返回值之后，更新 a,b,c,d的值
		size_t dtemp = d;//保存d未更新之前的值
		d = c;
		c = b;	
		//a + f + _k[i] + chunk[g]：循环左移的数据块
		b = b + shiftLeftRotate(a + f + _k[i] + chunk[g], _sft[i]);
		a = dtemp;

	}

	//当一个512位的数据块处理完后，更新MD buffer的值
	_a += a;
	_b += b;
	_c += c;
	_d += d;
}



//处理最后一个数据块（计算MD5）
void MD5:: calculateMD5Final()
{
	//lastByte（最后一块数据的大小）<64byte
	unsigned char* p=_chunk + _lastByte;
	//至少填充的这一个字节
	*p++ = 0x80;

	//remainFillbyte 填充完一个字节后剩余要填充的数据块的大小（字节为单位）
	size_t remainFillByte = _chunkByte - _lastByte - 1;

	//remainFillByte < 8,意味着这一块数据剩余的数据不够记录原文的长度，
	//需要将这块数据剩余的部分全部填充成0，然后再用同样的方法去处理它，
	//最后再构造出一块新的512位的数据块，前
	//448位数据填充为0，剩余64位记录原文的长度
	if (remainFillByte < 8)
	{
		memset(p, 0, remainFillByte);//将这块数据剩余的部分全部填充成0，
		calculateMD5((size_t*)_chunk);//用同样的方法去处理它
		memset(_chunk, 0, _chunkByte);//构造新的数据块，全部填充为0
	}
	else //大于8，长度足够记录原文的大小
	{
		memset(p, 0, remainFillByte);
	}
	//将剩下的部分全部置成0后，将其最后64位做以统一处理，专门记录原文的长度

	//定义的_chunk是char类型，每次偏移1个字节，但是char类型最大为256，所以需要强转
	//为long long类型，每次偏移8个字节，从索引为7的位置是最后8个字节
	((unsigned long long*)_chunk)[7] = _totalByte * 8;
	calculateMD5((size_t*)_chunk);//处理这个数据块
}


//计算完MD5后，将计算得到的值以整型转换成16进制的字符串,用于a,b,c,d的拼接
//0x23456789--->89 67 45 23 
std::string MD5::changeHex(size_t num)
{
	static std::string strMap = "0123456789abcdef";
	std::string ret;
	std::string byteStr;	
	//字节内部是头插，字节之间尾插
	for (int i = 0; i < 4; i++)
	{
		//处理下一个字节之前进行清空
		byteStr = "";
		//每次只拿一个字节的数据，右移8位，然后再与上8位的全1，共右移四次
		size_t b = (num >> (i * 8)) & 0xff;
		//拿两次，类似于拿十进制中的个位和十位
		for (int j = 0; j < 2; ++j)
		{
			//strMap[b % 16]：字符串的方括号操作，拿到一个字符后，下一个头插（字节内部）
			byteStr.insert(0, 1, strMap[b % 16]);
			b /= 16;
		}
		//字节之间的尾插
		ret += byteStr;
	}
	return ret;
}




//处理文件
std::string MD5::getFileMd5(const char* filename)
{
	std::ifstream fin(filename, std::ifstream::binary);//输入文件流，同一按照二进制处理
	if (fin.is_open())
	{
		//只要没走到文件的末尾一直走（按照64字节去读）
		while (!fin.eof())
		{
			fin.read((char*)_chunk, _chunkByte);//按照二进制方式来读，将读到的内容
			                                   //放到要处理数据块里面，每次读64个字节

		   //判断当前数据块读了多少个字节，如果不够64字节，则说明是最后一块，单独处理
			if (_chunkByte != fin.gcount())
				break;

			//够64个字节说明不是最后一个数据块
			//将当前读到的数据累加，每次加一个数据块，_totalByte记录原文长度(不断变化的)
			_totalByte += _chunkByte;
			calculateMD5((size_t*)_chunk);//计算当前数据块的MD5
		}

		//最后一块读到的数据的的大小
		_lastByte = fin.gcount();
		_totalByte += _lastByte;//此时原文的全部长度记录完毕
		calculateMD5Final();//处理最后一块数据
	}
	//拼接 a，b,c,d
	return changeHex(_a) + changeHex(_b) + changeHex(_c) + changeHex(_d);
}



//处理字符串
std::string MD5::getStringMd5(const std::string& str)
{
	if (str.empty())
		return "";
	else
	{
		//将字符串转换成char类型数组
		unsigned char* pstr = (unsigned char*)str.c_str();
		//字符串的大小除以每一块的数据大小，算出一共多少块数据
		size_t numChunk = str.size() / _chunkByte;
		//循环处理每一块数据
		for (size_t i = 0; i < numChunk; ++i)
		{
			_totalByte += _chunkByte;
			//每次偏移到下一块数据的起始位置，然后开始处理，每次处理64个字节
			calculateMD5((size_t*)(pstr + i*_chunkByte));
		}
		//最后一块数据剩余的字节数
		_lastByte = str.size() % _chunkByte;
		//新开一个数据块，将剩余的数据从pstr + _totalByte位置开始拷贝到_chunk数据块
		memcpy(_chunk, pstr + _totalByte, _lastByte);
		//处理最后一个数据块
		calculateMD5Final();
		//拼接 a,b,c,d字符串
		return changeHex(_a) + changeHex(_b) + changeHex(_c) + changeHex(_d);
	}
}





