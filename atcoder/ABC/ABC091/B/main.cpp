# include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) { cin >> S[i]; }
    int M; cin >> M;
    vector<string> T(M);
    for (int i = 0; i < M; ++i) { cin >> T[i]; }

    map<string, int> mp;
    for (const auto& s : S) { mp[s]++; }
    for (const auto& t : T) { mp[t]--; }

    int ans = 0;
    for (const auto& p : mp)
    {
        if (ans < p.second) { ans = p.second; }
    }

    cout << ans << "\n";

    return 0;
}

