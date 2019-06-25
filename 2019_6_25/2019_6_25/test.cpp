#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
using namespace std;
class bitSet
{
public:
	bitSet(size_t range)
	{
		_bits.resize((range >> 5) + 1);
	}
	//把x对应的位设为1，表示存在
	void Set(size_t x)
	{
		size_t index = x >> 5;
		size_t bitNum = x % 32;
		_bits[index] |= (1 << bitNum);
	}

	//把x对应的位设为0，表示不存在
	void ReSet(size_t x)
	{
		size_t index = x >> 5;
		size_t bitNum = x % 32;
		_bits[index] &= (~(1 << bitNum));
	}


	//把x对应的位是否为1
	bool Test(size_t x)
	{
		size_t index = x >> 5;
		size_t bitNum = x % 32;
		return _bits[index] & (1 << bitNum);
	}

private:
	vector<int> _bits;
};

template <class K,
class HashFun1,
class HashFun2,
class HashFun3>
class BloomFilter
{
public:
	// k = m * ln2 / n
	// k : 哈希函数数量
	// n : range
	// m : 需要的bit位数量
	// m = k * n / ln2  --->   k * range / 0.7  4.x * range
	BloomFilter(size_t range)
		:bs(range * 5)
		, _bitCount(range * 5)
	{}

	void Set(const K& key)
	{
		size_t index1 = HashFun1()(key) % _bitCount;
		size_t index2 = HashFun2()(key) % _bitCount;
		size_t index3 = HashFun3()(key) % _bitCount;
		bs.Set(index1);
		bs.Set(index2);
		bs.Set(index3);
	}

	bool Test(const K& key)
	{
		size_t index1 = HashFun1()(key) % _bitCount;
		if (!bs.Test(index1))
			return false;
		size_t index2 = HashFun2()(key) % _bitCount;
		if (!bs.Test(index2))
			return false;
		size_t index3 = HashFun3()(key) % _bitCount;
		if (!bs.Test(index3))
			return false;

		return true;   // 误判
	}



private:
	bitSet bs;
	size_t _bitCount;
};

struct HF1
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& e : str)
		{
			hash = hash * 131 + e;
		}
		return hash;
	}
};

struct HF2
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& e : str)
		{
			hash = hash * 65599 + e;
		}
		return hash;
	}
};


struct HF3
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		size_t magic = 63689;
		for (const auto& e : str)
		{
			hash = hash * magic + e;
			magic *= 378551;
		}
		return hash;
	}
};

void testbloom()
{
	BloomFilter<string, HF1, HF2, HF3> bf(100);
	string http1 = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
	string http3 = "https://connect.qq.com/widget/shareqq/index.html?url=https%3A%2F%2Fwww.douyu.com%2Froom%2Fshare%2F6924884%3Ffromuid%3D295813006&desc=%E7%94%A8%E6%88%B715316972%E5%BC%80%E6%92%AD%E4%BA%86%EF%BC%8C%E5%BF%AB%E6%9D%A5%E5%9B%B4%E8%A7%82%E5%90%A7~&title=%E6%96%97%E9%B1%BC%E7%9B%B4%E6%92%AD%E9%97%B4%EF%BC%8C%E4%BC%A0%E9%80%92%E6%AD%A3%E8%83%BD%E9%87%8F%EF%BC%81%E4%B8%BB%E6%92%AD%E7%94%A8%E6%88%B715316972%E6%AD%A3%E5%9C%A8%E7%9B%B4%E6%92%AD%EF%BC%8C%E6%88%BF%E9%97%B4%E5%90%8DbitTech%EF%BC%8C%E6%88%BF%E9%97%B4%E5%8F%B7%EF%BC%9A6924884%20https%3A%2F%2Fwww.douyu.com%2F6924884%EF%BC%8C%E6%9D%A5%E8%87%AA%23%E6%96%97%E9%B1%BC%E7%9B%B4%E6%92%AD%E5%B9%B3%E5%8F%B0%23%E5%85%A8%E7%90%83%E9%A2%86%E5%85%88%E7%9A%84%E7%BB%BC%E5%90%88%E7%9B%B4%E6%92%AD%E5%B9%B3%E5%8F%B0%EF%BC%81&pics=";
	string http4 = "https://www.cnblogs.com/-clq/p/8323799.html";


	string http2 = "https://www.cnblogs.com/-clq/archive/2002/05/31/2528153.html";

	bf.Set(http1);
	bf.Set(http3);
	bf.Set(http4);

	bool ret = bf.Test(http2);
	ret = bf.Test(http1);
	ret = bf.Test(http3);

}

int main()
{
	testbloom();
	return 0;
}