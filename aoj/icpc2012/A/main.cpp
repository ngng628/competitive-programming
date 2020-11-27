# include <iostream>
using namespace std;

int solve(int y, int m, int d) {
    int day = 0;
    for (int i = 1; i < y; ++i) {
        if (i % 3 == 0) day += 20 * 10;
        else day += (20 + 19) * 5;
    }

    for (int i = 1; i < m; ++i) {
        if (i % 2 == 0 and y % 3 != 0) day += 19;
        else day += 20;
    }

    day += d - 1;
    return day;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int y, m, d;
        cin >> y >> m >> d;
        int now = solve(1000, 1, 1);
        int birth = solve(y, m, d);
        cout << now - birth << endl;
    }

    return 0;
}
