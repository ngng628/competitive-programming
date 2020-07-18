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

lint gcd(lint a, lint b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a%b);
}

int main()
{
    lint N; cin >> N;
    vector<lint> A(N);
    for (lint i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    if (N == 2)
    {
        if (A[0] > A[1])
        {
            cout << A[0] << "\n";
        }
        else
        {
            cout << A[1] << "\n";
        }
    }
    if (N == 3)
    {
        int buff[3];
        buff[0] = gcd(A[0], A[1]);
        buff[1] = gcd(A[0], A[2]);
        buff[2] = gcd(A[1], A[2]);
        int ma, in;
        rep (i, 3)
        {
            if (chmax(ma, buff[i]))
            {
                in = i;
            }
        }
        cout << buff[in] << endl;
    }
    else
    {
        vector<lint> max_list;
        for (lint i = 0; i < N; ++i)
        {
            lint element;
            if (i == 0)
            {
                element = gcd(A[1], A[2]);
                for (lint k = 3; k < N; ++k)
                {
                    if (k != i)
                    {
                        element = gcd(element, A[k]);
                    }
                }
            }
            if (i == 1)
            {
                element = gcd(A[0], A[2]);
                for (lint k = 3; k < N; ++k)
                {
                    if (k != i)
                    {
                        element = gcd(element, A[k]);
                    }
                }
            }
            else 
            {
                element = gcd(A[0], A[1]);
                for (lint k = 2; k < N; ++k)
                {
                    if (k != i)
                    {
                        element = gcd(element, A[k]);
                    }
                }
            }
            max_list.push_back(element);
        }

        lint max = 0;
        lint max_index = 0;
        for (lint i = 0; i < (lint)max_list.size(); ++i)
        {
            if (chmax<lint>(max, max_list[i]))
            {
                max_index = i;
            }
        }

        cout << max_list[max_index] << "\n";
    }

    return 0;
}
