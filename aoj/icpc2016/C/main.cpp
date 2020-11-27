# include <iostream>
# include <vector>
# define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
cd 
static const int ANS_MAX = 7368791;

void Main(int m, int n) {
    vector<bool> mat(ANS_MAX + 1, false);
    int cnt = 0;
    for (int i = m; cnt < n; ++i) {
        if (mat[i] == true) continue;
        else {
            cnt++;
            for (int k = i; k <= ANS_MAX; k += i) mat[k] = true;
        }
    }

    int ans = 0;
    for (int i = m; i <= ANS_MAX; ++i) {
        if (mat[i]) ans++;
        else break;
    }
    cout << m + ans << endl;
}

int main() {
    while (true) {
        int m, n;
        cin >> m >> n;
        if (m == 0 and n == 0) break;
        Main(m, n);
    }
    return 0;
}