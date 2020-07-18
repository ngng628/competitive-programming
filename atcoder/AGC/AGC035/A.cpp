# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define rsort(x) sort(x, std::greater<Type>())
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define MSG(x) std::cout << #x << " : " << x << "\n";
using namespace std;
using lint = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int N;
vector<int> a;
 
int main()
{
    optimize_cin();
    cin >> N;
    a.resize(N);
    rep (i, N) { cin >> a[i]; }
    bool ans = true;
    
    sort(ALL(a));
 
    if (N == 3)
    {
        for (int i = 0; i < 3; ++i)
        {
            int Xor = a[(i-1+N)%N] ^ a[(i+1)%N];
            if (Xor != a[i])
            {
                ans = false;
                break;
            }
        }
        cout << (ans ? "Yes" : "No") << endl;
        return 0;
    }
    else if (N & 1) // Odd
    {
        
        for (int i = 1; i+1 < N; i+=2)
        {
            if (a[i] != a[i+1])
            {
                cout << "No" << endl;
                return 0;
            }
        }
        if (a[0] == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        return 0;
    }
    else // Even
    {
        for (int i = 0; i+1 < N; i+=2)
        {
            if (a[i] != a[i+1])
            {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        return 0;
    }
 
    cout << "Yes" << endl;
 
    return 0;
}
