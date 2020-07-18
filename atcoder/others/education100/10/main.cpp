# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define pb push_back
# define len(x) ((int)(x).size())
using namespace std;
string yesno(bool b) { return b ? "yes" : "no"; }
void _cin(){} template <class Head, class... Tail> void _cin(Head&& head, Tail&&... tail){ cin >> head; _cin(forward<Tail>(tail)...); }
#define Cin(Type, ...) Type __VA_ARGS__; _cin(__VA_ARGS__)
#define Cinv(Type, xs, n) vector<Type> xs(n); rep(i, n) cin >> xs[i]
void Print() { cout << endl; }
template <class Head, class... Tail> void Print(Head&& head, Tail&&... tail) { cout << head; if (sizeof...(tail) != 0) cout << " "; Print(forward<Tail>(tail)...); }
template <class Type> void Print(vector<Type> &vec) { for (auto& a : vec) { cout << a; if (&a != &vec.back()) cout << " "; } cout << endl; }
template <class Type> void Print(vector<vector<Type>> &df) { for (auto& vec : df) { Print(vec); } }

set<int> solve(const int n, const vector<int>& A)
{
    set<int> res;
    rep (bit, 1 << n)
    {
        int sum = 0;
        rep (i, n)
        {
            if (bit & (1 << i))
            {
                sum += A[i];
            }
        }

        res.insert(sum);
    }

    return res;
}

int main()
{
    Cin(int, n);
    Cinv(int, A, n);
    Cin(int, q);
    set<int> memo = solve(n, A);
    while (q--)
    {
        Cin(int, m);
        Print(yesno(memo.find(m) != memo.end()));
    }

    return 0;
}
