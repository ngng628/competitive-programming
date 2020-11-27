# include <bits/stdc++.h>
# define rep(i,n) for (int i = 0; i < (int)(n); i++)
# define repr(i,a,b) for (int i = a; i < (int)(b); i++)
# define rrep(i,n) for (int i = (int)(n)-1; i >= 0; i--)
# define all(v) (v).begin(), (v).end()
# define rall(v) (v).rbegin(), (v).rend()
# define len(v) ((int)(v).size())
# define pb(v) push_back(v)
# define FI first
# define SE second
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

vector<int> splitint(const string &s, char delim) {
    vector<int> elems;
    string item;    
    for (char ch: s) {
        if (ch == delim) {
            if (!item.empty()) elems.pb(stoi(item));
            item.clear();
        }
        else item += ch;
    }
    if (!item.empty()) elems.pb(stoi(item));
    return elems;
}

void Main(int h, int w, vvi s) {
    vvi t(w, vi(h));
    rep (i, w) rep (k, h) t[i][k] = s[h - k - 1][i];
    swap(h, w);

    int ans = 0;
    while (true) {
        bool con = false;
        rep (x, w) {
            pii l = make_pair(t[0][x], 0);
            int cnt = 1;
            repr (y, 1, h) {
                if (l.FI != t[y][x] or t[y][x] == -1) {
                    if (cnt >= 3) {
                        ans += l.FI * cnt;
                        repr (_y, l.SE, y) t[_y][x] = 0;
                        con = true;
                    }
                    l = make_pair(t[y][x], y);
                    cnt = 1;
                }
                else {
                    cnt++;
                }
            }

            if (cnt >= 3) {
                ans += t[l.SE][x] * cnt;
                repr (_y, l.SE, h) t[_y][x] = 0;
                con = true;
            }
        }

        if (not con) break; 

        rep (y, h) {
            auto result = remove_if(all(t[y]), [](int x){ return !x; });
            for_each(result, t[y].end(), [](auto& x){ x = -1; });
        }
    }

    cout << ans << endl;
}

int main() {
    while (true) {
        int h;
        cin >> h;
        if (!h) break;
        vvi s(h);
        rep (i, h) {
            string row;
            do { getline(cin, row); } while(row.empty());
            s[i] = splitint(row, ' ');
        }
        const int w = len(s[0]);
        Main(h, w, s);
    }
    
    return 0;
}
