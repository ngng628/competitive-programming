# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define float Float
# define overload3(_1,_2,_3,name,...) name
# define _step(n) _rep(_,n)
# define _rep(i,n) _repr(i,0,n)
# define _repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define rep(...) overload3(__VA_ARGS__, _repr, _rep, _step)(__VA_ARGS__)
# define _reps(i,n) _reprs(i,1,n)
# define _reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define reps(...) overload3(__VA_ARGS__, _reprs, _reps)(__VA_ARGS__)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
# define all(v) std::begin(v), std::end(v)
# define rall(v) std::rbegin(v), std::rend(v)
# define pb push_back
# define eb emplace_back
# define len(v) (int)std::size(v)
# define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
using Int = long long;
using Float = long double;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
constexpr int oo = (1LL<<62)-(1LL<<31);
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
# endif  // ngng628_library

template <class Type>
struct Matrix {
   // コンストラクタ
   Matrix() : m(vec<vec<Type>>()) {}
   Matrix(int n) : m(vec<vec<Type>>(n, vec<Type>(n))) {}
   Matrix(int h, int w) : m(vec<vec<Type>>(h, vec<Type>(w, 0))) {}
   Matrix(int h, int w, Type d) : m(vec<vec<Type>>(h, vec<Type>(w, d))){}
   Matrix(const vec<vec<Type>>& _m) : m(_m){}

   // 単位行列
   const static Matrix Identity(const int n) {
      Matrix mat(n);
      rep (i, n) mat[i][i] = 1;
      return mat;
   }

   // 要素アクセス
   vec<Type> operator[](const int i) const { return m[i]; }
   vec<Type>& operator[](const int i) { return m[i]; }
   Type operator ()(const int i, const int j) const { return m[i][j]; }
   Type& operator ()(const int i, const int j) { return m[i][j]; }

   // ゲッター
   [[nodiscard]] constexpr int n_rows() const { return len(m); }
   [[nodiscard]] constexpr int n_cols() const { return len(m[0]); }

   // 行・列の拡張
   void resize(const int h, const int w) { m.resize(h, w, Type()); }
   void push_back_row(const vec<Type>& v) { m.push_back(v); }
   void push_back_col(const vec<Type>& v) { rep (i, n_rows()) m[i].push_back(v[i]); }
   void pop_back_row() { m.pop_back(); }
   void pop_back_col() { rep (i, n_rows()) m[i].pop_back(); }

   // 四則演算とべき乗
   Matrix& operator +=(const Matrix& other) {
      const int r = n_rows();
      const int c = n_cols();
      assert(r == other.n_rows() and c == other.n_cols());
      rep (i, r) rep (j, c) (*this)(i, j) += other(i, j);
      return *this;
   }
   Matrix& operator -=(const Matrix& other) {
      const int r = n_rows();
      const int c = n_cols();
      assert(r == other.n_rows() and c == other.n_cols());
      rep (i, r) rep (j, c) (*this)(i, j) -= other(i, j);
      return *this;
   }
   Matrix& operator *=(const Matrix& other) {
      const int r = n_rows(), c = other.n_cols(), p = n_cols();
      assert(p == other.n_rows());
      vec<vec<Type>> v(r, vec<Type>(c, Type(0)));
      rep (i, r) rep (j, c) rep (k, p) v[i][j] = (v[i][j] + (*this)(i, k) * other(k, j));
      m.swap(c);
      return *this;
   }
   Matrix& operator ^=(int n) {
      Matrix res = Matrix::Identity(n_rows());
      while (n > 0) {
         if (n & 1) res *= *this;
         *this *= *this;
         n >>= 1LL;
      }
      swap(m, res);
      return *this;
   }

   friend Matrix operator +(const Matrix& a, const Matrix& b) { return Matrix(a) += b; }
   friend Matrix operator -(const Matrix& a, const Matrix& b) { return Matrix(a) -= b; }
   friend Matrix operator *(const Matrix& a, const Matrix& b) { return Matrix(a) *= b; }
   friend Matrix operator ^(const Matrix& a, const int n) { return Matrix(a) ^= n; }

   // スカラー倍
   Matrix& operator *=(Type k) { rep (i, n_rows()) rep (j, n_cols()) (*this)(i, j) *= k; return *this; }
   Matrix& operator /=(Type k) { rep (i, n_rows()) rep (j, n_cols()) (*this)(i, j) /= k; return *this; }
   friend Matrix operator *(const Matrix& a, const int b) { return Matrix(a) *= b; }
   friend Matrix operator *(const int a, const Matrix& b) { return Matrix(b) *= a; }
   friend Matrix operator /(const Matrix& a, const int b) { return Matrix(a) /= b; }

   // 単項演算子
   Matrix operator -() const { Matrix mat; rep (i, n_rows()) rep (j, n_cols()) mat(i, j) = -*this(i, j); return mat; }
   Matrix operator +() const { return *this; }

   // 行列式 （Type型が体であるときのみ対応）
   Type det() const {
      const int n = n_rows();
      assert(n == n_cols());
      Matrix mat(*this);
      Type ret = 1;
      rep (i, n) {
         int idx = -1;
         rep (j, i, n) if (mat(j, i) != Type(0)) idx = j;
         if (idx == -1) return 0;
         if (i != idx) {
            ret *= -1;
            swap(mat[i], mat[idx]);
         }
         ret *= mat(i, i);
         Type v = mat(i, i);
         rep (j, n) mat(i, j) /= v;
         rep (j, i + 1, n) {
            Type a = mat(j, i);
            rep (k, n) mat(j, k) -= mat(i, k) * a;
         }
      }
      return ret;
   }
   friend Type det(const Matrix& mat) { return mat.det(); }

   // 逆行列
   Matrix inv() const {
      Matrix mat = *this;
      const int n = mat.n_rows();
      assert(n == mat.n_cols());
      Matrix res = Matrix::Identity(n);
      int rank = 0;
      rep (j, n) {
         int pivot = -1;
         Type mx = 0;
         rep (i, rank, n) if (chmax(mx, abs(mat(i, j)))) pivot = i;
         if (pivot == -1) continue;

         swap(mat[pivot], mat[rank]);
         swap(res[pivot], res[rank]);

         auto fac = mat(rank, j);
         rep (k, n) {
            mat(rank, k) /= fac;
            res(rank, k) /= fac;
         }

         rep (i, n) {
            if (i != rank and abs(mat(i, j)) > Type(0)) {
               auto fac = mat(i, j);
               rep (k, n) {
                  mat(i, k) -= mat(rank, k) * fac;
                  res(i, k) -= res(rank, k) * fac;
               }
            }
         }
         ++rank;
      }
      return res;
   }
   friend Type inv(const Matrix& mat) { return mat.inv(); }

   // 跡
   Type tr() const {
      const int n = n_rows();
      assert(n == n_cols());
      int res = 0;
      rep (i, n) res += (*this)(i, i);
      return res;
   }
   friend Type tr(const Matrix& mat) { return mat.tr(); }

   Matrix T() const {
      const int h = n_rows(), w = n_cols();
      Matrix res(w, h);
      rep (i, h) rep (j, w) res(j, i) = (*this)(i, j);
      return res;
   }

   // 対角行列
   friend Matrix diag(const vec<Type>& v) {
      const int n = len(v);
      Matrix mat(n, n);
      rep (i, n) mat[i][i] = v[i];
      return mat;
   }

   // 掃き出し法
   //! @param is_extended 拡大係数行列か
   friend int sweep(Matrix& mat, bool is_extended = false) {
      int r = mat.n_rows(), c = mat.n_cols();
      int rank = 0;
      rep (j, c) {
         if (is_extended and j == c - 1) break;

         int pivot = -1;
         Type mx = 0;
         rep (i, rank, r) if (chmax(mx, abs(mat(i, j)))) pivot = i;
         if (pivot == -1) continue;

         swap(mat[pivot], mat[rank]);

         auto fac = mat(rank, j);
         rep (k, c) mat(rank, k) /= fac;

         rep (i, r) {
            if (i != rank and abs(mat(i, j)) > Type(0)) {
               auto fac = mat(i, j);
               rep (k, c) mat(i, k) -= mat(rank, k) * fac;
            }
         }
         ++rank;
      }
      return rank;
   }

   // 入出力
   friend istream& operator >>(istream& is, Matrix& mat){ rep (i, mat.n_rows()) rep (j, mat.n_cols()) is >> mat(i, j); return is; }
   friend ostream& operator <<(ostream& os, const Matrix& mat){ rep (i, mat.n_rows()) rep (j, mat.n_cols()) os << mat(i, j) << " \n"[j == mat.n_cols() - 1]; return os; }

private:
   vec<vec<Type>> m;
};

bool Main() {
   int n;
   cin >> n;
   cin.ignore();
   if (!n) return false;
   vec<string> s(n);
   for (auto& e : s) getline(cin, e);

   // struct Parser {
   //
   // };

   return true;
}

int32_t main() {
   Matrix<int> m({{1, 2, 3}, {4, 5, 6}});
   cout << m << endl;
   cout << m.T() << endl;
   // int n;
   // cin >> n;
   // cin.ignore();
   // vec<string> s(n);
   // rep (i, n) getline(cin, s[i]);


}