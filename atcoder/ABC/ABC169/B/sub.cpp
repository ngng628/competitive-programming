//                              ______  ______  ______
// .-----..-----..-----..-----.|    __||__    ||  __  |
// |     ||  _  ||     ||  _  ||  __  ||    __||  __  |
// |__|__||___  ||__|__||___  ||______||______||______|
//        |_____|       |_____|
//
# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define rep2(x,y,w,h) rep (x, w) rep (y, h)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define reps2(x,y,w,h) reps (x, w) reps (y, h)
# define rrep(i,n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i,n) for(int i=((int)(n)); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define step(n) rep(_, n)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) ((int)(x).size())
# define contains(x,key) ((x).find(key) != (x).end())
# define cauto const auto
# define FI first
# define SE second
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using mii = map<int, int>;
using msi = map<string, int>;
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T> istream& operator>>(istream& is, vector<vector<T>>& v) { for(auto& x : v) for (auto& y : x) is >> y; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.FI >> p.SE; }
template<class T> string join(const vector<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vector<vector<T>>& v){ rep (i, len(v)) { if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); } return os; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; print(args...);}
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){cerr << v; if(sizeof...(args))cerr << " "; eprint(args...);}
template<class T, class U> ostream& operator<<(ostream& os, const pair<T,U>& p){ cout << p.FI << " " << p.SE; return os; }
template<class T> inline void Unique(T& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
template<class T> inline constexpr bool chmax(T &a, T b) { return a < b && (a = b, true); }
template<class T> inline constexpr bool chmin(T &a, T b) { return a > b && (a = b, true); }
constexpr long long gcd(long long a, long long b) { while(b){ long long A = a; (a = b), (b = A % b); } return a; }
constexpr long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
constexpr int ctoi(const char c) { return ('0' <= c && c <= '9') ? (c - '0') : -1; }
const char* YesNo(bool b) { return b ? "Yes" : "No"; }
const char* YESNO(bool b) { return b ? "YES" : "NO"; }
const char* yesno(bool b) { return b ? "yes" : "no"; }
const char* yn(bool b) { return YesNo(b); }

class ll_ext {
public:
  using ll = long long int;

  enum tag_t {
    finite_tag,
    p_inf_tag,
    n_inf_tag,
  };

  // static constexpr bool infinity_same = true;

  ll v;
  tag_t t;

private:
  static constexpr ll ll_min = std::numeric_limits<ll>::min();
  static constexpr ll ll_max = std::numeric_limits<ll>::max();

  static constexpr bool add_overflow_base(const ll a, const ll b, ll *res) {
    if (a >= 0) {
      if (b >= 0) {
        if (a > ll_max - b) {
          return true;
        }
      }
    } else {
      if (b < 0) {
        if (a < ll_min - b) {
          return true;
        }
      }
    }
    *res = a + b;
    return false;
  }

  static constexpr bool add_overflow(const ll a, const ll b, ll *res) {
#ifdef __GNUC__
    return __builtin_saddll_overflow(a, b, res);
#else
    return add_overflow_base(a, b, res);
#endif
  }

  static constexpr bool sub_overflow_base(const ll a, const ll b, ll *res) {
    if (a >= 0) {
      if (b < 0) {
        if (a > ll_max + b) {
          return true;
        }
      }
    } else {
      if (b >= 0) {
        if (a < ll_min + b) {
          return true;
        }
      }
    }
    *res = a - b;
    return false;
  }

  static constexpr bool sub_overflow(const ll a, const ll b, ll *res) {
#ifdef __GNUC__
    return __builtin_ssubll_overflow(a, b, res);
#else
    return sub_overflow_base(a, b, res);
#endif
  }

  static constexpr bool mul_overflow_base(const ll a, const ll b, ll *res) {
    if (a > 0) {
      if (b > 0) {
        if (a > ll_max / b) {
          return true;
        }
      } else if (b < 0) {
        if (b < ll_min / a) {
          return true;
        }
      }
    } else if (a < 0) {
      if (b > 0) {
        if (a < ll_min / b) {
          return true;
        }
      } else if (b < 0) {
        if (a < ll_max / b) {
          return true;
        }
      }
    }
    *res = a * b;
    return false;
  }

  static constexpr bool mul_overflow(const ll a, const ll b, ll *res) {
#ifdef __GNUC__
    return __builtin_smulll_overflow(a, b, res);
#else
    return mul_overflow_base(a, b, res);
#endif
  }

public:
  static constexpr ll_ext p_infinity() {
    ll_ext ret;
    ret.t = p_inf_tag;
    return ret;
  }
  static constexpr ll_ext n_infinity() {
    ll_ext ret;
    ret.t = n_inf_tag;
    return ret;
  }

  constexpr ll_ext() noexcept : v(0), t(finite_tag) {}
  constexpr ll_ext(const ll x) noexcept : v(x), t(finite_tag) {}

  friend constexpr ll_ext operator+(const ll_ext &l, const ll_ext &r) noexcept {
    switch (l.t) {
    case finite_tag: {
      switch (r.t) {
      case finite_tag: {
        ll x = 0;
        assert(!add_overflow(l.v, r.v, &x) && "overflow: +");
        return x;
      } break;
      case p_inf_tag: {
        return p_infinity();
      } break;
      case n_inf_tag: {
        return n_infinity();
      } break;
      }
    } break;
    case p_inf_tag: {
      switch (r.t) {
      case finite_tag: {
        return p_infinity();
      } break;
      case p_inf_tag: {
        return p_infinity();
      } break;
      case n_inf_tag: {
        assert(false && "p_inf + n_inf");
        return 0;
      } break;
      }
    } break;
    case n_inf_tag: {
      switch (r.t) {
      case finite_tag: {
        return n_infinity();
      } break;
      case p_inf_tag: {
        assert(false && "n_inf + p_inf");
        return 0;
      } break;
      case n_inf_tag: {
        return n_infinity();
      } break;
      }
    }
    }
  }

  friend constexpr ll_ext operator-(const ll_ext &l, const ll_ext &r) noexcept {
    switch (l.t) {
    case finite_tag: {
      switch (r.t) {
      case finite_tag: {
        ll x = 0;
        assert(!sub_overflow(l.v, r.v, &x) && "overflow: -");
        return x;
      } break;
      case p_inf_tag: {
        return n_infinity();
      } break;
      case n_inf_tag: {
        return p_infinity();
      } break;
      }
    } break;
    case p_inf_tag: {
      switch (r.t) {
      case finite_tag: {
        return p_infinity();
      } break;
      case p_inf_tag: {
        assert(false && "p_inf - p_inf");
        return 0;
      } break;
      case n_inf_tag: {
        return p_infinity();
      } break;
      }
    } break;
    case n_inf_tag: {
      switch (r.t) {
      case finite_tag: {
        return n_infinity();
      } break;
      case p_inf_tag: {
        return n_infinity();
      } break;
      case n_inf_tag: {
        assert(false && "n_inf - n_inf");
        return 0;
      } break;
      }
    }
    }
  }

  friend constexpr ll_ext operator*(const ll_ext &l, const ll_ext &r) noexcept {
    switch (l.t) {
    case finite_tag: {
      switch (r.t) {
      case finite_tag: {
        ll x = 0;
        assert(!mul_overflow(l.v, r.v, &x) && "overflow: *");
        return x;
      } break;
      case p_inf_tag: {
        if (l.v > 0) {
          return p_infinity();
        } else if (l.v == 0) {
          return 0;
        } else {
          return n_infinity();
        }
      } break;
      case n_inf_tag: {
        if (l.v > 0) {
          return n_infinity();
        } else if (l.v == 0) {
          return 0;
        } else {
          return p_infinity();
        }
      } break;
      }
    } break;
    case p_inf_tag: {
      switch (r.t) {
      case finite_tag: {
        if (r.v > 0) {
          return p_infinity();
        } else if (r.v == 0) {
          return 0;
        } else {
          return n_infinity();
        }
      } break;
      case p_inf_tag: {
        return p_infinity();
      } break;
      case n_inf_tag: {
        return n_infinity();
      } break;
      }
    } break;
    case n_inf_tag: {
      switch (r.t) {
      case finite_tag: {
        if (r.v > 0) {
          return n_infinity();
        } else if (r.v == 0) {
          return 0;
        } else {
          return p_infinity();
        }
      } break;
      case p_inf_tag: {
        return n_infinity();
      } break;
      case n_inf_tag: {
        return p_infinity();
      } break;
      }
    }
    }
  }

  friend constexpr ll_ext operator/(const ll_ext &l, const ll_ext &r) noexcept {
    switch (l.t) {
    case finite_tag: {
      switch (r.t) {
      case finite_tag: {
        assert(r.v != 0 && "division by zero: /");
        assert(!(l.v == ll_min && r.v == -1) && "overflow: /");
        return l.v / r.v;
      } break;
      case p_inf_tag: {
        return 0;
      } break;
      case n_inf_tag: {
        return 0;
      } break;
      }
    } break;
    case p_inf_tag: {
      switch (r.t) {
      case finite_tag: {
        if (r.v > 0) {
          return p_infinity();
        } else if (r.v == 0) {
          assert(false && "division by zero: /");
        } else {
          return n_infinity();
        }
      } break;
      case p_inf_tag: {
        assert(false && "p_inf / p_inf");
        return 0;
      } break;
      case n_inf_tag: {
        assert(false && "p_inf / n_inf");
        return 0;
      } break;
      }
    } break;
    case n_inf_tag: {
      switch (r.t) {
      case finite_tag: {
        if (r.v > 0) {
          return n_infinity();
        } else if (r.v == 0) {
          assert(false && "division by zero: /");
        } else {
          return p_infinity();
        }
      } break;
      case p_inf_tag: {
        assert(false && "n_inf / p_inf");
        return 0;
      } break;
      case n_inf_tag: {
        assert(false && "n_inf / n_inf");
        return 0;
      } break;
      }
    }
    }
  }

  friend constexpr ll_ext operator%(const ll_ext &l, const ll_ext &r) noexcept {
    switch (l.t) {
    case finite_tag: {
      switch (r.t) {
      case finite_tag: {
        assert(r.v != 0 && "division by zero: %");
        assert(!(l.v == ll_min && r.v == -1) && "overflow: %");
        return l.v % r.v;
      } break;
      case p_inf_tag: {
        return l.v;
      } break;
      case n_inf_tag: {
        return l.v;
      } break;
      }
    } break;
    case p_inf_tag: {
      switch (r.t) {
      case finite_tag: {
        assert(false && "p_inf % finite");
        return 0;
      } break;
      case p_inf_tag: {
        assert(false && "p_inf % p_inf");
        return 0;
      } break;
      case n_inf_tag: {
        assert(false && "p_inf % n_inf");
        return 0;
      } break;
      }
    } break;
    case n_inf_tag: {
      switch (r.t) {
      case finite_tag: {
        assert(false && "n_inf % finite");
        return 0;
      } break;
      case p_inf_tag: {
        assert(false && "n_inf % p_inf");
        return 0;
      } break;
      case n_inf_tag: {
        assert(false && "n_inf % n_inf");
        return 0;
      } break;
      }
    }
    }
  }

  constexpr ll_ext operator+() const noexcept { return *this; }

  constexpr ll_ext operator-() const noexcept {
    switch (t) {
    case finite_tag: {
      assert(v != ll_min && "overflow: unary -");
      return -v;
    } break;
    case p_inf_tag: {
      return n_infinity();
    } break;
    case n_inf_tag: {
      return p_infinity();
    } break;
    }
  }

  constexpr ll_ext &operator+=(const ll_ext &r) noexcept {
    return *this = *this + r;
  }

  constexpr ll_ext &operator-=(const ll_ext &r) noexcept {
    return *this = *this - r;
  }

  constexpr ll_ext &operator*=(const ll_ext &r) noexcept {
    return *this = *this * r;
  }

  constexpr ll_ext &operator/=(const ll_ext &r) noexcept {
    return *this = *this / r;
  }

  constexpr ll_ext &operator%=(const ll_ext &r) noexcept {
    return *this = *this % r;
  }

  friend constexpr bool operator==(const ll_ext &l, const ll_ext &r) noexcept {
    return l.v == r.v && l.t == r.t;
  }

  friend constexpr bool operator!=(const ll_ext &l, const ll_ext &r) noexcept {
    return !(l == r);
  }

  friend constexpr bool operator<(const ll_ext &l, const ll_ext &r) noexcept {
    switch (l.t) {
    case finite_tag: {
      switch (r.t) {
      case finite_tag: {
        return l.v < r.v;
      } break;
      case p_inf_tag: {
        return true;
      } break;
      case n_inf_tag: {
        return false;
      } break;
      }
    } break;
    case p_inf_tag: {
      switch (r.t) {
      case finite_tag: {
        return false;
      } break;
      case p_inf_tag: {
        // assert(false && "p_inf < p_inf");
        return false;
      } break;
      case n_inf_tag: {
        return false;
      } break;
      }
    } break;
    case n_inf_tag: {
      switch (r.t) {
      case finite_tag: {
        return true;
      } break;
      case p_inf_tag: {
        return true;
      } break;
      case n_inf_tag: {
        // assert(false && "n_inf < n_inf");
        return false;
      } break;
      }
    }
    }
  }

  friend constexpr bool operator<=(const ll_ext &l, const ll_ext &r) noexcept {
    return !(r < l);
  }

  friend constexpr bool operator>(const ll_ext &l, const ll_ext &r) noexcept {
    return r < l;
  }

  friend constexpr bool operator>=(const ll_ext &l, const ll_ext &r) noexcept {
    return !(l < r);
  }

  friend std::istream &operator>>(std::istream &is, ll_ext &x) {
    x.t = finite_tag;
    is >> x.v;
    return is;
  }

  friend std::ostream &operator<<(std::ostream &os, const ll_ext &x) {
    switch (x.t) {
    case finite_tag: {
      os << x.v;
      return os;
    } break;
    case p_inf_tag: {
      assert(false && "ostream << p_inf");
      return os;
    } break;
    case n_inf_tag: {
      assert(false && "ostream << n_inf");
      return os;
    } break;
    }
  }
};

signed main() {
    int n; cin >> n;
    vector<ll_ext> a(n); cin >> a;

    ll_ext ans = 1;
    rep (i, n) {
        ans *= a[i];
        if (ans.finite_tag == ll_ext::finite_tag) {
            print(-1);
            return 0;
        }
    }

    if (ans > 1000000000000000000LL) print(-1);
    else print(ans);

    return 0;
}
