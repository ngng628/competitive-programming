# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;

static const int MAX_ROW = 10;
static const int MAX_COL = 10;

struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL>& operator [] (int i) {return val[i];}
};

int GaussJordan(BitMatrix &A, bool is_extended) {
    int rank = 0;
    for (int col = 0; col < A.W; ++col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = rank; row < A.H; ++row) {
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);
        for (int row = 0; row < A.H; ++row) {
            if (row != rank && A[row][col]) A[row] ^= A[rank];
        }
        ++rank;
    }
    return rank;
}

int main() {
    int N, M; cin >> N >> M;
    BitMatrix A(M, N);
    rep (i, M) {
        int k; cin >> k;
        rep (j, k) {
            int s; cin >> s;
            s--;
            A[i][s] = 1;
        }
    }
    vector<int> p(M); rep (i, M) cin >> p[i];

    int m = A.H, n = A.W;
    BitMatrix mat(M, N + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) mat[i][j] = A[i][j];
        mat[i][n] = p[i];
    }
    int r = GaussJordan(mat, true);

	int ans = 1;  
    for (int row = r; row < M; ++row) if (mat[row][n]) ans = 0;
    
    rep (i, N - r) ans *= 2;
    cout << ans << endl;
    
    return 0;
}
