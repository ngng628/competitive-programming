# include <bits/stdc++.h>
using namespace std;

struct Prime {
   Prime() : n_max(0) {}
   // O ( N loglog(N) )
   Prime(int n) : n_max(n), table(n+1, true), osak(n+1) {
      iota(osak.begin(), osak.end(), 0);
      osak[0] = 1;
      if(n >= 0) table[0] = false;
      if(n >= 1) table[1] = false;
      for(int i = 2; i * i <= n; i++) {
         if (not table[i]) continue;
         lst.push_back(i);
         for(int k = i + i; k <= n; k += i) {
            table[k] = false;
            osak[k] = i;
         }
      }
   }

   // n <= n_max のとき: O(1)
   // それ超えのとき: O( sqrt(N) )
   bool is(const int n) {
      if (n <= n_max) return table[n];
      if (n <= 4) return n == 2 || n == 3;
      if (n % 2 == 0 || n % 3 == 0 || (n % 6 != 1 && n % 6 != 5)) return false;
      for (int i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
      return true;
   }

   // O( sqrt(N) )
   map<int, int> factor(int n) {
      if (n == 1) {
         map<int, int> one;
         one[1] = 1;
         return one;
      }
      if (n <= n_max) return impl_factor_fast(n);
      map<int, int> ret;
      for (int i = 2; i * i <= n; i++) {
         while (n % i == 0) {
            ret[i]++;
            n /= i;
         }
      }
      if (n != 1) ret[n] = 1;
      return ret;
   }

   // O( log(N) )
   map<int, int> impl_factor_fast(int n) {
      map<int, int> ret;
      while (n != 1) {
         int p = osak[n];
         ret[p]++;
         n /= p;
      }
      return ret;
   }

   // O( len(v) log(v_max) )
   bool to(vector<int> v) {
      unordered_set<int> s;
      for (auto& n : v) {
         while (n != 1) {
            int p = osak[n];
            if (s.find(p) != s.end()) return false;
            else s.insert(p);
            while (n % p == 0) n /= p;
         }
      }
      return true;
   }

   const int n_max;
   vector<bool> table;
   vector<int> osak;
   vector<int> lst;
} PRIME(123456);

void Main(int n) {
   int cnt = 0;
   for (int i = n+1; i <= 2*n; ++i) {
      if (PRIME.is(i)) cnt++;
   }
   cout << cnt << endl;
}

int main() {
   while (true) {
      int n;
      cin >> n;
      if (!n) break;
      Main(n);
   }
}
