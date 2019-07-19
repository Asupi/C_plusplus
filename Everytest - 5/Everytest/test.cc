
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <sstream>
 
using namespace std;
 
long long greatestCommonDivisor(long long a, long long b);
string getProperFraction(long long num, long long den);
 
int main()
{
    // 提取分数的两部分
    string fraction1, fraction2;
    cin >> fraction1 >> fraction2;
    long long num1, den1, num2, den2;
    int nPos = fraction1.find('/');
    num1 = atoi((fraction1.substr(0, nPos)).c_str());
    den1 = atoi((fraction1.substr(nPos+1)).c_str());
    nPos = fraction2.find('/');
    num2 = atoi((fraction2.substr(0, nPos)).c_str());
    den2 = atoi((fraction2.substr(nPos+1)).c_str());
 
    // 四则运算
    string first = getProperFraction(num1, den1);
    string second = getProperFraction(num2, den2);
        // +
    long long num = num1*den2 + num2*den1;
    long long den = den1*den2;
    string third = getProperFraction(num, den);
    cout << first << " + " << second << " = " << third << endl;
        // -
    num = num1*den2 - num2*den1;
    third = getProperFraction(num, den);
    cout << first << " - " << second << " = " << third << endl;
        // *
    num = num1*num2; den = den1*den2;
    third = getProperFraction(num, den);
    cout << first << " * " << second << " = " << third << endl;
        // /
    num = num1*den2; den = den1*num2;
    if(den == 0) {
        cout << first << " / " << second << " = Inf" << endl;
    } else {
        third = getProperFraction(num, den);
        cout << first << " / " << second << " = " << third << endl;
    }
 
    return 0;
}
 
string getProperFraction(long long num, long long den)
{
    // 基本边界、基本变量
    if(num == 0) {
        return "0";
    }
    bool isMinus = false;
    string str = "";
    if(num*den < 0) {
        isMinus = true; num = abs(num);
        den = abs(den); str = "(-";
    }
 
    //约分
    long long gcd = greatestCommonDivisor(num, den);
    num /= gcd; den /= gcd;
    stringstream ss; ss << (num/den);
    string intPart, fracPart;
    ss >> intPart;
    stringstream ss2; ss2 << (num%den);
    ss2 >> fracPart;
    if((num/den)>0) {
        str += intPart;
    }
    if((num%den)>0) {
        if((num/den)>0) {
            str += " ";
        }
        str += fracPart; str += '/';
        stringstream ss3; string temp;
        ss3 << den; ss3 >> temp;
        str += temp;
    }
    if(isMinus) {
        str += ')';
    }
    return str;
}
 
long long greatestCommonDivisor(long long a, long long b)
{
    long long c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
