#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    unordered_map <char, int> freq;

    for(char ch: s)
    {
        freq[ch]++;
    }

    int oddCount = 0;

    for(auto it: freq)
    {
        if(it.second % 2 != 0)
        {
            oddCount++;
        }
    }

    return oddCount<=1;
}

int main ()
{
    string s;
    cin >> s;

    if(s.length() >= 1 && s.length() <=50)
    {
        if(isPalindrome(s))
        {
            cout << "YES\n";
        }
        else
        {
            cout <<"NO\n";
        }
    }

    return 0;
}