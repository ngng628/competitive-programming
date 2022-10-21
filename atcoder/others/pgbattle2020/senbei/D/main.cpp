#include <iostream>
#include <map>
#include <vector>
using namespace std;

const long long MOD = (long long)(1e9) + 7cd ;
long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

template<class T> struct Matrix {
    vector<vector<T> > val;
    Matrix(int n = 1, int m = 1) {val.clear(); val.resize(n, vector<T>(m));}
    Matrix(int n, int m, T x) {val.clear(); val.resize(n, vector<T>(m, x));}
    void init(int n, int m, T x = 0) {val.clear(); val.resize(n, vector<T>(m, x));}
    void resize(int n, int m, T x = 0) {val.resize(n); for (int i = 0; i < n; ++i) val[i].resize(m, x);}
    int size() {return val.size();}
    inline vector<T>& operator [] (int i) {return val[i];}
    friend ostream& operator << (ostream& s, Matrix<T> M) {s << endl;
        for (int i = 0; i < M.val.size(); ++i) s << M[i] << endl; return s;}
};

template<class T> Matrix<T> operator * (Matrix<T> A, Matrix<T> B) {
    Matrix<T> R(A.size(), B[0].size());
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < B[0].size(); ++j)
            for (int k = 0; k < B.size(); ++k)
                R[i][j] = mod(R[i][j] + A[i][k] * B[k][j], MOD);
    return R;
}

template<class T> vector<T> operator * (Matrix<T> A, vector<T> B) {
    vector<T> v(A.size());
    for (int i = 0; i < A.size(); ++i)
        for (int k = 0; k < B.size(); ++k)
            v[i] = (v[i] + A[i][k] * B[k]) % MOD;
    return v;
}

template<class T> Matrix<T> pow(Matrix<T> A, long long n) {
    Matrix<T> R(A.size(), A.size());
    for (int i = 0; i < A.size(); ++i) R[i][i] = 1;
    while (n > 0) {
        if (n & 1) R = R * A;
        A = A * A;
        n >>= 1;
    }
    return R;
}

int H, W;

map<int,int> patterns;
map<pair<int,int>, int> step;

/* hamidashi + white-black of next line -> patterns of new hamidasis */
int nex(int hamidashi, int nextline) {
    int pattern = 0;
    if ((hamidashi & nextline) != hamidashi) return 0; // empty set
    nextline ^= hamidashi;
    for (int nexthamidashi = 0; nexthamidashi < (1<<H); ++nexthamidashi) {
        if ((nexthamidashi & nextline) != nexthamidashi) continue;
        
        // 左からはみ出されているわけでも、右にはみ出しているわけでもない部分が 2 マスずつ塗れるか
        int remline = nextline ^ nexthamidashi;
        int con = 0;
        bool ok = true;
        for (int i = 0; i < H; ++i) {
            if (remline & (1<<i)) ++con;
            else {
                if (con & 1) ok = false;
                con = 0;
            }
        }
        if (con & 1) ok = false;
        if (!ok) continue;
        
        pattern |= (1<<nexthamidashi);
    }
    return pattern;
}

/* enumerate all paterns */
void dfs(int p) {
    if (patterns.count(p)) return;
    int iter = (int)patterns.size();
    patterns[p] = iter;
    
    // enumerate white-black of nextline
    for (int nextline = 0; nextline < (1<<H); ++nextline) {
        int np = 0;
        for (int hamidashi = 0; hamidashi < (1<<H); ++hamidashi) {
            if (p & (1<<hamidashi)) {
                np |= nex(hamidashi, nextline);
            }
        }
        step[make_pair(p, np)]++;
        dfs(np);
    }
}

int main() {
    cin >> H >> W;
	patterns.clear(); step.clear();
    dfs(1); // only { no hamidasi }
    
    int n = (int)patterns.size();
    Matrix<long long> M(n, n, 0);
    for (map<int,int>::iterator i = patterns.begin(); i != patterns.end(); ++i) {
	  for (map<int,int>::iterator j = patterns.begin(); j != patterns.end(); ++j) {
		M[i->second][j->second] = step[make_pair(j->first, i->first)];
	  }
	}
    Matrix<long long> P = pow(M, W);
    vector<long long> ini(n, 0); ini[0] = 1;
    vector<long long> R = P*ini;
    long long res = 0;
    for (map<int,int>::iterator it = patterns.begin(); it != patterns.end(); ++it) {
        if (it->first & (1<<0)) res += R[it->second];
    }
    cout << res % MOD << endl;
}