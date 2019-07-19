#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string> 

#include<iostream>
int main()
{
    int day = 0;
    while (std::cin >> day) {
        long long cur = 1, next = 1;
        for (int i = 0; i < day; ++i) {
            long long tmp = next + cur;
            cur = next;
            next = tmp;
        }
        std::cout << cur << std::endl;
    }
    return 0;
}