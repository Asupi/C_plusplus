#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string> 
#include <cstdio> 
int main() 
{ 
	int n; while(std::cin >> n) //接收数字
	{ 
		std::cin.get(); //处理回车 
		std::string name; 
		for(int i=0; i < n; i++) //名字分别处理 
		{ 
			bool quote = false; 
			std::getline(std::cin, name);
			if (name.find(',') != std::string::npos ||
				name.find(' ') != std::string::npos) //找到逗号或者空格，就要加双引号 
			{ 
				quote = true; 
			}
			if (quote) 
			{ 
				putchar('\"'); //putchar效率更高 
			}
			std::cout << name; 
			if (quote)
			{ 
				putchar('\"');
			}
			if (i == n - 1) //如果已经是最后一个字符串，那就补回车，否则加逗号和空格 
			{ 
				putchar('\n'); 
			}else
			{ 
				putchar(','); 
				putchar(' '); 
			} 
		} 
	}
	return 0; 
}