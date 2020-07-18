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

int main()
{
    int N; cin >> N;
    vector<int> a(N);
    rep (i, N)
    {
        int b; cin >> b;
        a[i] = b-1;
    }

    vector<vector<int>> graph(N);
    graph[0].push_back(a[0]);
    for (int i = 0; i + 1 < N; ++i)
    {
        graph[a[i]].push_back(a[i+1]);
    }

    vector<int> visited(N, false);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    int d = 1;

    while (!q.empty())
    {
        int now = q.front(); q.pop();
        if (now == 1)
        {
            cout << d << endl;
            return 0;
        }
        if (visited[graph[now][0]])
        {
            cout << "-1" << endl;
            return 0;
        }
        visited[graph[now][0]] = true;
        q.push(graph[now][0]);
        d++;
    }

    return 0;
}

