# include <iostream>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    while (b) {
        ll t = a;
        (a = b), (b = t % b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a*b / gcd(a, b);
}

int main()
{
    ll a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    cout << lcm(a, b) << endl;
    return 0;
}
