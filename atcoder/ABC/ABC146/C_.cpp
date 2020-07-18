# include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B, X;

bool isOK(ll n) {
    if (A*n + B*((ll)log10(n) + 1) <= X) { return true; }
    else { return false; }
}
 
ll binary_search() {
    ll ng = 1e9 + 1;
    ll ok = 0;
        
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid)) { ok = mid; }
        else { ng = mid; }
    }
    return ok;
}
 
int main() {
    cin >> A >> B >> X;
    cout << binary_search() << endl;
    return 0;
}
