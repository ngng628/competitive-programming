# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
using lint = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    optimize_cin();

    string SA, SB, SC;
    cin >> SA >> SB >> SC;
    reverse(ALL(SA));
    reverse(ALL(SB));
    reverse(ALL(SC));

    char turn = 'a';

    while (true)
    {
        if (turn == 'a' && SZ(SA) == 0)
        {
            cout << "A" << "\n";
            break;
        }
        else if (turn == 'b' && SZ(SB) == 0)
        {
            cout << "B" << "\n";
            break;
        }
        else if (turn == 'c' && SZ(SC) == 0)
        {
            cout << "C" << "\n";
            break;
        }

        if (turn == 'a')
        {
            turn = SA.back();
            SA.pop_back();
        }
        else if (turn == 'b')
        {
            turn = SB.back();
            SB.pop_back();
        }
        else if (turn == 'c')
        {
            turn = SC.back();
            SC.pop_back();
        }
    }

    return 0;
}
