#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string> 
#include <cstdio> 
int main() 
{ 
	int n; while(std::cin >> n) //��������
	{ 
		std::cin.get(); //����س� 
		std::string name; 
		for(int i=0; i < n; i++) //���ֱַ��� 
		{ 
			bool quote = false; 
			std::getline(std::cin, name);
			if (name.find(',') != std::string::npos ||
				name.find(' ') != std::string::npos) //�ҵ����Ż��߿ո񣬾�Ҫ��˫���� 
			{ 
				quote = true; 
			}
			if (quote) 
			{ 
				putchar('\"'); //putcharЧ�ʸ��� 
			}
			std::cout << name; 
			if (quote)
			{ 
				putchar('\"');
			}
			if (i == n - 1) //����Ѿ������һ���ַ������ǾͲ��س�������Ӷ��źͿո� 
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