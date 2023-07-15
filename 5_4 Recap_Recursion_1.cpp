#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string str)
{
    int n = str.size();

    int l = 0, r = n-1;
    while(l<r)
    {
        if(str[l] != str[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main ()
{
    string st;
    cin >> st;
    if(is_palindrome(st) == true)
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }
    return 0;
}