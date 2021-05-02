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
# define debug(x) std::cerr << #x << " : " << x << "\n";
using namespace std;
using lint = long long;
template <class T> using grid = vector<vector<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
static const lint MOD = (lint)1e9+7;

static const int Nmax = 1000;

std::vector<bool> IsPrime;

void sieve(size_t max){
    if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
    } 
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for(size_t i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]) // iが素数ならば
            for(size_t j=2; i*j<=max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
}

int main()
{
    lint N; cin >> N;

    sieve(Nmax);

    vector<lint> primes;
    for (lint i = 2; i <= N; ++i)
    {
        if (IsPrime[i])
        {
            primes.pb(i);
        }
    }
    vector<lint> counters(SZ(primes), 1);
    lint sqrtN = sqrt(N) + 1;
    for (lint i = 1; i <= N; ++i)
    {
        lint t = i;
        for (lint p = 0; p < SZ(primes); ++p)
        {
            while (t % primes[p] == 0)
            {
                t /= primes[p];
                counters[p]++;
            }
        }
    }

    lint ans = 1;
    for (lint i = 0; i < counters.size(); ++i)
    {
        ans = (ans * counters[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
