#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
using namespace std;
//stack��queue

//ջ�ĵ���ѹ��
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳��
//����4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
//��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		size_t psz = pushV.size();
		size_t popsz = popV.size();
		if (psz != popsz)
			return false;
		//ģ���ջ����
		stack<int> s;
		size_t pushIndex = 0;
		size_t popIndex = 0;
		while (pushIndex < psz)
		{
			s.push(pushV[pushIndex++]);
			while (!s.empty() && s.top() == popV[popIndex])
			{
				s.pop();
				popIndex++;
			}
		}
		return s.empty();

	}
};