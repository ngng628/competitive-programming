# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <functional>
# define len(v) ((int)v.size())
# define all(v) std::begin(v), std::end(v)
# define rall(v) std::rbegin(v), std::rend(v)
using namespace std;

void Main(int a0, const int L) {
    vector<int> visited;
    visited.push_back(a0);
    using Res = tuple<int, int, int>;
    function<Res(int, int)> solve = [&](int a, int i) -> Res {
        string s0 = to_string(a);
        string zero(L - len(s0), '0');
        s0 += zero;
        string big = [](auto& s){ sort(rall(s)); return s; }(s0);
        string small = [](auto& s){ sort(all(s)); return s; }(s0);
        int b = stoi(big) - stoi(small);
        if (any_of(all(visited), [=](int x){ return x == b; })) {
            int j = 0;
            for (;; j++) if (visited[j] == b) break;
            return { j, b, i - j };
        }
        else {
            visited.push_back(b);
            return solve(b, i + 1);
        }
    };
    auto [ j, b, i_j ] = solve(a0, 1);
    printf("%d %d %d\n", j, b, i_j);
}

int main() {
    while (true) {
        int a0, L;
        cin >> a0 >> L;
        if (!(a0 | L)) break;
        Main(a0, L);
    }

    return 0;
}
