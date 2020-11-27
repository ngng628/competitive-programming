# include <bits/stdc++.h>
# define rep(i,n) for (int i = 0; i < (int)(n); ++i)
# define all(v) (v).begin(), (v).end()
# define rall(v) (v).rbegin(), (v).rend()
# define sz(v) ((int)(v).size())
using ll = long long;
using namespace std;

int plus(int a, int b) { return a + b; }
int times(int a, int b) { return a * b; }

void Main(int n, vector<string>& s) {
    vector<int> levels(n);
    int max_level = 0;
    rep (i,n) {
        levels[i] = count(all(s[i]), '.');
        max_level = max(max_level, levels[i]);
    }

    int now = max_level;
    while (not s.empty()) {
        rep (i, sz(levels))
            if (levels[i] == now) {
                char op = s[i-1][sz(s[i-1]) - 1];
                if (op == '+') {
                    
                }
            }
        }
    }
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (!n) break;
        vector<string> s(n);
        rep (i, n) cin >> s[i];
        Main(n, s); 
    }
    return 0;
}