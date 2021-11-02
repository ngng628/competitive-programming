#include <bits/stdc++.h>
#ifndef ngng628_library
#define ngng628_library
#define int Int
#define float Float
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define rreps(i, n) for (int i = (n); i > 0; --i)
#define repr(i, b, e) for (int i = (b), i##_len = (e); i < i##_len; ++i)
#define reprs(i, b, e) for (int i = (b), i##_len = (e); i <= i##_len; ++i)
#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)
#define pb push_back
#define eb emplace_back
#define len(v) (int)std::size(v)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
using Int   = long long;
using Float = long double;
template <class T>
using vec = vector<T>;
using pii = pair<int, int>;
using vi  = vec<int>;
using vvi = vec<vi>;
using db  = deque<bool>;
using ddb = deque<db>;

using lint  = int64_t;
using uint  = uint32_t;
using ulint = uint64_t;

template <class T>
using vector2d   = vector<vector<T>>;
constexpr int oo = (1LL << 62) - (1LL << 31);
template <class T>
istream &operator>>(istream &is, vec<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}
template <class T, size_t N>
istream &operator>>(istream &is, array<T, N> &v) {
  for (auto &x : v) is >> x;
  return is;
}
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
  return is >> p.first >> p.second;
}
template <class T>
string join(const vec<T> &v) {
  stringstream s;
  for (T t : v) s << ' ' << t;
  return s.str().substr(1);
}
template <class T>
ostream &operator<<(ostream &os, const vec<T> &v) {
  if (len(v)) os << join(v);
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vec<vec<T>> &v) {
  rep(i, len(v)) if (len(v[i])) os << join(v[i])
                                   << (i - len(v) + 1 ? "\n" : "");
  return os;
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << ' ' << p.second;
}
template <class T, class U, class V>
ostream &operator<<(ostream &os, const tuple<T, U, V> &t) {
  return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
}
void drop() {
  cout << '\n';
  exit(0);
}
template <class T, class... A>
void drop(const T &v, const A &...args) {
  cout << v;
  if (sizeof...(args)) cout << ' ';
  drop(args...);
}
template <class T>
constexpr bool chmax(T &a, const T &b) {
  return a < b && (a = b, true);
}
template <class T>
constexpr bool chmin(T &a, const T &b) {
  return a > b && (a = b, true);
}
#endif  // ngng628_library

// 1-index
struct FenwickTree {
  int n;
  vi bit;
  FenwickTree(int _n) : n(_n), bit(n + 1, 0) {
  }
  FenwickTree(const vi &a) : n(len(a)), bit(len(a) + 1, 0) {
    rep(i, n) add(i + 1, a[i]);
  }

  void add(int i, int x) {
    assert(0 <= i and i <= n);
    if (i == 0) return;
    for (int k = i; k <= n; k += (k & -k)) bit[k] += x;
  }

  void set(int i, int x) {
    assert(0 <= i and i <= n);
    if (i == 0) return;
    int a = get(i);
    for (int k = i; k <= n; k += (k & -k)) bit[k] += x - a;
  }

  int sum(int i) {
    assert(0 <= i and i <= n);
    int s = 0;
    if (i == 0) return s;
    for (int k = i; k > 0; k -= (k & -k)) s += bit[k];
    return s;
  }

  int sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }

  int get(int i) {
    assert(0 <= i and i <= n);
    return i == 0 ? 0 : sum(i) - sum(i - 1);
  }

  int lower_bound(int x) {
    if (x <= 0)
      return 0;
    else {
      int i = 0;
      int r = 1;
      while (r < n) r <<= 1;
      for (int dist = r; dist > 0; dist >>= 1) {
        if (i + dist < n and bit[i + dist] < x) {
          x -= bit[i + dist];
          i += dist;
        }
      }
      return i + 1;
    }
  }
};

//! @brief 配列 v の反転数を求めます。
int inversion_number(const vi &v) {
  const int n = len(v);
  FenwickTree fw(n);
  int ret = 0;
  rep(i, n) {
    ret += i - fw.sum(v[i]);
    fw.add(v[i], 1);
  }
  return ret;
}

template <class T>
bool UpdateMax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  } else {
    return false;
  }
}

template <class T>
bool UpdateMin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  } else {
    return false;
  }
}

template <class T>
void OutVec(const vector<T> &vec) {
  for (int i = 0; i < vec.size() - 1; ++i) {
    cout << vec[i] << " ";
  }
  cout << vec.back() << endl;
}

template <class T>
void OutVec2d(const vector2d<T> &vec) {
  for (auto v : vec) {
    OutVec(v);
  }
}

lint pow5(lint v) {
  return v * v * v * v * v;
}

bool isOk(lint y, lint p, lint q, lint x) {
  double left = log(y) + log(x) - log(p) + log(q) - log(12) + 2 * log(x + 1) +
                log(2 * x * x + 2 * x - 1);
  double right = 99*log(10);
  // cout << "2 * x * x + 2 * x - 1 =" << 2 * x * x + 2 * x - 1 << '\n';
  cout << left << " " << right << endl;
  return left >= right;
}

int32_t main() {
  cout << std::fixed << std::setprecision(16);
  cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  using P = pair<char, int>;

  lint q, p;
  cin >> p >> q;

  lint day = (lint)ceil(pow((double)p / q, 0.2));

  lint y = 0;
  for (int i = day - 1; i >= 0; i--) {
    y += p;
    y -= pow5(i);
  }

  lint max = INT64_MAX / 2;
  lint min = 0;
  lint mid = (max + min) / 2;
  while (max - min > 1) {
    if (isOk(y, p, q, mid)) {
      max = mid;
    } else {
      min = mid;
    }

    mid = (max + min) / 2;
  }

  cout << y << endl;
  cout << max << endl;
  return 0;
}