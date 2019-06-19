//#define _CRT_SECURE_NO_WARNINGS 
//class Gift {
//public:
//	int getValue(vector<int> gifts, int n) {
//		sort(gifts.begin(), gifts.end());
//		//超过一半的数排序之后必然排在中间
//		int middle = gifts[n / 2];
//		int count = 0;
//		for (int i = 0; i < n; i++)
//		{
//			//统计排在中间的数的个数
//			if (gifts[i] == middle)
//			{
//				count++;
//			}
//		}
//		//如果个数大于一半，则存在超过一半的数
//		if (count > n / 2)
//			return middle;
//		else
//			return 0;
//	}
//};
///*思路二：map统计*/
//class Gift {
//public:
//	int getValue(vector<int> gifts, int n) {
//		map<int, int> count;
//int middle = gifts.size() / 2;
//for (const auto& e : gifts)
//{
//	++count[e];
//}
//for (const auto& e : count)
//{
//	if (e.second >= middle)
//		return e.first;
//}
//return 0;
//}
//};

#include <string>
#include <iostream>
#include <vector>
using namespace std;
int minDistance(string word1, string word2) {
	// word与空串之间的编辑距离为word的长度
	if (word1.empty() || word2.empty()) {
		return max(word1.size(), word2.size());
	}
	int len1 = word1.size();
	int len2 = word2.size();
	// F(i,j)初始化
	vector<vector<int> > f(1 + len1, vector<int>(1 + len2, 0));

	for (int i = 0; i <= len1; ++i) {
		f[i][0] = i;
	}
	for (int i = 0; i <= len2; ++i) {
		f[0][i] = i;
	}
	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) {
			// F(i,j) = min { F(i-1,j）+1, F(i,j-1) +1, F(i-1,j-1) +
			//(w1[i]==w2[j]?0:1) }
			// 判断word1的第i个字符是否与word2的第j个字符相等
			if (word1[i - 1] == word2[j - 1]) {
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// 字符相等，F(i-1,j-1)编辑距离不变
				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}
			else {
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// 字符不相等，F(i-1,j-1)编辑距离 + 1
				f[i][j] = min(f[i][j], 1 + f[i - 1][j - 1]);
			}
		}
	}
	return f[len1][len2];
}
int main(){
	string a, b;
	while (cin >> a >> b)
		cout << minDistance(a, b) << endl;
	return 0;
}