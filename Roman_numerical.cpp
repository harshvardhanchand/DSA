#include <iostream>
#include <map>
#include <string>
using namespace std;
int romain_to_decimal(string s)
{
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i < s.size() - 1 && m[s[i]] < m[s[i + 1]])
        {
            sum -= m[s[i]];
        }
        else
        {
            sum += m[s[i]];
        }
    }
    return sum;
}

int main()
{
    return 0;
}