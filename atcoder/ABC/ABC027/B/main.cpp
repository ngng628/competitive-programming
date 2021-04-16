# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(std::begin(whole), std::end(whole), ## __VA_ARGS__); })(x)
# define rwhole(f,x,...) ([&](decltype((x)) rwhole) { return (f)(std::rbegin(whole), std::rend(whole), ## __VA_ARGS__); })(x)
# define int long long
# define float long double
using namespace std;
using vi = vector<int>;
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; print(args...); }
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; drop(args...); }

int32_t main() {
    int n; cin >> n;
    vi a(n); cin >> a;
    int sum = whole(accumulate, a, 0);
    if (sum % n != 0) drop(-1);

    int m = sum / n;
    int ans = 0;
    int cnt = 0;
    int island = 0;
    rep (i, n) {
        cnt += a[i];
        island++;
        if (cnt == m*island) cnt = island = 0;
        else ans++;
    }

    print(ans);
}
