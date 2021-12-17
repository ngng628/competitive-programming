#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll M = 1e9+7;

vector<bool> f;

ll expr(string const& s, int& p);
ll term(string const& s, int& p);
void sp(string const& s, int& p);
ll number(string const& s, int& p);

ll expr(string const& s, int& p) {
    sp(s, p);
    ll v1 = term(s, p);
    sp(s, p);
    while(p+1 < s.size() && f[p]) {
        p += 2;
        sp(s, p);
        ll v2 = term(s, p);
        if(v2 > 63) {
            v1 = 0;
        } else {
            v1 >>= v2;
        }
        sp(s, p);
    }
    return v1;
}

ll term(string const& s, int& p) {
    sp(s, p);
    if(s[p] == 'S') {
        sp(s, ++p);
        p++; // <
        sp(s, p);
        ll v = expr(s, p);
        sp(s, p);
        p++; // >
        v = (v * v) % M;
        return v;
    }
    return number(s, p);
}

void sp(string const& s, int& p) {
    while(p < s.size() && s[p] == ' ') {
        p++;
    }
}

ll number(string const& s, int& p) {
    int res = 0;
    while(p < s.size() && isdigit(s[p])) {
        res *= 10;
        res += s[p++] - '0';
    }
    return res;
}

int main() {
    while(true) {
        string s;
        getline(cin, s);
        if(s[0] == '#') {
            break;
        }
        int p = 0;
        f.assign(s.size(), false);
        for(int i=s.size()-1; i>=0; --i) {
            if(isdigit(s[i]) || s[i] == 'S') {
                if(isdigit(s[i])) {
                    while(i > 0 && isdigit(s[i])) {
                        --i;
                    }
                } else if(s[i] == 'S') {
                    i--;
                }
                while(i > 0 && s[i] == ' ') {
                    i--;
                }
                if(s[i] == '>') {
                    i--;
                    f[i] = true;
                }
            }
        }
        cout << expr(s, p) << endl;
    }
}