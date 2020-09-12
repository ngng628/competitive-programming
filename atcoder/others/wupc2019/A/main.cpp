# include <iostream>
# include <string>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    for (int i = (int)s.size()-1; i > 0; i--) {
        if (s[i-1] == 'W' and s[i] == 'A') {
            s[i-1] = 'A';
            s[i] = 'C';
        }
    }

    cout << s << "\n";

    return 0;
}

