#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		// array是二维数组，这里没做判空操作
		int rows = array.size();
		int cols = array[0].size();
		int i = rows - 1, j = 0;//左下角元素坐标
		while (i >= 0 && j<cols){//使其不超出数组范围
			if (target<array[i][j])
				i--;//查找的元素较少，往上找
			else if (target>array[i][j])
				j++;//查找元素较大，往右找
			else
				return true;//找到
		}
		return false;
	}
};

