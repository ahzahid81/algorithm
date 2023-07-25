// print 1 to n

#include <bits/stdc++.h>
using namespace std;


void printNum(int num)
{
    if(num == 0) // base case
    {
        return;
    }
    printNum(num-1); // recursive function
    cout << num <<" ";
}

int main ()
{
    int n;
    cin >> n;
    printNum(n);
    return 0;
}
