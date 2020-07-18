///------------------------------------------
/// つらい道を避けないこと。
/// 自分の目指す場所にたどりつくためには
/// 進まなければ。
///
/// - キャサリン・アン・ポーター -
///------------------------------------------
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

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

lint bubble(std::vector<int>& ary)
{
    lint cnt = 0;
    for (int i = 0; i < SZ(ary); ++i)
    {
        for (int k = SZ(ary) - 1; k > i; --k)
        {
            if (ary[k] < ary[k-1])
            {
                swap(ary[k], ary[k-1]);
                cnt++;
            }
        }
    }
    return cnt;
}

lint Sum(lint a0, lint d, lint n)
{
    lint sub1 = (2*n*a0)%MOD;
    lint sub2 = (n*(n-1)*d)%MOD;
    lint sub = (sub1 + sub2) % MOD;
    sub = sub * modinv(2, MOD);
    sub %= MOD;
    return sub;
}
    

int main()
{
    lint N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep (i, N) { cin >> A[i]; }

    vector<int> B1 = A;

    for (int i = 0; i < N; ++i)
    {
        A.push_back(B1[i]);
    }

    vector<int> B2 = A;

    for (int i = 0; i < N; ++i)
    {
        A.push_back(B1[i]);
    }
    
    vector<int> B3 = A;

    lint cnt1 = bubble(B1);
    lint cnt2 = bubble(B2);
    lint cnt3 = bubble(B3);

    if (K == 1)
    {
        cout << cnt1 << endl;
        return 0;
    }

    lint a0 = cnt2 - cnt1;
    lint d = cnt3 - cnt2 - a0;
    lint k = K - 1;

    lint s = Sum(a0, d, k);

    cout << (cnt1 + s) % MOD << endl;

    return 0;
}
