# include <bits/stdc++.h>
# define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;

//──────────────────────
//  行列ライブラリ
//──────────────────────
template<typename T>
struct Matrix {
   vector<vector<T>> m;

   Matrix():m(vector<vector<T>>()){}
   Matrix(int h,int w) : m(vector<vector<T>>(h,vector<T>(w))) {}
   Matrix(int h,int w, T d) : m(vector<vector<T>>(h,vector<T>(w,d))){}
   Matrix(const vector<vector<T>>& _m):m(_m){}

   vector<T> operator[](const int i) const {return m[i];}
   vector<T>& operator[](const int i){return m[i];}

   int nrow = m.size();
   int ncol = m[0].size();

   Matrix& operator+=(const Matrix& a){assert(ncol == a.ncol && nrow == a.nrow);rep(i,nrow)rep(j,ncol)m[i][j] += a[i][j]; return *this;}
   Matrix& operator-=(const Matrix& a){assert(ncol == a.ncol && nrow == a.nrow);rep(i,nrow)rep(j,ncol)m[i][j] -= a[i][j]; return *this;} 
   Matrix& operator*=(const Matrix& a){assert(ncol == a.nrow);Matrix<T> m2(nrow, a.ncol, 0);rep(i,nrow)rep(j,a.ncol)rep(k,ncol)m2[i][j] += m[i][k]*a[k][j];ncol = a.ncol;rep(i,nrow)m[i].resize(ncol);rep(i,nrow)rep(j,ncol)m[i][j] = m2[i][j]; return *this;}
   Matrix operator+(const Matrix& a) const { return Matrix(*this) += a;}
   Matrix operator-(const Matrix& a) const { return Matrix(*this) -= a;}
   Matrix operator*(const Matrix& a) const { return Matrix(*this) *= a;}
   bool operator==(const Matrix& a){assert(ncol == a.ncol && nrow == a.nrow);bool flg = true;rep(i,nrow)rep(j,ncol)if(m[i][j] != a[i][j])flg = false; return flg;}

   Matrix& operator+=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] += a;return *this;}
   Matrix& operator-=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] -= a;return *this;}
   Matrix& operator*=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] *= a;return *this;}
   Matrix& operator/=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] /= a;return *this;}
   Matrix operator+(const T& a) const { return Matrix(*this) += a;}
   Matrix operator-(const T& a) const { return Matrix(*this) -= a;}
   Matrix operator*(const T& a) const { return Matrix(*this) *= a;}
   Matrix operator/(const T& a) const { return Matrix(*this) /= a;}
};
using Mat = Matrix<ll>;
const Mat E({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});

//──────────────────────
//  各操作の行列
//──────────────────────
Mat Affin(const int op, const ll p = 0) {
   switch (op) {
   case 1:
      return Mat({{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}});
   case 2:
      return Mat({{0, -1, 0}, {1, 0, 0}, {0, 0, 1}});
   case 3:
      return Mat({{-1, 0, 2*p}, {0, 1, 0}, {0, 0, 1}});
   case 4:
      return Mat({{1, 0, 0}, {0, -1, 2*p}, {0, 0, 1}});
   default:
      return E;
   }
}

int main() {
   //──────────────────────
   //  駒の処理
   //──────────────────────
   int n;
   cin >> n;
   vector<Mat> p(n, Mat(3, 1, 1));
   for  (Mat& e : p) cin >> e[0][0] >> e[1][0];

   //──────────────────────
   //  操作の処理
   //──────────────────────
   int m;
   cin >> m;
   vector<Mat> cumprod(m+1, E);
   cumprod[0] = E;
   rep (i, m) {
      int op;
      cin >> op;
      if (op == 3 or op == 4) {
         ll p;
         cin >> p;
         cumprod[i+1] = (Affin(op, p) * cumprod[i]);
      }
      else {
         cumprod[i+1] = (Affin(op) * cumprod[i]);
      }
   }

   //──────────────────────
   //  クエリの処理
   //──────────────────────
   int q;
   cin >> q;
   while (q--) {
      int a, b;
      cin >> a >> b;
      Mat ans = cumprod[a] * p[b-1];
      cout << ans[0][0] << " " << ans[1][0] << endl;
   }
}
