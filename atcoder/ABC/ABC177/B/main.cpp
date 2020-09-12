# include <bits/stdc++.h>
using namespace std;

signed main() {
    string S, T;
    cin >> S >> T;
    const int n = S.length(), m = T.length();
    int ans = 0;
    for (int i = 0; i < n - m + 1; i++) {
        string s = S.substr(i, m);
        int cnt = 0;
        for (int k = 0; k < m; k++) cnt += (s[k] == T[k]);
        ans = max(ans, cnt);
    }

    cout << m - ans << endl;

    return 0;
}

