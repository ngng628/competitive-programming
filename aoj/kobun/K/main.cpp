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
# define reps(...) overload3(__VA_ARGS__, _reps, _reprs)(__VA_ARGS__)
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

struct Fraction {
   // コンストラクタ
   Fraction() : m_num(0), m_den(1) {}
   Fraction(int n) : m_num(n), m_den(1) {}
   Fraction(int n, int d) : m_num(n), m_den(d) { reduce(); m_num *= abs(m_den) / m_den; m_den = abs(m_den); }
   Fraction(const string& s) {
      auto pos = s.find_first_of('.');
      if (pos == string::npos) *this = Fraction(stoll(s));
      else {
         int d = 1;
         int ten = 10;
         for (int m = len(s) - 1 - pos; m > 0; m >>= 1) {
            if (m & 1) d *= ten;
            ten *= ten;
         }
         int n = 0;
         for (char c : s) if (c != '.') n = 10*n + c - '0';
         *this = Fraction(n, d);
      }
   }

   // 代入操作
   Fraction& operator =(int n) { m_num = n, m_den = 1; return *this; }
   Fraction& assign(int n, int d) { m_num = n, m_den = d; return *this; }

   // ゲッター
   constexpr int num() const { return m_num; }
   constexpr int den() const { return m_den; }
   Fraction inv() const { return Fraction(m_den, m_num); }

   // 分数同士の四則演算
   Fraction& operator +=(const Fraction& f){ int l = m_den != 0 and f.m_den != 0 ? lcm(m_den, f.m_den) : 1; *this = Fraction(m_num*(l / m_den) + f.m_num*(l / f.m_den), l); return *this; }
   Fraction& operator -=(const Fraction& f){ int l = m_den != 0 and f.m_den != 0 ? lcm(m_den, f.m_den) : 1; *this = Fraction(m_num*(l / m_den) - f.m_num*(l / f.m_den), l); return *this; }
   Fraction& operator *=(const Fraction& f){ int g1 = gcd(m_den, f.m_num), g2 = gcd(m_num, f.m_den); *this = Fraction((m_num / g2)*(f.m_num / g1), (m_den / g1)*(f.m_den / g2)); return *this; }
   Fraction& operator /=(const Fraction& f){ int g1 = gcd(m_den, f.m_den), g2 = gcd(m_num, f.m_num); *this = Fraction((m_num / g2)*(f.m_den / g1), (m_den / g1)*(f.m_num / g2)); return *this; }

   friend Fraction operator +(const Fraction& a, const Fraction& b) { return Fraction(a) += b; }
   friend Fraction operator -(const Fraction& a, const Fraction& b) { return Fraction(a) -= b; }
   friend Fraction operator *(const Fraction& a, const Fraction& b) { return Fraction(a) *= b; }
   friend Fraction operator /(const Fraction& a, const Fraction& b) { return Fraction(a) /= b; }

   // 整数型との四則演算
   Fraction& operator +=(const int n){ *this = Fraction(m_num + m_den*n, m_den); return *this; }
   Fraction& operator -=(const int n){ *this = Fraction(m_num - m_den*n, m_den); return *this; }
   Fraction& operator *=(const int n){ *this = Fraction(m_num*n, m_den); return *this; }
   Fraction& operator /=(const int n){ *this = Fraction(m_num, m_den*n); return *this; }

   friend Fraction operator +(const int n, const Fraction& f) { return Fraction(n) += f; }
   friend Fraction operator -(const int n, const Fraction& f) { return Fraction(n) -= f; }
   friend Fraction operator *(const int n, const Fraction& f) { return Fraction(n) *= f; }
   friend Fraction operator /(const int n, const Fraction& f) { return Fraction(n) /= f; }

   friend Fraction operator +(const Fraction& f, const int n) { return Fraction(f) += Fraction(n); }
   friend Fraction operator -(const Fraction& f, const int n) { return Fraction(f) -= Fraction(n); }
   friend Fraction operator *(const Fraction& f, const int n) { return Fraction(f) *= Fraction(n); }
   friend Fraction operator /(const Fraction& f, const int n) { return Fraction(f) /= Fraction(n); }


   // 単項演算子
   Fraction operator -() const { return Fraction(-m_num, m_den); }
   Fraction operator +() const { return *this; }

   // インクリメントとデクリメント
   const Fraction& operator ++() { *this = Fraction(m_num + m_den, m_den); return *this; }
   const Fraction& operator --() { *this = Fraction(m_num - m_den, m_den); return *this; }

   Fraction operator ++(int32_t) { Fraction res = *this; ++*this; return res; }
   Fraction operator --(int32_t) { Fraction res = *this; --*this; return res; }

   // 否定演算
   bool operator !() const noexcept { return !m_num; }

   // 比較演算
   friend bool operator <(const Fraction& a, const Fraction& b) { return a.m_num * b.m_den < a.m_den * b.m_num; }
   friend bool operator >(const Fraction& a, const Fraction& b) { return b < a; }
   friend bool operator <=(const Fraction& a, const Fraction& b) { return !(a > b); }
   friend bool operator >=(const Fraction& a, const Fraction& b) { return !(a < b); }

   friend bool operator ==(const Fraction& a, const Fraction& b) { return a.m_num == b.m_num and a.m_den == b.m_den; }
   friend bool operator !=(const Fraction& a, const Fraction& b) { return !(a == b); }

   // 絶対値
   friend Fraction abs(const Fraction& f) { return Fraction(abs(f.m_num), f.m_den); }

   // 入出力
   friend istream& operator >>(istream& is, Fraction& f){ int n, d; f = Fraction(n, d); return is; }
   // friend ostream& operator <<(ostream& os, const Fraction& f){ return os << "frac{" << f.num() << "}{" << f.den() << "}"; }
   friend ostream& operator <<(ostream& os, const Fraction& f){ 
      if (f.den() == 1) return os << f.num();
      else return os << "(" << f.num() << "/" << f.den() << ")";
   }

   // キャスト変換
   operator double() const { return double(m_num) / m_den; }
   operator float() const { return double(m_num) / m_den; }
   operator int() const { return m_num / m_den; }

private:
   int m_num, m_den;
   bool reduce() {
      if (m_num == 0) {
         m_den = 1;
         return false;
      }
      else if (m_den == 0) {
         m_num = 1;
         return false;
      }
      else {
         int g = gcd(m_num, m_den);
         m_num /= g;
         m_den /= g;
         return g != 1;
      }
   }
};

template <class T>
struct Matrix {
   // コンストラクタ
   Matrix() : m(vec<vec<T>>()) {}
   Matrix(int n) : m(vec<vec<T>>(n, vec<T>(n))) {}
   Matrix(int h, int w) : m(vec<vec<T>>(h, vec<T>(w, 0))) {}
   Matrix(int h, int w, T d) : m(vec<vec<T>>(h, vec<T>(w, d))){}
   Matrix(const vec<vec<T>>& _m) : m(_m){}

   // 単位行列
   const static Matrix Identity(const int n) {
      Matrix mat(n);
      rep (i, n) mat[i][i] = T(1);
      return mat;
   }

   // 要素アクセス
   vec<T> operator[](const int i) const { return m[i]; }
   vec<T>& operator[](const int i) { return m[i]; }
   T operator ()(const int i, const int j) const { return m[i][j]; }
   T& operator ()(const int i, const int j) { return m[i][j]; }

   // ゲッター
   [[nodiscard]] constexpr int n_rows() const { return len(m); }
   [[nodiscard]] constexpr int n_cols() const { return len(m[0]); }

   // 行・列の拡張
   void resize(const int h, const int w) { m.resize(h, w, T()); }
   void push_back_row(const vec<T>& v) { m.push_back(v); }
   void push_back_col(const vec<T>& v) { rep (i, n_rows()) m[i].push_back(v[i]); }
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
      vec<vec<T>> v(r, vec<T>(c, T(0)));
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
   Matrix& operator *=(T k) { rep (i, n_rows()) rep (j, n_cols()) (*this)(i, j) *= k; return *this; }
   Matrix& operator /=(T k) { rep (i, n_rows()) rep (j, n_cols()) (*this)(i, j) /= k; return *this; }
   friend Matrix operator *(const Matrix& a, const int b) { return Matrix(a) *= b; }
   friend Matrix operator *(const int a, const Matrix& b) { return Matrix(b) *= a; }
   friend Matrix operator /(const Matrix& a, const int b) { return Matrix(a) /= b; }

   // 単項演算子
   Matrix operator -() const { Matrix mat; rep (i, n_rows()) rep (j, n_cols()) mat(i, j) = -*this(i, j); return mat; }
   Matrix operator +() const { return *this; }

   // 行列式 （T型が体であるときのみ対応）
   T det() {
      assert(n_rows() == n_cols());
      Matrix mat(*this);
      T ret = 1;
      rep (i, n_cols()) {
         int idx = -1;
         rep (j, i, n_cols()) {
            if (mat(j, i) != T(0)) idx = j;
         }
         if (idx == -1) return 0;
         if (i != idx) {
            ret *= -1;
            swap(mat[i], mat[idx]);
         }
         ret *= mat(i, i);
         T v = mat(i, i);
         rep (j, n_cols()) mat(i, j) /= v;
         rep (j, i + 1, n_cols()) {
            T a = mat(j, i);
            rep (k, n_cols()) mat(j, k) -= mat(i, k) * a;
         }
      }
      return ret;
   }
   friend T det(const Matrix& mat) { return mat.det(); }

   // 逆行列
   Matrix inv() {
      Matrix mat = *this;
      int n = mat.n_rows();
      assert(n == mat.n_cols());
      Matrix res = Matrix::Identity(n);
      int rank = 0;
      rep (j, n) {
         int pivot = -1;
         T mx = 0;
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
            if (i != rank and abs(mat(i, j)) > T(0)) {
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
   friend T inv(const Matrix& mat) { return mat.inv(); }

   // 対角行列
   friend Matrix diag(const vec<T>& v) {
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
         T mx = 0;
         rep (i, rank, r) if (chmax(mx, abs(mat(i, j)))) pivot = i;
         if (pivot == -1) continue;

         swap(mat[pivot], mat[rank]);

         auto fac = mat(rank, j);
         rep (k, c) mat(rank, k) /= fac;

         rep (i, r) {
            if (i != rank and abs(mat(i, j)) > T(0)) {
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
   vec<vec<T>> m;
};

using State = string::const_iterator;
void skip(State& it) { while (isspace(*it)) ++it; }
void skip(State& it, char c) { assert(c == *it); ++it; }
void skip(State& it, const string& s) { for (char c : s) { assert(c == *it); ++it; } }
void skip(State& it, int n) { while (n--) ++it; }
string erase_all_space(string s) { s.erase(remove_if(all(s), [](char c){ return isspace(c); }), s.end()); return s; }
int ctoi(char c) { assert('0' <= c and c <= '9'); return c - '0'; }

bool Main() {
   // ────────────────────────────────
   //  1. 入力
   // ────────────────────────────────
   string s;
   cin >> s;
   s.pop_back();
   if (s.empty()) return false;
   reverse(all(s));

   // ────────────────────────────────
   //  2. 構文解析
   // ────────────────────────────────
   struct Parser {
      string s;
      int n_terms;
      map<string, vec<Fraction>> mp;  // mp['元素記号'][i項目] = 係数
      Parser(string _s) : s(_s), it(s.begin()) {}

      void parse() {
         n_terms = count(all(s), '+') + 2;
         chemical_equation();
      }

   private:
      State it;

      void chemical_equation() {
         molecule_sequence();
      }

      void molecule_sequence() {
         int sgn = 1;
         molecule(sgn, 0, 1);
         int term_index = 1;
         for (; it != s.end();) {
            if (*it == '+') {
               skip(it, '+');
               molecule(sgn, term_index++, 1);
            }
            else if (*it == '>') {
               skip(it, ">-");
               sgn *= -1;
            }
            else {
               molecule(sgn, term_index++, 1);
            }
         }
      }

      void molecule(int sgn, int i, int k) {
         const set<char> delimiters = {'+', '>', '('};
         while (it != s.end() and not delimiters.count(*it)) group(sgn, i, k);
      }

      void group(int sgn, int i, int k) {
         k *= isdigit(*it) ? number() : 1;
         unit_group(sgn, i, k);
      }

      void unit_group(int sgn, int i, int k) {
         if (*it == ')') {
            skip(it, ')');
            molecule(sgn, i, k);
            skip(it, '(');
         }
         else {
            chemical_element(sgn, i, k);
         }
      }

      void chemical_element(int sgn, int i, int k) {
         string elem;
         if (islower(*it)) {
            elem.push_back(*it++);
         }
         elem.push_back(*it++);
         swap(elem[0], elem.back());

         if (not mp.count(elem)) mp[elem].resize(n_terms, 0);
         mp[elem][i] += sgn * k;
      }

      int number() {
         int res = 0;
         int ratio = 1;
         for (; isdigit(*it); ++it) {
            res = res + ratio * ctoi(*it);
            ratio *= 10;
         }
         return res;
      }
   };
   auto parser = Parser(s);
   parser.parse();

   // ────────────────────────────────
   //  3. 拡大係数行列の生成
   // ────────────────────────────────
   Matrix<Fraction> mat(0, parser.n_terms);
   for (auto p : parser.mp) mat.push_back_row(p.second);
   int h = mat.n_rows();
   vec<Fraction> zeros(h, 0);
   mat.push_back_col(zeros);
   int w = mat.n_cols();

   // ────────────────────────────────
   //  4. 掃き出し法をする
   // ────────────────────────────────
   sweep(mat, true);

   // ────────────────────────────────
   //  5. 係数を調整
   // ────────────────────────────────
   int k = 1;
   rep (i, h) k = lcm(k, mat(i, w - 2).den());
   vi ans(w - 1);
   rep (i, w - 2) ans[i] = (-mat(i, w - 2) * k).num();
   ans.back() = k;

   // ────────────────────────────────
   //  6. 答えの出力
   // ────────────────────────────────
   reverse(all(ans));
   cout << ans << endl;

   return true;
}

int32_t main() {
   while (Main());
}