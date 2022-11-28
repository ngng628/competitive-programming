# include <iostream>
# include <vector>
# include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(m + 3010, vector<int>(2, 100100100));
    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i = 1; i <= n; i++) {
        vector<vector<int>> dp2(m + 3010, vector<int>(2, 100100100));
        for (int j = 0; j <= m; j++) {
            dp2[j][0] = min(dp[j][0], dp[j][1] + 1);
            dp2[j + a[i]][1] = min(dp[j][0], dp[j][1]);
        }
        swap(dp, dp2);
    }

    for (int x = 1; x <= m; x++) {
        int ans = min(dp[x][0], dp[x][1]);
        if (ans >= 100100100) {
            cout << -1 << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }
}