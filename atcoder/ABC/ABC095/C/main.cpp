# include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;
    if (A + B >= 2*C) {
        if (X < Y) {
            ans += X*2*C;
            int nokori = Y - X;
            if (B > 2*C) { ans += 2*C*nokori; }
            else         { ans += B*nokori;   }
        }
        else
        {
            ans += Y*2*C;
            int nokori = X - Y;
            if (A > 2*C) { ans += 2*C*nokori; }
            else         { ans += A*nokori;   }
        }
    }
    else {
        ans += A*X;
        ans += B*Y;
    }

    cout << ans << "\n";

    return 0;
}

