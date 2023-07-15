#include <bits/stdc++.h>
using namespace std;

char getCapital(string str)
{
    if(str.empty() || isupper(str[0]))
    {
        return str[0];
    }

    return getCapital(str.substr(1));
}

int main()
{
    string input = "thisStRIng";
    char capital = getCapital(input);
    cout << "First capital letter: " << capital <<"\n";
    return 0;
}