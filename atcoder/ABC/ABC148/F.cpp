# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define debug(x) std::cerr<<#x<<": "<<(x)<<endl;
using namespace std;
using lint = long long;
template<class T> using grid = vector<vector<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
static const lint MOD = (lint)1e9+7;

static const lint MAX_V = (lint)1e6;
static const lint INF = (lint)1e9;

struct edge {
    int to;
    int cost;
};

typedef pair<int, int> P;  // first: 最短距離, second: 頂点番号

int V, d[MAX_V];
vector<edge> G[MAX_V]; // 隣接リスト表現

void dijkstra(int s) {
    fill(d, d + V, INF);
    d[s] = 0;  // 始点sへの最短距離は0

    priority_queue<P, vector<P>, greater<P>> que;  // 距離が小さい順に取り出せるようgreater<P>を指定
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;  // 更新した頂点の中で距離が最小の頂点v
        if (d[v] < p.first) {
            continue;
        }
        for (auto e : G[v]) {  // 頂点vから出る辺eを走査
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main()
{
    lint N, u, v;
    cin >> N >> u >> v;

    V = N - 1;
    for (lint i = 0; i < N-1; ++i)
    {
        lint a, b;
        cin >> a >> b;
        a--; b--;
        G[i] = edge(a, b);
    }

    dijkstra(u);

    return 0;
}
