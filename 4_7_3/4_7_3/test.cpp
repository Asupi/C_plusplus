#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
//�沨�����ʽ��ֵ
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (size_t i = 0; i < tokens.size(); ++i)
		{
			string& str = tokens[i];
			// strΪ����
			if (!("+" == str || "-" == str || "*" == str || "/" == str))
			{
				s.push(atoi(str.c_str()));
			}
			else
			{
				// strΪ������
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();
				switch (str[0])
				{
				case '+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
					break;
				case '*':
					s.push(left * right);
					break;
				case '/':
					// ��Ŀ˵���˲����ڳ���Ϊ0�����
					s.push(left / right);
					break;
				}
			}
		}
		return s.top();
	}
};