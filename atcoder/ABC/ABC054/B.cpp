# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(M);
    rep (i, N) { cin >> A[i]; }
    rep (i, M) { cin >> B[i]; }

    rep (ay, N - M + 1)
    {
        rep (ax, N - M + 1)
        {
            int cnt = 0;
            rep (by, M)
            {
                rep (bx, M)
                {
                    if (A[ay+by][ax+bx] == B[by][bx])
                    {
                        cnt++;
                    }
                }
            }
            if (cnt == M*M)
            {
                cout << "Yes" << "\n";
                return 0;
            }
        }
    }

    cout << "No" << "\n";

    return 0;
}
