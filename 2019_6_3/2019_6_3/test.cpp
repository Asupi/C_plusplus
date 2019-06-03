#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string input;
	while (getline(cin, input))
	{
		vector<string> ans;
		string tmp = "";
		string order = "";
		for (int i = 0; i< input.size(); i++)
		{
			if (input[i] == ' ')//遇到空格处理之前保存的
			{
				if (!tmp.empty())
					ans.push_back(tmp);
				tmp.clear();
			}
			else if (input[i] == '"')//遇到引号，处理这部分
			{
				i++;
				while (input[i] != '"')
				{
					tmp.push_back(input[i]);
					i++;
				}
			}
			else//命令部分，都保存起来
				tmp.push_back(input[i]);
		}
		if (!tmp.empty())
			ans.push_back(tmp);

		cout << ans.size() << endl;
		for (int i = 0; i<ans.size(); i++)
			cout << ans[i] << endl;
	}

	return 0;
}