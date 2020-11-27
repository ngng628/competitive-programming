# include <atcoder/modint>
# include <iostream>
using namespace std;
using mint = atcoder::modint1000000007;

int main() {
    int N;
    cin >> N;

    mint ans = mint(10).pow(N) - 2*mint(9).pow(N) + mint(8).pow(N);

    cout << ans.val() << endl;

    return 0;
}
