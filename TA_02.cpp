#include <bits/stdc++.h>
using namespace std;

int power(int n, int m)
{
    if(m==0)
        return 1;
    else
        return n*power(n, m-1);
}

int main ()
{
    int n, m;
    cin >> n >> m;

    int result = power(n, m);
    cout << result <<"\n";

    return 0;
}