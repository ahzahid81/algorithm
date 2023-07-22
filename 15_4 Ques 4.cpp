#include <bits/stdc++.h>
using namespace std;

int recursion_sum(vector <int> &a, int sz)
{
    if(sz == 0)
    {
        return 0;
    }
    return a[sz-1] + recursion_sum(a, sz-1);
}

int main ()
{
    int n;
    cin >> n;
    if(n<1 || n>100)
    {
        return 0;
    }

    vector <int> a(n);

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        if(a[i] < 1 || a[i] > 1000)
        {
            return 0;
        }
    }

    int result = recursion_sum(a, n);
    cout << result <<"\n";
    return 0;
}