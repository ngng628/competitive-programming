# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;

int main()
{
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    int dx = tx - sx;
    int dy = ty - sy;

    cout << string(dy, 'U') << string(dx, 'R');
    cout << string(dy, 'D') << string(dx, 'L');
    cout << 'L' << string(dy + 1, 'U') << string(dx + 1, 'R') << 'D';
    cout << 'R' << string(dy + 1, 'D') << string(dx + 1, 'L') << 'U';

    cout << "\n";

    return 0;
}

