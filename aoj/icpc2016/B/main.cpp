# include <iostream>
# include <map>
# include <cmath>
# include <vector>
# include <algorithm>
# define rep(i,n) for(int i=0; i<(n); i++)
# define LEN(v) ((int)(v).size())
# define ALL(v) (v).begin(), (v).end()
# define RALL(v) (v).rbegin(), (v).rend()
using namespace std;

void Main(int n, vector<char>& c) {
    vector<int> box(26, 0);
    rep (i, n) {
        box[c[i] - 'A']++;
        vector<int> tmp = box;
        sort(RALL(tmp));
        int nokori = n - (i+1);
        if (tmp[0] > tmp[1] + nokori) {
            rep (k, 26) {
                if (box[k] == tmp[0]) {
                    printf("%c %d\n", k + 'A', i + 1);
                    break;
                }
            }
            return;
        }
    }
    puts("TIE");
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<char> c(n);
        rep (i, n) cin >> c[i];
        Main(n, c);
    }
    
    return 0;
}