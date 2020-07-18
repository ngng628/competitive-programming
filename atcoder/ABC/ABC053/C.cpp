# include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main()
{
    lint x;
    cin >> x;

    lint ans = 0;
    ans += x / 11;

    if (x % 11 == 0)
    {
        cout << 2*ans << endl;
    }
    else if (x % 11 <= 6)
    {
        cout << 2*ans + 1 << endl;
    }
    else 
    {
        cout << 2*ans + 2 << endl;
    }

    return 0;
}
