#define _CRT_SECURE_NO_WARNINGS 
#include"MD5.h"
#include<cstring>
#include<fstream>
#include<math.h>

//��ʼ���б�
MD5::MD5()
:_chunkByte(N)
{
	init();
	memset(_chunk, 0, _chunkByte);
	_totalByte = _lastByte = 0;
}
void MD5::init()
{
	// ��ʼ��A,B,C,D
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

//����MD5
void MD5::calculateMD5(size_t* chunk)//����MD5��ֵ����������ݿ����ĸ��ֽ�Ϊ��λ
//���ⶨ�壬��Ҫ�����������
{
	size_t a = _a;
	size_t b = _b;
	size_t c = _c;
	size_t d = _d;

	//chunk[g]:��ǰѭ��Ҫ�õ���һ������  f:��ϣ�����ķ���ֵ
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
	

	//64�α任��4�ֲ�����ÿһ�ֲ�����16���Բ���
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
		//64�β�����ÿһ�μ������ϣ�����ķ���ֵ֮�󣬸��� a,b,c,d��ֵ
		size_t dtemp = d;//����dδ����֮ǰ��ֵ
		d = c;
		c = b;
		//a + f + _k[i] + chunk[g]��ѭ�����Ƶ����ݿ�
		b = b + shiftLeftRotate(a + f + _k[i] + chunk[g], _sft[i]);
		a = dtemp;

	}

	//��һ��512λ�����ݿ鴦����󣬸���MD buffer��ֵ
	_a += a;
	_b += b;
	_c += c;
	_d += d;
}


//�������һ�����ݿ飨����MD5��
void MD5:: calculateMD5Final()
{
	//lastByte�����һ�����ݵĴ�С��<64byte
	unsigned char* p=_chunk + _lastByte;
	//����������һ���ֽ�
	*p++ = 0x80;

	//remainFillbyte �����һ���ֽں�ʣ��Ҫ�������ݿ�Ĵ�С���ֽ�Ϊ��λ��
	size_t remainFillByte = _chunkByte - _lastByte - 1;

	//remainFillByte < 8,��ζ����һ������ʣ������ݲ�����¼ԭ�ĵĳ��ȣ�
	//��Ҫ���������ʣ��Ĳ���ȫ������0��Ȼ������ͬ���ķ���ȥ��������
	//����ٹ����һ���µ�512λ�����ݿ飬ǰ
	//448λ�������Ϊ0��ʣ��64λ��¼ԭ�ĵĳ���
	if (remainFillByte < 8)
	{
		memset(p, 0, remainFillByte);//���������ʣ��Ĳ���ȫ������0��
		calculateMD5((size_t*)_chunk);//��ͬ���ķ���ȥ������
		memset(_chunk, 0, _chunkByte);//�����µ����ݿ飬ȫ�����Ϊ0
	}
	else //����8�������㹻��¼ԭ�ĵĴ�С
	{
		memset(p, 0, remainFillByte);
	}
	//��ʣ�µĲ���ȫ���ó�0�󣬽������64λ����ͳһ����ר�ż�¼ԭ�ĵĳ���

	//�����_chunk��char���ͣ�ÿ��ƫ��1���ֽڣ�����char�������Ϊ256��������Ҫǿת
	//Ϊlong long���ͣ�ÿ��ƫ��8���ֽڣ�������Ϊ7��λ�������8���ֽ�
	((unsigned long long*)_chunk)[7] = _totalByte * 8;
	calculateMD5((size_t*)_chunk);//����������ݿ�
}



//�����ļ�
//����һ���ļ���MD5
std::string MD5::getFileMd5(const char* filename)
{
	std::ifstream fin(filename, std::ifstream::binary);//�����ļ�����ͬһ���ն����ƴ���
	if (fin.is_open())
	{
		//ֻҪû�ߵ��ļ���ĩβһֱ�ߣ�����64�ֽ�ȥ����
		while (!fin.eof())
		{
			fin.read((char*)_chunk, _chunkByte);//���ն����Ʒ�ʽ������������������
			                                   //�ŵ�Ҫ�������ݿ����棬ÿ�ζ�64���ֽ�

		   //�жϵ�ǰ���ݿ���˶��ٸ��ֽڣ��������64�ֽڣ���˵�������һ�飬��������
			if (_chunkByte != fin.gcount())
				break;

			//��64���ֽ�˵���������һ�����ݿ�
			//����ǰ�����������ۼӣ�ÿ�μ�һ�����ݿ飬_totalByte��¼ԭ�ĳ���(���ϱ仯��)
			_totalByte += _chunkByte;
			calculateMD5((size_t*)_chunk);//���㵱ǰ���ݿ��MD5
		}

		//���һ����������ݵĵĴ�С
		_lastByte = fin.gcount();
		_totalByte += _lastByte;//��ʱԭ�ĵ�ȫ�����ȼ�¼���
		calculateMD5Final();//�������һ������
	}

	return changeHex(_a) + changeHex(_b) + changeHex(_c) + changeHex(_d);
}

//�����ַ���
std::string MD5::getStringMd5(const std::string& str)
{
	if (str.empty())
		return "";
	else
	{
		unsigned char* pstr = (unsigned char*)str.c_str();
		size_t numChunk = str.size() / _chunkByte;
		for (size_t i = 0; i < numChunk; ++i)
		{
			_totalByte += _chunkByte;
			calculateMD5((size_t*)(pstr + i*_chunkByte));
		}
		_lastByte = str.size() % _chunkByte;
		memcpy(_chunk, pstr + _totalByte, _lastByte);
		calculateMD5Final();
		return changeHex(_a) + changeHex(_b) + changeHex(_c) + changeHex(_d);
	}
}

//������MD5�󣬽�����õ���ֵ������ת����16���Ƶ��ַ���,����a,b,c,d��ƴ��
//0x23456789--->89 67 45 23 
std::string MD5:: changeHex(size_t num)
{
	static std::string strMap = "0123456789abcdef";
	std::string ret;
	std::string byteStr;
	//�ֽ��ڲ���ͷ�壬�ֽ�֮��β��
	for (int i = 0; i < 4; i++)
	{
		byteStr = "";
		size_t b = (num >> (i * 8)) & 0xff;
		for (int j = 0; j < 2; ++j)
		{
			byteStr.insert(0, 1, strMap[b % 16]);
			b /= 16;
		}
		ret += byteStr;
	}
	return ret;
}




