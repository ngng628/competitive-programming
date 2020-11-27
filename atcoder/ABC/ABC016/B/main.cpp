# include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    bool p = a + b == c;
    bool n = a - b == c;
    puts((p & n) ? "?" : p ? "+" : n ? "-" : "!");
    return 0;
}
