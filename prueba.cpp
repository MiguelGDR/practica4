#include "iostream"
#include <string>
#include <cassert>

using namespace std;

int main()
{
    string s1 = "Palabra", s2 = "Alfa";
    bool s1menor = false, s2menor = false;


    if (s1.length() >= s2.length())
    {
        while (!s1menor && !s2menor)
        {
            for (int i = 0; i < s2.length(); i++)
            {
                if (s1[i] < s2[i])
                {
                    s1menor = true;
                    break;
                }
                if (s2[i] < s1[i])
                {
                    s2menor = true;
                    break;
                }
                if ((i + 1) == s2.length())
                {
                    s2menor = true;
                    break;
                }
            }
        }
    }
    else
    {
        while (!s1menor && !s2menor)
        {
            for (int i = 0; i < s1.length(); i++)
            {
                if (s1[i] < s2[i])
                {
                    s1menor = true;
                    break;
                }
                if (s2[i] < s1[i])
                {
                    s2menor = true;
                    break;
                }
                if ((i + 1) == s1.length())
                {
                    s1menor = true;
                    break;
                }
            }
        }
    }

    if(s1menor)
    {
        cout << s1 << ", " << s2;
    }
    else if(s2menor)
    {
        cout << s2 << ", " << s1;
    }

    return 0;
}