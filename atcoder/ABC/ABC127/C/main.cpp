# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define MSG(x) std::cout << #x << " : " << x << "\n";
using namespace std;
using lint = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int N, M;
vector<int> L;
vector<int> R;

struct Point
{
    Point(int _b, int _e)
        : b(_b)
        , e(_e)
    {
    }
    int b; // begin
    int e; // end

    int length() const
    {
        return e - b;
    }

    bool operator <(const Point& other) const
    {
        return this->length() < other.length();
    }
    bool operator >(const Point& other) const
    {
        return this->length() > other.length();
    }
};
vector<Point> P;

int main()
{
    cin >> N >> M;
    L.resize(M);
    R.resize(M);
    rep (i, M)
    {
        cin >> L[i];
        cin >> R[i];
        P.push_back(Point(L[i], R[i]));
    }

    std::sort(ALL(P), std::greater<Point>());
    Point now = P[0];
    // cout << now.b << ", " << now.e << endl;
    for (int i = 0; i < P.size() - 1; ++i)
    {
        if (now.e < P[i+1].b)
        {
            // cout << "A" << endl;
            cout << 0 << endl;
            return 0;
        }
        if (now.b > P[i+1].e)
        {
            // cout << "B" << endl;
            cout << 0 << endl;
            return 0;
        }

        if (now.b < P[i+1].b)
        {
            // cout << "C" << endl;
            now.b = P[i+1].b;
        }

        if (now.e > P[i+1].e)
        {
            // cout << "D" << endl;
            now.e = P[i+1].e;
        }

        if (now.b > now.e)
        {
            // cout << "E" << endl;
            cout << 0 << endl;
            return 0;
        }
        // cout << now.b << ", " << now.e << endl;
    }

    cout << now.length() + 1 << endl;

    return 0;
}
