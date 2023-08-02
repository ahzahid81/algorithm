#include <bits/stdc++.h>
using namespace std;

const int N = 1e9;

int value[N];

int main ()
{
    int n, x;
    cin >> n >> x;

    for(int i = 1; i<=n; i++)
    {
        cin >> value[i];
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j =1; j<=n; j++)
        {
            if(i==j)
            {
                continue;
            }

            if(value[i] + value[j] == x)
            {
                cout << i <<" " << j << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
