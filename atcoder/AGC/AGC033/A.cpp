# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define MSG(x) std::cout << #x << " : " << x << "\n";
using namespace std;
using lint = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

lint H, W;
vector<string> A;

// bool Over(int y, int x)
// {
//     if (y < 0 || H - 1 < y)
//     {
//         return true;
//     }
//     if (x < 0 || W - 1 < x)
//     {
//         return true;
//     }
//     return false;
// }

int main()
{
    cin >> H >> W;
    A.resize(H);
    vector<vector<lint>> distance_map;
    distance_map.resize(H);
    rep (y, H)
    {
        cin >> A[y];
        distance_map[y].resize(W);
        rep (x, W)
        {
            distance_map[y][x] = LLONG_MAX;
        }
    }

    int res = 0;

    rep (y, H)
    {
        rep (x, W)
        {
            if (A[y][x] == '#')
            {
                rep (v, H)
                {
                    rep (u, W)
                    {
                        if (A[v][u] == '#')
                        {
                            switch(y - v)
                        }
                        lint yy = abs(y - v);
                        lint xx = abs(x - u);
                        chmin(distance_map[v][u], yy + xx);
                    }
                }
            }
        }
    }

    lint ans = -1;
    rep (y, H)
    {
        rep (x, W)
        {
            chmax(ans, distance_map[y][x]);
        }
    }

    cout << ans << "\n";

    return 0;
}
