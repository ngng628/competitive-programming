# include <bits/stdc++.h>
# define ALL(v) (v).begin(), (v).end()
# define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

void Main(const int n, const vector<int> a) {
    int sum = accumulate(ALL(a), 0);
    cout << count_if(ALL(a), [=](int it) {
        return n*it <= sum;
    }) << endl;
}

int main() {
    while (true)
    {
        int n; cin >> n;
        if (n == 0) break;
        vector<int> a(n);
        rep (i, n) { cin >> a[i]; }
        Main(n, a);
    }

    return 0;
}

