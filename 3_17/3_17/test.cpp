//把字符串翻转成整型
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
			return 0;
		//字符转数字  c - '0'
		string::iterator sit = str.begin();
		int ret = 0;
		int flag = 1;
		while (sit != str.end())
		{
			ret *= 10;
			if (*sit >= '0' && *sit <= '9')
			{
				ret += *sit - '0';
			}
			else if (*sit == '-' || *sit == '+')
			{
				if (*sit == '-')
					flag = -1;
			}
			else
			{
				return 0;
			}
			++sit;
		}
		return ret * flag;
	}
};
int main()
{
	
	string s;
	cout << s.max_size() << endl;
	system("pause");
	return 0;
}