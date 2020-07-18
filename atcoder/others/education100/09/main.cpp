# include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define range_for(i, b, e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)

using P = pair<int, int>;
# define X first
# define Y second
# define DX first
# define DY second

struct phash {
    inline size_t operator ()(const pair<int,int>& p) const {
        const auto h1 = hash<int>()(p.first);
        const auto h2 = hash<int>()(p.second);
        return h1 ^ (h2 << 1);
    }
};

# define m_max (200)
# define n_max (1000)

int m;
P A[m_max];
int n;
P B[n_max];
P edge[m_max];
unordered_set<P, phash> s;

// bool pcmp(P p1, P p2)
// {
//     return p1.X == p2.X and p1.Y == p2.Y;
// }

bool ok(P start, P p, int i)
{
    P next;
    next.X = p.X + edge[i].DX;
    next.Y = p.Y + edge[i].DY;

    if (s.find(next) != s.end())
    {
        if (i == m-1)
        {
            return true;
        }
        else
        {
            return ok(start, next, ++i);
        }
    }
    else
    {
        return false;
    }
}

int main(void)
{
    cin >> m;
    rep (i, m)
    {
        int x, y; cin >> x >> y;
        A[i].X = x;
        A[i].Y = y;
        cerr << "(" << A[i].X << ", " << A[i].Y << "), ";
    }

    cin >> n;
    rep (i, n)
    {
        int x, y; cin >> x >> y;
        B[i].X = x;
        B[i].Y = y;
        s.insert(B[i]);
    }

    for (int i = 0; i + 1 < m; ++i)
    {
        edge[i].DX = A[i+1].X - A[i].X;
        edge[i].DY = A[i+1].Y - A[i].Y;
    }

    P ans;
    rep (i, n)
    {
        if (ok(B[i], B[i], 0))
        {
            ans.DX = B[i].X - A[0].X;
            ans.DY = B[i].Y - A[0].Y;
            break;
        }
    }

    printf("%d %d\n", ans.DX, ans.DY);

    return 0;
}

