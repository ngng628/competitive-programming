# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
using lint = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

struct Point
{
    int x, y;
    int a;

    bool operator < (const Point& other)
    {
        return this->a < other.a;
    }
    bool operator <= (const Point& other)
    {
        return this->a < other.a;
    }
    bool operator > (const Point& other)
    {
        return this->a > other.a;
    }
    bool operator >= (const Point& other)
    {
        return this->a >= other.a;
    }

};

int main()
{
    int W, H, N;
    cin >> W >> H >> N;
    vector<Point> p(N);
    rep (i, N) { cin >> p[i].x >> p[i].y >> p[i].a; }

    int max1, max2, max3, max4;
    max1 = max3 = -1;
    max2 = max4 = 1000;
    rep (i, N)
    {
        switch(p[i].a)
        {
        case 1:
            chmax(max1, p[i].x);
            break;
        case 2:
            chmin(max2, p[i].x);
            break;
        case 3:
            chmax(max3, p[i].y);
            break;
        case 4:
            chmin(max4, p[i].y);
            break;
        }
    }

    if (max2 != 1000)
    {
        W = max2;
    }
    if (max1 != -1)
    {
        W -= max1;
    }
    if (max4 != 1000)
    {
        H = max4;
    }
    if (max3 != -1)
    {
        H -= max3;
    }

    if (W > 0 && H > 0)
    {
        cout << W * H << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }

    return 0;
}

