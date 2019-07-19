

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s, res;
    while (getline(cin, s))
    {
        getline(cin, res);
        bool sta = false;
        for (int i = 0; i < s.length(); i++)
        {
            string t;
            if (s[i] == '"')
            {
                i++;
                while (i<s.length()&&s[i] != '"')
                {
                    t += s[i];
                    i++;
                }
                if (t == res)
                {
                    sta = true;
                    break;
                }
            }
            else if (s[i] != ',')
            {
                while (i<s.length()&&s[i] != ',')
                {
                    t += s[i];
                    i++;
                }
                if (t == res)
                {
                    sta = true;
                    break;
                }
            }
        }
        if (sta == true)
            cout << "Ignore" << endl;
        else
            cout << "Important!" << endl;
    }
    return 0;
}