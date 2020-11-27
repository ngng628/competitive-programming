//                              ______  ______  ______
// .-----..-----..-----..-----.|    __||__    ||  __  |
// |     ||  _  ||     ||  _  ||  __  ||    __||  __  |
// |__|__||___  ||__|__||___  ||______||______||______|
//        |_____|       |_____|
//
# include <iostream>
# include <string>
using namespace std;

signed main() {
    string A, B;
    cin >> A >> B;

    if (A.length() < B.length()) {
        cout << B << endl;
    } else {
        cout << A << endl;
    }

    return 0;
}

