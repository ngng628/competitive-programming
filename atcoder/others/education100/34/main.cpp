# include <bits/stdc++.h>
# define range_for(i, b, e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
using namespace std;
void _cin(){}
template <class Head, class... Tail> void _cin(Head&& head, Tail&&... tail){ cin >> head; _cin(forward<Tail>(tail)...); }
#define Cin(Type, ...) Type __VA_ARGS__; _cin(__VA_ARGS__)

static const int n_max = 44;
int fib[n_max + 1];

signed main()
{
    Cin(int, n);

    fib[0] = fib[1] = 1;
    range_for (i, 2, n+1)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    cout << fib[n] << endl;

    return 0;
}
