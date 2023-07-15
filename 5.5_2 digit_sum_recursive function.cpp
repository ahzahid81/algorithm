#include <bits/stdc++.h>
using namespace std;

int digitsum(int n)
{
    if(n<10)
    {
        return n;
    }

    int lastDigit = n % 10;
    int quotient = n/10;
    return lastDigit + digitsum(quotient);
}

int main ()
{
    int input = 7464;
    int sum = digitsum(input);
    cout << "Sum of digits: " << sum << "\n";
    return 0;
}