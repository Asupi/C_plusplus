#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		// array�Ƕ�ά���飬����û���пղ���
		int rows = array.size();
		int cols = array[0].size();
		int i = rows - 1, j = 0;//���½�Ԫ������
		while (i >= 0 && j<cols){//ʹ�䲻�������鷶Χ
			if (target<array[i][j])
				i--;//���ҵ�Ԫ�ؽ��٣�������
			else if (target>array[i][j])
				j++;//����Ԫ�ؽϴ�������
			else
				return true;//�ҵ�
		}
		return false;
	}
};

