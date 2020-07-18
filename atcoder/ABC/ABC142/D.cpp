# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
# define SZ(x) ((int)(x).size())
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define debug(x) std::cerr<<#x<<": "<<(x)<<endl;
using namespace std;
using lint = long long;
template<class T> using grid = vector<vector<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
static const lint MOD = (lint)1e9+7;

vector<int> divisors(int a, int b) {
    vector<int> res;
    int c = a;
    if (a > b)
    {
        c = b;
    }
    for (int i = 1; i*i <= c; ++i)
    {
        if (a%i == 0 && b%i == 0)
        {
            res.push_back(i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
map< lint, lint > prime_factor(lint n) {
  map< lint, lint > ret;
  for(lint i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main()
{
    lint A, B;
    cin >> A >> B;

    map<lint, lint> Amp = prime_factor(A);
    map<lint, lint> Bmp = prime_factor(B);

    lint cnt = 0 + 1;
    for (auto& ap : Amp)
    {
        for (auto& pb : Bmp)
        {
            if (ap.first == pb.first)
            {
                cnt += 1;
                break;
            }
            else if (ap.first < pb.first)
            {
                break;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
