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
