# include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n, 0);
    while (q--) {
        int l, r, t;
        cin >> l >> r >> t;
        l--; r--;
        fill(a.begin() + l, a.begin() + r + 1, t);
    }

    for (int  it : a) cout << it << endl;

    return 0;
}
