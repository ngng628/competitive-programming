// これナップサックの亜種…？
// vectorの容量MAXエラー的なこと吐かれてる…？なんもわからん

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

int N;
vector<int> x, y;

vector<pair<lint, lint>> stk;
vector<pair<lint, lint>> cpstk;
lint cnt = 0;

lint ma = -1;

void foreach_permutation(lint n, std::function<void(lint *)> f) {
  lint indexes[n];
  for (lint i = 0; i < n; i++) indexes[i] = i;
  do {
    f(indexes);
  } while (std::next_permutation(indexes, indexes + n));
}

lint kaijo(lint n)
{
    lint k = 1;
    lint i = n;
    while (i >= 1)
    {
        k = k*i;
        --i;
    }
    return k;
}


int main()
{
    cin >> N;
    x.resize(N); y.resize(N);
    rep (i, N) { cin >> x[i] >> y[i]; }

    lint kaijoN = kaijo(N);
    foreach_permutation(N, [&](lint *id)
    {
        stk.clear();
        for (lint d = 1; d < N; ++d)
        {
            lint p_ = x[id[d]] - x[id[d-1]];
            lint q_ = y[id[d]] - y[id[d-1]];
            stk.push_back(make_pair(p_, q_));
        }
            cpstk = stk;
            lint count = 0;
            for (lint i = 0; i < stk.size(); ++i)
            {
BEGIN:
                pair<lint, lint> tmp = stk[i];
                count = 0;
                for (lint m = 0; m < cpstk.size(); ++m)
                {
                    if (tmp == cpstk[m])
                    {
                        count++;
                    }
                }
            }
                chmax(ma, count);
        cnt++;
    });


    cout << N - ma << endl;

    return 0;
}
