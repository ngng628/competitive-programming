# include <bits/stdc++.h>
# define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    const int INF = INT_MAX;
    vector<int> B(N, INF);
    rep (i, N-1) cin >> B[i];

    int sum = B[0];
    rep (i, N - 1) sum += min(B[i], B[i+1]);
    cout << sum << endl;

    return 0;
}
