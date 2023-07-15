#include <bits/stdc++.h>
using namespace std;

string reverse(string str)
{
    if(str =="" || str.size() ==1)
    {
        return str;
    }

    char lastChar = str.back();
    string substring = str.substr(0, str.size()-1);
    return lastChar + reverse(substring);
    
}

int main ()
{
    string input = "phitron";
    string reversed = reverse(input);
    cout << " Reversed String: " <<reversed<<"\n";
    return 0;

}