#include <bits/stdc++.h>
#ifndef ngng628_library
#define ngng628_library
#define int Int
#define float Float
#define overload3(_1, _2, _3, name, ...) name
#define _step(n) _rep(_, n)
#define _rep(i, n) _repr(i, 0, n)
#define _repr(i, b, e) for (int i = (b), i##_len = (e); i < i##_len; ++i)
#define rep(...) overload3(__VA_ARGS__, _repr, _rep, _step)(__VA_ARGS__)
#define _reps(i, n) _reprs(i, 1, n)
#define _reprs(i, b, e) for (int i = (b), i##_len = (e); i <= i##_len; ++i)
#define reps(...) overload3(__VA_ARGS__, _reprs, _reps)(__VA_ARGS__)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define rreps(i, n) for (int i = (n); i > 0; --i)
#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)
#define pb push_back
#define eb emplace_back
#define len(v) (int)std::size(v)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
using Int   = long long;
using Float = long double;
template <class T>
using vec        = vector<T>;
using pii        = pair<int, int>;
using vi         = vec<int>;
using vvi        = vec<vi>;
using db         = deque<bool>;
using ddb        = deque<db>;
constexpr int oo = (1LL << 62) - (1LL << 31);
template <class T>
istream& operator>>(istream& is, vec<T>& v) {
  for (auto& x : v) is >> x;
  return is;
}
template <class T, size_t N>
istream& operator>>(istream& is, array<T, N>& v) {
  for (auto& x : v) is >> x;
  return is;
}
template <class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
  return is >> p.first >> p.second;
}
template <class T>
string join(const vec<T>& v) {
  stringstream s;
  for (T t : v) s << ' ' << t;
  return s.str().substr(1);
}
template <class T>
ostream& operator<<(ostream& os, const vec<T>& v) {
  if (len(v)) os << join(v);
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vec<vec<T>>& v) {
  rep(i, len(v)) if (len(v[i])) os << join(v[i])
                                   << (i - len(v) + 1 ? "\n" : "");
  return os;
}
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  return os << p.first << ' ' << p.second;
}
template <class T, class U, class V>
ostream& operator<<(ostream& os, const tuple<T, U, V>& t) {
  return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
}
template <class T>
constexpr bool chmax(T& a, const T& b) {
  return a < b && (a = b, true);
}
template <class T>
constexpr bool chmin(T& a, const T& b) {
  return a > b && (a = b, true);
}
#endif  // ngng628_library

using State = string::const_iterator;
int ctoi(char c) {
  assert('0' <= c and c <= '9');
  return c - '0';
}

struct Node;
using pNode = shared_ptr<Node>;
struct Node {
  Node() : type('e'), op('*'), num(-1), left(), mid(nullptr), right(nullptr) {
  }
  Node(int t, char o, int n)
      : type(t), op(o), num(n), left(nullptr), mid(nullptr), right(nullptr) {
  }

  char type;
  char op;
  int num;
  int nodeNum;

  pNode left;
  pNode mid;
  pNode right;
};

int calc(pNode node) {
  if (node->type == 'o') {
    int l = calc(node->left);
    int r = calc(node->right);
    if (node->op == '+')
      return l + r;
    else if (node->op == '-')
      return l - r;
    else
      assert(false);
  } else {
    return node->num;
  }
}

void giveNodeNum(pNode curr, int& num) {
  if (curr == nullptr) return;
  curr->nodeNum = num;
  if (curr->left != nullptr) {
    num++;
    giveNodeNum(curr->left, num);
  }
  if (curr->mid != nullptr) {
    num++;
    giveNodeNum(curr->mid, num);
  }
  if (curr->right != nullptr) {
    num++;
    giveNodeNum(curr->right, num);
  }
}

Int treeDP(pNode curr, bool maxmize, vector<Int>& maximized,
           vector<Int>& minimized) {
  if (curr == nullptr) {
    return 0;
  }
  if (maxmize && maximized[curr->nodeNum] != INT32_MIN) {
    return maximized[curr->nodeNum];
  }
  if (!maxmize && minimized[curr->nodeNum] != INT32_MAX) {
    return minimized[curr->nodeNum];
  }
  Int res = 0;
  if (curr->type == 'i') {
    res                      = curr->num;
    maximized[curr->nodeNum] = res;
    minimized[curr->nodeNum] = res;
  } else {
    Int leftMax  = treeDP(curr->left, true, maximized, minimized);
    Int leftMin  = treeDP(curr->left, false, maximized, minimized);
    Int midMax   = treeDP(curr->mid, true, maximized, minimized);
    Int midMin   = treeDP(curr->mid, false, maximized, minimized);
    Int rightMax = treeDP(curr->right, true, maximized, minimized);
    Int rightMin = treeDP(curr->right, false, maximized, minimized);

    Int currMax, currMin;

    if (curr->op == '+') {
      currMax = leftMax + midMax + rightMax;
      currMin = leftMin + midMin + rightMin;
    } else {
      vector<Int> maxcandidate, mincandidate;
      if (curr->mid == nullptr) {
        maxcandidate.push_back(leftMax - rightMin);
        maxcandidate.push_back(rightMax - leftMin);
        mincandidate.push_back(leftMin - rightMax);
        mincandidate.push_back(rightMin - leftMax);
      } else {
        maxcandidate.push_back(leftMax - midMin - rightMin);
        maxcandidate.push_back(midMax - leftMin - rightMin);
        maxcandidate.push_back(rightMax - midMin - leftMin);

        mincandidate.push_back(leftMin - midMax - rightMax);
        mincandidate.push_back(midMin - leftMax - rightMax);
        mincandidate.push_back(rightMin - midMax - leftMax);
      }
      currMax = *max_element(maxcandidate.begin(), maxcandidate.end());
      currMin = *min_element(mincandidate.begin(), mincandidate.end());
    }

    maximized[curr->nodeNum] = max(currMax, maximized[curr->nodeNum]);
    minimized[curr->nodeNum] = min(minimized[curr->nodeNum], currMin);

    if (maxmize) {
      res = currMax;
    } else {
      res = currMin;
    }
  }

  return res;
}

void dp2(pNode curr, Int parentMax, Int parentMin, Int centerMax, Int centerMin,
         char parentOp, vector<Int>& maximized, vector<Int>& minimized,
         vector<Int>& res) {
  if (curr == nullptr) return;
  if (curr->type == 'i') return;

  if (curr->op == '+') {
    res[curr->nodeNum] = maximized[curr->left->nodeNum] +
                         maximized[curr->right->nodeNum] + parentMax;
  } else {
    res[curr->nodeNum] = max({maximized[curr->left->nodeNum] -
                                  minimized[curr->right->nodeNum] - parentMin,
                              maximized[curr->right->nodeNum] -
                                  minimized[curr->left->nodeNum] - parentMin,
                              parentMax - minimized[curr->right->nodeNum] -
                                  minimized[curr->left->nodeNum]});
  }

  // 左に行く: 中央と右の2つ
  if (parentOp == '+') {
    parentMax = centerMax + maximized[curr->right->nodeNum];
    parentMin = centerMin + minimized[curr->right->nodeNum];
  } else {
    parentMax = max(centerMax - minimized[curr->right->nodeNum],
                    maximized[curr->right->nodeNum] - centerMin);
    parentMin = min(centerMin - maximized[curr->right->nodeNum],
                    minimized[curr->right->nodeNum] - centerMax);
  }
  if (curr->left->type != 'i') {
    dp2(curr->left, parentMax, parentMin, maximized[curr->left->right->nodeNum],
        minimized[curr->left->right->nodeNum], curr->op, maximized, minimized,
        res);
  }

  // 右に行く
  if (parentOp == '+') {
    parentMax = centerMax + maximized[curr->left->nodeNum];
    parentMin = centerMin + minimized[curr->left->nodeNum];
  } else {
    parentMax = max(centerMax - minimized[curr->left->nodeNum],
                    maximized[curr->left->nodeNum] - centerMin);
    parentMin = min(centerMin - maximized[curr->left->nodeNum],
                    minimized[curr->left->nodeNum] - centerMax);
  }
  if (curr->right->type != 'i') {
    dp2(curr->right, parentMax, parentMin,
        maximized[curr->right->left->nodeNum],
        minimized[curr->right->left->nodeNum], curr->op, maximized, minimized,
        res);
  }
}

bool Main() {
  string s;
  cin >> s;
  if (s == "-1") return false;

  struct Parser {
    string s;
    pNode root;
    Parser(string _s) : s(_s) {
    }

    pNode parse() {
      State it = s.begin();
      root     = make_shared<Node>();
      Root(it);
      return root;
    }

    void Root(State& it) {
      // cerr << "<Root>" << endl;
      root->left  = make_shared<Node>();
      root->mid   = make_shared<Node>();
      root->right = make_shared<Node>();

      NonRoot(it, root->left);
      char op1 = *it++;
      NonRoot(it, root->mid);
      char op2 = *it++;
      NonRoot(it, root->right);

      assert(op1 == op2);
      root->type = 'r';
      root->op   = op1;
    }

    void NonRoot(State& it, pNode now) {
      // cerr << "<NonRoot>" << endl;
      assert(now != nullptr);
      if (isdigit(*it)) {
        now->type = 'i';
        now->num  = number(it);
      } else if (*it == '(') {
        now->type = 'o';
        assert(*it++ == '(');
        now->left = make_shared<Node>();
        assert(now->left != nullptr);
        NonRoot(it, now->left);

        assert(*it == '+' or *it == '-');
        now->op = *it++;

        now->right = make_shared<Node>();
        assert(now->right != nullptr);
        NonRoot(it, now->right);
        assert(*it++ == ')');
      }
    }

    int number(State& it) {
      int res = 0;
      for (; isdigit(*it); ++it) {
        res *= 10;
        res += ctoi(*it);
      }
      return res;
    }
  };

  pNode tree = Parser(s).parse();

  cerr << "finished" << endl;

  int nodeNum = 0;
  giveNodeNum(tree, nodeNum);

  cerr << "finished" << endl;

  vector<Int> maximized(nodeNum + 2, INT32_MIN),
      minimized(nodeNum + 2, INT32_MAX);
  treeDP(tree, true, maximized, minimized);
  treeDP(tree, false, maximized, minimized);
  vector<Int> res(nodeNum + 2, INT32_MIN);
  dp2(tree, maximized[tree->mid->nodeNum], minimized[tree->mid->nodeNum],
      maximized[tree->mid->nodeNum], minimized[tree->mid->nodeNum], tree->op,
      maximized, minimized, res);

  cout << *max_element(res.begin(), res.end()) << endl;

  return true;
}

int32_t main() {
  while (Main())
    ;
}