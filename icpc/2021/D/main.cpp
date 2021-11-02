#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <random>

using namespace std;

using lint  = int64_t;
using uint  = uint32_t;
using ulint = uint64_t;

template <class T>
using vector2d = vector<vector<T>>;

template <class T>
bool UpdateMax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  } else {
    return false;
  }
}

template <class T>
bool UpdateMin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  } else {
    return false;
  }
}

template <class T>
void OutVec(const vector<T> &vec) {
  for (int i = 0; i < vec.size() - 1; ++i) {
    cout << vec[i] << " ";
  }
  cout << vec.back() << endl;
}

template <class T>
void OutVec2d(const vector2d<T> &vec) {
  for (auto v : vec) {
    OutVec(v);
  }
}

int64_t EuclidMod(int64_t v, int64_t m) {
  if (0 <= v && v < m) {
    return v;
  } else if (-m <= v && v < 0) {
    return v + m;
  } else {
    int64_t result = v % m;
    if (result < 0) {
      result += m;
    }
    return result;
  }
}

int64_t ModInv(int64_t a, int64_t m) {
  int64_t b = m, u = 1, v = 0;
  while (b) {
    int64_t t = a / b;
    a -= t * b;
    std::swap(a, b);
    u -= t * v;
    std::swap(u, v);
  }
  EuclidMod(u, m);
  return u;
}

// return base^exponent (MOD. mod).
int64_t RepeatedPowMod(int64_t base, int64_t exponent, int64_t mod) {
  if (exponent == 0)
    return 1;
  else if (exponent % 2 == 0) {
    int64_t root = RepeatedPowMod(base, exponent / 2, mod);
    return (root * root) % mod;
  } else {
    return (base * RepeatedPowMod(base, exponent - 1, mod)) % mod;
  }
}

template <int64_t mod>
class ModInt {
  int64_t value_;

public:
  explicit ModInt(const int64_t x = 0) : value_(x % mod){};

  ModInt& operator=(const ModInt& another) {
    value_ = another.value_;
    return *this;
  }

  ModInt& operator^=(const ModInt& another) {
    value_ = RepeatedPowMod(value_, another.value_, mod);
    return *this;
  }

  ModInt& operator+=(const ModInt& another) {
    value_ += another.value_;
    value_ = EuclidMod(value_, mod);
    return *this;
  }

  ModInt& operator-=(const ModInt& another) {
    value_ -= another.value_;
    value_ = EuclidMod(value_, mod);
    return *this;
  }

  ModInt& operator*=(const ModInt& another) {
    value_ *= another.value_;
    value_ = EuclidMod(value_, mod);
    return *this;
  }

  ModInt& operator/=(const ModInt& another) {
    value_ = value_ * ModInv(another.value_, mod);
    value_ = EuclidMod(value_, mod);
    return *this;
  }

  ModInt& operator++() {
    value_ += ModInt(1);
    return *this;
  }

  ModInt operator++(int) {
    ModInt tmp = *this;
    ++tmp;
    return tmp;
  }

  ModInt& operator--() {
    value_ -= ModInt(1);
    return *this;
  }

  ModInt operator--(int) {
    ModInt tmp = *this;
    --tmp;
    return tmp;
  }

  int64_t GetValue() const {
    return value_;
  }
};

template <int64_t mod>
ModInt<mod> operator+(const ModInt<mod>& left, const ModInt<mod>& right) {
  return ModInt<mod>(left) += right;
}

template <int64_t mod>
ModInt<mod> operator-(const ModInt<mod>& left, const ModInt<mod>& right) {
  return ModInt<mod>(left) -= right;
}

template <int64_t mod>
ModInt<mod> operator/(const ModInt<mod>& left, const ModInt<mod>& right) {
  return ModInt<mod>(left) /= right;
}

template <int64_t mod>
ModInt<mod> operator*(const ModInt<mod>& left, const ModInt<mod>& right) {
  return ModInt<mod>(left) *= right;
}

template <int64_t mod>
ModInt<mod> operator^(const ModInt<mod>& left, const ModInt<mod>& right) {
  return ModInt<mod>(left) ^= right;
}

template <int64_t mod>
std::ostream& operator<<(std::ostream& stream, const ModInt<mod>& mod_int) {
  stream << mod_int.GetValue();
  return stream;
}

template <int64_t mod>
std::istream& operator>>(std::istream& stream, ModInt<mod>& mod_int) {
  int64_t v;
  stream >> v;
  mod_int = ModInt<mod>(v);
  return stream;
}

class RandomIntNumber {
  std::mt19937_64 mt_maker_;
  std::uniform_int_distribution<int64_t> range_maker_;

public:
  RandomIntNumber(int64_t min, int64_t max) {
    std::random_device seed_maker;
    mt_maker_.seed(seed_maker());
    // range_maker_.min = min;
    // range_maker_.max = max;
    std::uniform_int_distribution<int64_t>::param_type param(min, max);
    range_maker_.param(param);
  }
  int64_t Make(void) {
    return range_maker_(mt_maker_);
  }
  int64_t operator()(void) {
    return Make();
  }
};

class RollingHash {
  static const int64_t MOD_ = 1000000007;
  std::vector<ModInt<MOD_>> hash_;
  std::string str_;
  RandomIntNumber random_int_number_;
  int64_t base_;

public:
  RollingHash(const std::string &str)
      : random_int_number_(2, MOD_ - 2), str_(str) {
    base_ = random_int_number_.Make();
    for (int i = 0; i < str.size(); i++) {
      if (i == 0) {
        hash_.push_back(ModInt<MOD_>(str[0]));
      } else {
        ModInt<MOD_> result(hash_[i - 1]);
        result *= ModInt<MOD_>(base_);
        result += ModInt<MOD_>(str[i]);
        hash_.push_back(result);
      }
    }
  }
  RollingHash(const std::string &str, int64_t base)
      : random_int_number_(2, MOD_ - 2), str_(str), base_(base) {
    for (int i = 0; i < str.size(); i++) {
      if (i == 0) {
        hash_.push_back(ModInt<MOD_>(str[0]));
      } else {
        ModInt<MOD_> result(hash_[i - 1]);
        result *= ModInt<MOD_>(base_);
        result += ModInt<MOD_>(str[i]);
        hash_.push_back(result);
      }
    }
  }
  int64_t GetHash(int front, int back) {
    if (front > back) {
      cerr << "RollingHash::GetHash() Error: argument\"front\" is larger than "
              "\"back\""
           << endl;
      abort();
    }
    if (front == 0) return hash_[back].GetValue();
    ModInt<MOD_> result =
        hash_[back] - hash_[front - 1] * ModInt<MOD_>(RepeatedPowMod(
                                             base_, back - front + 1, MOD_));
    return result.GetValue();
  }
  int64_t GetBase() {
    return base_;
  }
};

lint solve(string all) {
  string s;
  string t;
  if (all.size() % 2 == 0) {
    s = all.substr(0, all.size() / 2);
    t = all.substr(all.size() / 2);
  } else {
    s = all.substr(0, all.size() / 2);
    t = all.substr(all.size() / 2 + 1);
  }

  string tRev = t;
  reverse(tRev.begin(), tRev.end());
  std::reverse(s.begin(), s.end());

  RollingHash sHash(s, 10007);
  RollingHash tRevHash(tRev, 10007);

  vector<int> dp(t.size() + 10, INT32_MAX / 2);

  if (s == t) {
    return 0;
  }

  int beginItr = -1;
  for (int i = 1; i <= t.size(); i++) {
    // string tgt = t.substr(0, i);
    // reverse(tgt.begin(), tgt.end());
    if (sHash.GetHash(0, i-1) == tRevHash.GetHash(tRev.size()-i, tRev.size()-1)) {
      beginItr     = i - 1;
      dp[beginItr] = i * i;
      break;
    }
  }

  if (beginItr == -1) {
    return -1;
  }

  for (int i = beginItr + 1; i < t.size(); i++) {
    if(i%1000==0){
      cerr << i << endl;
    }
    
    for (int j = 0; j < i; j++) {
      // string tgt = t.substr(j + 1, i - j);
      // reverse(tgt.begin(), tgt.end());
      // if (s.substr(j + 1, i - j) == tgt) {
      //   if (i - j == 1) {
      //     UpdateMin(dp[i], dp[j]);
      //   } else {
      //     UpdateMin(dp[i], dp[j] + (i - j) * (i - j));
      //   }
      // }
      if (sHash.GetHash(j+1, i) == tRevHash.GetHash(tRev.size()-i-1, tRev.size()-j-2)) {
        if (i - j == 1) {
          UpdateMin(dp[i], dp[j]);
        } else {
          UpdateMin(dp[i], dp[j] + (i - j) * (i - j));
        }
      }
    }
  }

  if (dp[t.size() - 1] == INT32_MAX / 2) {
    return -1;
  } else {
    return dp[t.size() - 1];
  }
}

int main() {
  cout << std::fixed << std::setprecision(16);
  cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int cnt = 0;
  while (true) {
    cerr << cnt;
    string s;
    cin >> s;
    if (s == "#") break;
    cerr << "solving" << endl;
    cout << solve(s) << endl;
    cnt++;
  }

  return 0;
}