# include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n;
    cin >> n;
    uint64_t mn = numeric_limits<uint64_t>::max();
    for (size_t i = 0; i < 5; ++i) {
        uint64_t x;
        cin >> x;
        mn = min(mn, x);
    }
    cout << (n + mn - 1) / mn + 4 << endl;
}