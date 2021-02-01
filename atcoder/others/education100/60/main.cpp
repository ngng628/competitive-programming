# include <bits/stdc++.h>
# define rep(i,n) for(int i=0;i<(int)(n);++i)
# define INF 123454321
using namespace std;

using Matrix = vector<vector<int>>;

int main() {
    int V, E;
    cin >> V >> E;
    Matrix graph(V, vector<int>(V, INF));
    rep (i, V) graph[i][i] = 0;
    rep (_, E) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s][t] = d;
    }

    Matrix dist(graph);
    rep (k, V) rep (i, V) rep (j, V) {
        if (dist[i][k] == INF or dist[k][j] == INF) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    rep (i, V) {
        if (dist[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << "\n";
            return 0;
        }
    }

    rep (i, V) {
        rep (k, V) {
            if (dist[i][k] == INF) cout << "INF";
            else cout << dist[i][k];
            if (k != V-1) cout << " ";
            else cout << "\n";
        }
    }
}