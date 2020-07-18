# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define MSG(x) std::cout << #x << " : " << x << "\n";
using namespace std;
using lint = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int N = 0;
    cin >> N;
    vector<int> a(N+1);
    vector<int> box(N+1);
    reps (i, N)
    { 
        cin >> a[i];
        box[i] = -1;
    }

    box[N] = a[N];

    int M = 0;
    vector<int> b;

    int t = 1;
    rreps (i, N)
    {
        int tmp = a[i];
        for (int k = 2*i; k <= N; k += i)
        {
            tmp ^= box[k];
        }
        
        box[i] = tmp;
    }

    for (int i = 0; i < box.size(); ++i)
    {
        if (box[i])
        {
            M++;
            b.pb(i);
        }
    }

    cout << M << endl;
    rep (i, SZ(b))
    {
        if (i != SZ(b) - 1)
            cout << b[i] << " ";
        else
            cout << b[i] << endl;
    }
    

    return 0;
}
