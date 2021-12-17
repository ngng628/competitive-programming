# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define float Float
# define overload3(_1,_2,_3,name,...) name
# define _step(n) _rep(_,n)
# define _rep(i,n) _repr(i,0,n)
# define _repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define rep(...) overload3(__VA_ARGS__, _repr, _rep, _step)(__VA_ARGS__)
# define _reps(i,n) _reprs(i,1,n)
# define _reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define reps(...) overload3(__VA_ARGS__, _reprs, _reps)(__VA_ARGS__)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
# define all(v) std::begin(v), std::end(v)
# define rall(v) std::rbegin(v), std::rend(v)
# define pb push_back
# define eb emplace_back
# define len(v) (int)std::size(v)
# define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
using Int = long long;
using Float = long double;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
constexpr int oo = (1LL<<62)-(1LL<<31);
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
# endif  // ngng628_library

using State = string::const_iterator;
void skip(State& it) { while (isspace(*it)) ++it; }
void skip(State& it, char c) { assert(c == *it); ++it; }
void skip(State& it, const string& s) { for (char c : s) { assert(c == *it); ++it; } }
void skip(State& it, int n) { while (n--) ++it; }
string erase_all_space(string s) { s.erase(remove_if(all(s), [](char c){ return isspace(c); }), s.end()); return s; }
int ctoi(char c) { assert('0' <= c and c <= '9'); return c - '0'; }

// 各向きに対する移動方向
map<char, pii> dydx = {
	{'N', make_pair(-1, 0)},
	{'E', make_pair(0, 1)},
	{'S', make_pair(1, 0)},
	{'W', make_pair(0, -1)},
};

// ロボット
struct Robot {
	Robot() = default;
	Robot(int _y, int _x, char _dir, vec<string> _a) : y(_y), x(_x), dir(_dir), a(_a) {}
	bool cannot_move_front() {
		int ny = y + dydx[dir].first;
		int nx = x + dydx[dir].second;
		return a[ny][nx] == '#'
	}
	int y, x;
	char dir;
private:
	vec<string> a;
};

int32_t main() {
	int h, w;
	cin >> h >> w;
	vec<string> a(h);
	cin >> a;
	string s;
	cin >> s;

	struct Parser {
		// 入力
		int h, w;
		vec<string> a;
		string s;

		// 現在の位置
		Robot robot;

		// ゴールの位置
		int gy, gx;

		Parser(int _h, int _w, vector<string> _a, string _s) : h(_h), w(_w), a(_a), s(_s) {
			int sy, sx;
			rep (i, h) rep (j, w) {
				if (a[i][j] == 's') {
					sy = i;
					sx = j;
				}
				if (a[i][j] == 'g') {
					gy = i;
					gx = j;
				}
			}
			robot = Robot(sy, sx, 'N', a);

			State it = s.begin();
			program(it, true, false);
		}

		void program(State& it, bool if_cond, bool while_cond) {
			sentence(it, if_cond, while_cond);
		}

		void sentence(State& it, bool if_cond, bool while_cond) {
			if (*it == '[') {
				assert(*it++ == '[');
				bool c = condition(it);
				program(it, if_cond & c, while_cond);
			}
			else if (*it == '{') {
				assert(*it++ == '{');
				bool c = condition(it);
				program(it, if_cond, while_cond & c);
			}
			else {
				run(it, if_cond, while_cond);
			}
		}

		bool condition(State& it) {
			bool NOT = false;
			if (*it == '~') {
				NOT = true;
				it++;
			}
			char c = *it;
			it++;
			if (c == 'C') return (robot.cannot_move_front()) ^ NOT;
			else if (c == 'T') return true ^ NOT;
			else return (c == robot.dir) ^ NOT;
		}

		void run(State& it, bool if_cond, bool while_cond) {
			if (not if_cond) return;

			if (while_cond) {
				while (
			}
			else {

			}
		}
	};


}