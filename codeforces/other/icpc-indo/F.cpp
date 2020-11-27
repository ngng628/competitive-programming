# include <bits/stdc++.h>
# define rep(i,n) for (int i = 0; i < (n); i++)
# define all(v) (v).begin(), (v).end()
# define sz(v) ((int)(v).size())
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    cout << "? " << 1 << " " << n << endl;
    int sum; cin >> sum;
    const int old = sum;
    vector<int> ans;
    for (int i = n-1; i >= 2; --i) {
        cout << "? " << 1 << " " << i << endl;
        int in; cin >> in;
        ans.push_back(sum - in);
        sum -= (sum - in);
    }
    cout << "? " << 2 << " " << n << endl;
    int in; cin >> in;
    int tmp = old - in;

    int tmpp = 0;
    rep (i, sz(ans)) {
        tmpp += ans[i];
    }
    ans.push_back(old - tmpp - tmp);
    ans.push_back(tmp);

    cout << "!";
    for (int i = sz(ans) - 1; i >= 0; --i) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}