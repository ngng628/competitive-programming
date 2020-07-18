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
# define TO_STRING(x) #x
using namespace std;
using lint = long long;
template<class T> using grid = vector<vector<T>>;
template<class T>void debug(const T &x) {cerr<<TO_STRING(x)<<": "<<x<<"\n";}
template<class T>void debug(const vector<T>& ary, const T& i) {cerr<<TO_STRING(ary)<<"["<<i<<"]: "<<ary[i]<< "\n";}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
static const lint MOD = (lint)1e9+7;

# define Nmax (8)

bool graph[Nmax][Nmax];

int dfs(int v, int N, bool visited[Nmax])
{
    bool all_visited = true;
    rep (i, N)
    {
        if (visited[i] == false)
        {
            all_visited = false;
        }
    }

    if (all_visited)
    {
        return 1;
    }

    int ret = 0;

    rep (i, N)
    {
        if (graph[v][i] == false)
        {
            continue;
        }
        if (visited[i])
        {
            continue;
        }
        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }
    
    return ret;
}

int main()
{
    int N, M;
    cin >> N >> M;

    rep (i, M)
    {
        int A, B;
        cin >> A >> B;
        A -= 1;
        B -= 1;
        graph[A][B] = graph[B][A] = true;
    }

    bool visited[Nmax];
    rep (i, N)
    {
        visited[i] = false;
    }

    visited[0] = true;

    cout << dfs(0, N, visited) << endl;

    return 0;
}
