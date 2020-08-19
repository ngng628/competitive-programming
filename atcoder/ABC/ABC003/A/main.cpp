# include <bits/stdc++.h>
# define reps(i,n) for (int i = 1; i <= n; ++i)
using namespace std;

int main()
{
    int n; cin >> n;
    int sum = 0;
    reps (i, n) sum += 10000*i;
    printf("%d\n", sum / n);
    return 0;
}
