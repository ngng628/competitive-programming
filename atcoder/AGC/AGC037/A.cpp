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

string S;
int L;
string s;
map<string, int> mp;
string buff;
int cnt;

void func(int index)
{
    // 最後まで走査したら
    if (index >= L)
    {
        return;
    }

    if (s == "")
    {
        s = S[index];
    }
    else
    {
        s += S[index];
    }

    if (mp[s] == 0)
    {
        mp[s]++;
        cnt++;
        if (buff == "")
        {
            buff = s;
        }
        else
        {
            mp[buff] = 0;
            buff = s;
        }
        cerr << s << " ";
        s = "";
    }

    func(index + 1);
}


int main()
{
    buff = "";
    cnt = 0;
    cin >> S;
    L = S.length();

    func(0);

    int ans = cnt;

//    for (auto& it : mp)
//    {
//        cerr << it.first << " ";
//    }
//    cerr << endl;

    cout << ans << endl;

    return 0;
}
