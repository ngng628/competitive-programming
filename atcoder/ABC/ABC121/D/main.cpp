# include <bits/stdc++.h>
using namespace std;
bool IsOdd(long long n) { return n & 1; }
bool IsEven(long long n) { return !(n & 1); }
long long read() {long long a;cin >> a;return a;}

long long F(long long b)
{
    if (IsOdd(b))
        return (long long)IsOdd((b+1)/2);
    else
        return b == 0 ? 0 : b ^ F(b-1);
}

int main()
{
    cout << (F(read()-1) ^ F(read())) << endl;
    return 0;
}

