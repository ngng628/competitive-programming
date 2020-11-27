# include <bits/stdc++.h>
# define rep(i, n) for (int i = 0; i < (int)(n); ++i)
# define pb push_back
# define eb emplace_back
# define len(v) ((int)v.size())
# define all(v) std::begin(v), std::end(v)
# define rall(v) std::rbegin(v), std::rend(v)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

struct Result {
    Result() = default;
    Result(int t, int a, int s) : team_num(t), ac(a), sum_time(s) {}
    int team_num;
    int ac;
    int sum_time;
};

bool operator <(const Result& a, const Result& b) {
    if (a.ac == b.ac) {
        if (a.sum_time == b.sum_time) {
            return a.team_num < b.team_num;
        }
        return a.sum_time > b.sum_time;
    }
    return a.ac < b.ac;
}

bool operator >(const Result& a, const Result& b) {
    if (a.ac == b.ac) {
        return a.sum_time < b.sum_time;
    }
    return a.ac > b.ac;
}

bool operator ==(const Result& a, const Result& b) {
    return a.ac == b.ac and a.sum_time == b.sum_time;
}

void Main(int M, int T, int P, int R, vi m, vi t, vi p, vi j) {
    vvi timer(T, vi(P, -1));
    vvi miss(T, vi(P, 0));
    rep (i, R) {
        int team = t[i];
        int problem = p[i];
        int elapsed = m[i];
        int judge = j[i];
        if (judge == 0) { // 正解
            if (timer[team][problem] == -1 and elapsed <= M) {
                timer[team][problem] = elapsed + 20*miss[team][problem];
            }
        }
        else { // 不正解
            miss[team][problem]++;
        }
    }

    vector<Result> res;
    rep (team, T) {
        int ac = 0;
        for (int x : timer[team]) ac += (x != -1);
        int sum_time = 0;
        for (int x : timer[team]) sum_time += max(0, x);
        res.eb(team + 1, ac, sum_time);
    }

    if (len(res) == 1) {
        cout << res[0].team_num << endl;
        return;
    }
    sort(rall(res));
    cout << res[0].team_num;
    for (int i = 1; i < len(res); ++i) {
        if (res[i] == res[i-1]) {
            cout << "=" << res[i].team_num;
        }
        else {
            cout << "," << res[i].team_num;
        }
    }
    cout << endl;
}

int main() {
    while (true) {
        int M, T, P, R;
        cin >> M >> T >> P >> R;
        if (!(M | T | P | R)) break;
        vi m(R), t(R), p(R), j(R);
        rep (i, R) {
            cin >> m[i] >> t[i] >> p[i] >> j[i];
            t[i]--; p[i]--;
        }
        Main(M, T, P, R, m, t, p, j);
    }
    return 0;
}
