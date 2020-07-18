# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define range_for(i, b, e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define step(n) rep(_, n)
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
# define Unique(a) a.erase(unique(ALL(a)), a.end())
# define pb push_back
# define len(x) ((int)(x).size())
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define debug(x) std::cerr<<#x<<": "<<(x)<<endl;
# define LINT_MAX (LLONG_MAX)
# define LINT_MIN (LLONG_MIN)
# define cauto const auto
//# define int long long
//# define float long double
using namespace std;
template <class Type> inline constexpr Type Square(Type x) { return x * x; }
template <class Type> inline constexpr bool InRange(const Type& x, const Type& i, const Type& a) { return (i <= x) && (x <= a); }
template<class Integer>bool chmax(Integer &a, const Integer &b) { if (a<b) { a=b; return 1; } return 0; }
template<class Integer>bool chmin(Integer &a, const Integer &b) { if (b<a) { a=b; return 1; } return 0; }
template<class Integer>bool IsOdd(Integer &n) { return n & 1; }
template<class Integer>bool IsEven(Integer &n) { return !(n & 1); }
long long gcd(long long a, long long b) { while(b){ long long A = a; (a = b), (b = A % b); } return a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int ctoi(const char c) { return ('0' <= c && c <= '9') ? (c - '0') : -1; }
string YesNo(bool b) { return b ? "Yes" : "No"; }
string YESNO(bool b) { return b ? "YES" : "NO"; }
string yesno(bool b) { return b ? "yes" : "no"; }
void _cin(){} template <class Head, class... Tail> void _cin(Head&& head, Tail&&... tail){ cin >> head; _cin(forward<Tail>(tail)...); }
#define Cin(Type, ...) Type __VA_ARGS__; _cin(__VA_ARGS__)
#define Cinv(Type, xs, n) vector<Type> xs(n); rep(i, n) cin >> xs[i]
#define Cinv2(Type, xs, ys, n) vector<Type> xs(n), ys(n); rep(i, n) cin >> xs[i] >> ys[i]
#define Cinv3(Type, xs, ys, zs, n) vector<Type> xs(n), ys(n), zs(n); rep(i, n) cin >> xs[i] >> ys[i] >> zs[i]
#define Cinvv(Type, xs, h, w) vector<vector<Type>> xs(h, vector<int>(w)); rep(i, h) rep(j, w) cin >> xs[i][j]
void Print() { cout << endl; }
template <class Head, class... Tail> void Print(Head&& head, Tail&&... tail) { cout << head; if (sizeof...(tail) != 0) cout << " "; Print(forward<Tail>(tail)...); }
template <class Type> void Print(vector<Type> &vec) { for (auto& a : vec) { cout << a; if (&a != &vec.back()) cout << " "; } cout << endl; }
template <class Type> void Print(vector<vector<Type>> &df) { for (auto& vec : df) { Print(vec); } }
void Debug() { cerr << endl; }
template <class Head, class... Tail> void Debug(Head&& head, Tail&&... tail) { cerr << head; if (sizeof...(tail) != 0) cerr << " "; Debug(forward<Tail>(tail)...); }
template <class Type> void Debug(vector<Type> &vec) { for (auto& a : vec) { cerr << a; if (&a != &vec.back()) cerr << " "; } cerr << endl; }
template <class Type> void Debug(vector<vector<Type>> &df) { for (auto& vec : df) { Debug(vec); } }

std::chrono::system_clock::time_point  __start, __end;

static const int D = 365;
vector<int> c;
vector<vector<int>> s;
void random_change(vector<int>&, int);

inline double GetTime()
{
    __end = chrono::system_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(__end - __start).count();
}

struct State
{
    State() = default;
    State(const State& st, int type) {
        this->types = st.types;
        types.pb(type);
        day = len(types);
        calcScore();
    }

    vector<State> all_next()
    {
        vector<State> res(26);
        rep (i, 26)
        {
            res[i] = State(*this, i);
        }
        return res;
    }

    void calcScore()
    {
        vector<int> lst(26);
        score = 0;
        rep (d, day)
        {
            int i = types[d];
            score += s[d][i];
            lst[i] = d+1;
            rep (k, 26)
            {
                score -= c[k] * (d+1 - lst[k]);
            }
        }

        range_for (d, day, min(day+6, D))
        {
            rep (k, 26)
            {
                score -= c[k] * (d+1 - lst[k]);
            }
        }
    }

    int score;
    int day;
    vector<int> types;

private:
    //int pre_score;

};

bool operator <(const State& left, const State& right)
{
    return left.score < right.score;
}

bool ShouldFinish(const State& s)
{
    return s.day == D;
}

vector<int> BeamSearch()
{
    int beam_width = 10;
    priority_queue<State> que;
    State s0 = State();
    que.push(s0);
    while (!que.empty())
    {
        priority_queue<State> next_que;
        int que_size = len(que);
        rep (i, min(beam_width, que_size))
        {
            State state = que.top(); que.pop();
            if (ShouldFinish(state)) { return state.types; }
            if (i == 0 and GetTime() >= 1900) { return state.types; }

            for (auto& nxt : state.all_next())
            {
                next_que.push(nxt);
            }
        }
        que = next_que;
    }

    return vector<int>(D, 0);
}

int Score(const vector<int>& t, int nowday = D)
{
    vector<int> lst(26);
    int value = 0;
    rep (d, nowday)
    {
        int i = t[d];
        value += s[d][i];
        lst[i] = d+1;
        rep (k, 26)
        {
            value -= c[k] * (d+1 - lst[k]);
        }
    }
    return value;
}

void random_change(vector<int>& types, int nowday)
{
    static random_device rnd;
    static mt19937 mt(rnd());
    static uniform_int_distribution<> rand_type(0, 25);
    int d = mt()%nowday;
    int t = rand_type(mt);
    int backup = types[d];
    int old_score = Score(types, nowday);
    types[d] = t;
    int new_score = Score(types, nowday);
    if (old_score >= new_score) {
        types[d] = backup;
    }

    int left_idx = mt()%nowday;
    int right_idx = mt()%nowday;
    old_score = Score(types, nowday);
    swap(types[left_idx], types[right_idx]);
    new_score = Score(types, nowday);
    if (old_score >= new_score) {
        swap(types[left_idx], types[right_idx]);
    }
}


signed main()
{
    optimize_cin();
    __start = chrono::system_clock::now();
    static random_device rnd;
    static mt19937 mt(rnd());
    static uniform_int_distribution<> rand_day(0, D-1);
    static uniform_int_distribution<> rand_type(0, 25);
    static uniform_int_distribution<> rand_inf(0, INT_MAX-1);
    
    int _; cin >> _;
    c.resize(26); rep (d, 26) cin >> c[d];
    s.resize(D); rep (d, D) { s[d].resize(26); rep (i, 26) { cin >> s[d][i]; } }

    vector<int> types = BeamSearch();
    types.resize(D);

    double start_temp = 2e3, end_temp = 2e2;
    //double start_temp = 14000, end_temp = -130000;
    int time_limit = 1980;

    //int maxi = -1, mini = INT_MAX;

    bool changed = true;
    int old_score, new_score;
    double nowtime = 0.0;
    double temp, prob;
    while ((nowtime = GetTime()) <= time_limit)
    {
        int d = rand_day(mt);
        int t = rand_type(mt);
        int backup = types[d];
        if (changed) old_score = Score(types);
        types[d] = t;
        new_score = Score(types);

        // 温度関数
        temp = start_temp + (end_temp - start_temp)*nowtime / time_limit;
        // 遷移確率関数
        prob = exp((new_score - old_score) / temp);

        //chmax(maxi, new_score - old_score);
        //chmin(mini, new_score - old_score);
        
        if (prob > (double) rand_inf(mt) / INT_MAX) {
            types[d] = backup;
            changed = false;
        }
        else {
            changed = true;
        }

        int left_idx = rand_day(mt);
        int right_idx = rand_day(mt);
        if (changed) old_score = Score(types);
        swap(types[left_idx], types[right_idx]);
        new_score = Score(types);

        //temp = start_temp + (end_temp - start_temp)*nowtime / time_limit;
        //prob = exp((new_score - old_score) / temp);
        //chmax(maxi, new_score - old_score);
        //chmin(mini, new_score - old_score);

        if (prob > (double) rand_inf(mt) / INT_MAX) {
            swap(types[left_idx], types[right_idx]);
            changed = false;
        }
        else {
            changed = true;
        }
    }

    rep (d, D)
    {
        cout << types[d] + 1 << "\n";
    }
    //Print(Score(types));
    //Print("max:",maxi);
    //Print("min:",mini);
    return 0;
}
