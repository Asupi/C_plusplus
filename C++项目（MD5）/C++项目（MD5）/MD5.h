
#pragma once
#define  N 64
class MD5
{
private:

	void calculateMD5(size_t* chunk);
	size_t _a;
	size_t _b;
	size_t _c;
	size_t _d;

	size_t _k[N];
	size_t _sft[N];
	std::string MD5::getFileMd5(const char* filename);
	std::string MD5::getStringMd5(const std::string& str);

	const size_t _chunkByte;
    size_t _totalByte;
	unsigned char _chunk[N];
};