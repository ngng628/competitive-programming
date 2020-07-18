# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> d(N);
    rep (i, N) {
        cin >> d[i];
    }

    vector<int> sums(N+1, 0);
    rep (i, N) {
        sums[i+1] = sums[i] + d[i];
    }

    int ans = 0;
    rep (i, N) {
        ans += d[i]*(sums[N] - sums[i+1]);
    }

    cout << ans << endl;

    return 0;
}

