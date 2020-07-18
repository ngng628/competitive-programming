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

    vector<int> A(N);
    rep (i, N) { cin >> A[i]; }

    vector<int> B(N);
    map<int, lint> mp;
    priority_queue<int, vector<int>, greater<int>> que;
    lint allSum = 0;
    rep (i, N) 
    { 
        cin >> B[i];
        mp[i] = B[i]; 
    }


    lint value = que.top(); que.pop();
    int index = mp.at(value);
    lint sum = allSum - value;
    lint a0 = A[index];
    lint t = value;
    lint S = allSum - value;
    lint cnt = 0;
    if ((t - a0) % S)
    {
        cnt += (t - a0) / S;
    }



    return 0;
}
