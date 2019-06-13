#include <vector>
using namespace std;
class bitSet
{
public:
	bitSet(size_t range)
	{
		_bits.resize((range >> 5) + 1);
	}
	//��x��Ӧ��λ��Ϊ1����ʾ����
	void Set(size_t x)
	{
		size_t index = x >> 5;
		size_t bitNum = x % 32;
		_bits[index] |= (1 << bitNum);
	}

	//��x��Ӧ��λ��Ϊ0����ʾ������
	void ReSet(size_t x)
	{
		size_t index = x >> 5;
		size_t bitNum = x % 32;
		_bits[index] &= (~(1 << bitNum));
	}


	//��x��Ӧ��λ�Ƿ�Ϊ1
	bool Test(size_t x)
	{
		size_t index = x >> 5;
		size_t bitNum = x % 32;
		return _bits[index] & (1 << bitNum);
	}

private:
	vector<int> _bits;
};
