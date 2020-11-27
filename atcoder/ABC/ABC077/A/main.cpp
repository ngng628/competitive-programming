# include <bits/stdc++.h>
using namespace std;
const char* YESNO(bool b) { return b ? "YES" : "NO"; }

int32_t main() {
    string s, t;
    cin >> s >> t;
    swap(s[0], s[2]);
    puts(YESNO(s == t));

    return 0;
}

