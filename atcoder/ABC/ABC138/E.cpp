// 名言用意してないわ
// てかなんでwakasuki D解いとんねん
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

struct Range
{
    int left;
    int right;
};

int main()
{
    string s; cin >> s;
    string t; cin >> t;

    map<char, lint> mps;
    rep (i, s.length())
    {
        mps[s[i]]++;
    }
    map<char, lint> mpt;
    rep (i, t.length())
    {
        mpt[t[i]]++;
    }
    
    rep (i, t.length())
    {
        if (mps[t[i]] == 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    Range range;

    // 文字の重複つらみ
    // 結局、左からmin-maxのrangeのvectorを作っていって
    // そのvectorの大きさがほぼほぼ答えを示してんじゃねぇの（わからん）


    return 0;
}
