# include <bits/stdc++.h>
using namespace std;

struct Rect {
    Rect() = default;
    Rect(int _h, int _w) : h(_h), w(_w) {}
    int diagonal2() const { return h*h + w*w; }
    int h, w;
};

bool operator <(const Rect& a, const Rect& b) {
    if (a.diagonal2() == b.diagonal2()) return a.h < b.h;
    return a.diagonal2() < b.diagonal2();
}

bool operator >(const Rect& a, const Rect& b) {
    if (a.diagonal2() == b.diagonal2()) return a.h > b.h;
    return a.diagonal2() > b.diagonal2();
}

void Main(const int H, const int W) {
    Rect input(H, W);
    Rect ans(5000, 5000);
    for (int h = 1; h < 1000; ++h) {
        for (int w = h + 1; w < 1000; ++w) {
            Rect rect(h, w);
            if (rect > input) {
                ans = min(ans, rect);
            }
        }
    }
    cout << ans.h << " " << ans.w << endl;
}

int main() {
    while (true) {
        int h, w;
        cin >> h >> w;
        if (!(h | w)) break;
        Main(h, w);
    }
    return 0;
}
