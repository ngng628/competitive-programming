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

long double N, K;

int main()
{
    cin >> N >> K;
    if (N < K)
    {
        long double sum = 0.0;
        const long double log2K = log2(K);
        for (int i = 1; i <= N; ++i)
        {
            cout << pow((long double)0.5, (long double)ceil(log2K - log2(i))) << endl;
            sum += pow((long double)0.5, (long double)ceil(log2K - log2(i)));
        }
        sum = sum / N;

        cout << std::setprecision(13) << sum << endl;
    }
    else
    {
        long double sum = 0.0;
        const long double log2K = log2(K);
        for (int i = 1; i <= K - 1; ++i)
        {
            sum += pow((long double)0.5, (long double)ceil(log2K - log2(i)));
        }
        sum = sum / N;
        sum += (long double)(N - K + 1) / N;

        cout << std::setprecision(13) << sum << endl;

    }


    return 0;
}
