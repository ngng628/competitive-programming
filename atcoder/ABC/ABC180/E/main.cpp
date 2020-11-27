#include <bits/stdc++.h>
using namespace std;
#define all(c) begin(c), end(c)
#define range(i,a,b) for(int i = a; i < (int)(b); i++)
#define rep(i,b) range(i,0,b)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
using ll = long long;
// #define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
void fastios(){ ios_base::sync_with_stdio(0); cin.tie(0); }
int const mod = 1000000007;
auto const inf = numeric_limits<int>::max()/8;

using Weight = int;
using Capacity = int;
struct Edge {
    int src, dst; Weight weight;
    Edge(int s, int d, int w) : src(s), dst(d), weight(w) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

Weight tsp(const Graph &g){
    int n = g.size();
    Matrix m(n, Array(n, inf));
    for(auto &es : g) for(auto &e : es) m[e.src][e.dst] = min(m[e.src][e.dst], e.weight);
    Matrix dp(1<<n, Array(n, inf));
    dp[0][0] = 0;
    for(int S = 0; S < 1<<n; S++)
        for(int u = 0; u < n; u++)
            for(int v = 0; v < n; v++)
                if(!((S >> v) & 1))
                    dp[S|1<<v][v] = min(dp[S|1<<v][v], dp[S][u] + m[u][v]);
    return dp[(1<<n)-1][0];
}

int main(){
    fastios();
    int n;
    cin >> n;
    vi x(n), y(n), z(n);
    rep (i, n) cin >> x[i] >> y[i] >> z[i];

    Graph g(n);
    rep (i, n) {
        range (k, i+1, n) {
            int a = i;
            int b = k;
            int c1 = abs(x[k] - x[i]) + abs(y[k] - y[i]) + max(0, z[k] - z[i]);
            int c2 = abs(x[k] - x[i]) + abs(y[k] - y[i]) + max(0, z[i] - z[k]);
            //cout << a << " " << b << " " << c << endl;
            g[a].eb(a, b, c1);
            g[b].eb(b, a, c2);
        }
    }

    int ans = tsp(g);
    cout << (ans==inf ? -1 : ans) << '\n';

    return 0;
}
