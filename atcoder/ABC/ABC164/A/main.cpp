# include <bits/stdc++.h>
using namespace std;

int read() { int a; cin >> a; return a; }
string Ans(bool b) { return b ? "unsafe" : "safe"; }

signed main()
{
    cout << Ans(read() <= read()) << endl;

    return 0;
}

