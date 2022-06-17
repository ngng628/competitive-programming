# include <iterator>
# include <algorithm>
# include <numeric>
# include <vector>
using namespace std;

template <class T>
struct StaticRangeSum {
   /**
    * @brief デフォルトコンストラクタ
    */
   StaticRangeSum() = default;

   /**
    * @brief コンストラクタ
    * @param seq 累積和を取りたい配列
    */
   explicit StaticRangeSum(const vector<T>& seq) {
      const int n = len(seq);
      sums.resize(n + 1);
      sums[0] = 0;
      partial_sum(all(seq), begin(sums) + 1);
   }

   /**
    * @brief a[0] + ... + a[n - 1] を求めます。
    * @param n 終端の仕切り
    * @return a[0] + ... + a[n - 1]
    */
   T get(int n) const {
      return get(0, n);
   }

   /**
    * @brief a[l] + ... + a[r - 1] を求めます。
    * @param l 始端の仕切り
    * @param r 終端の仕切り
    * @return a[l] + ... + a[r - 1]
    */
   T get(int l, int r) const {
      assert(0 <= l and l < r and r <= len(sums) - 1);
      return sums[r] - sums[l];
   }

   /**
    * @brief a[0] + ... + a[n - 1] を求めます。
    * @param n 終端の仕切り
    * @return a[0] + ... + a[n - 1]
    */
   T operator ()(int n) const { return get(n); }

   /**
    * @brief a[l] + ... + a[r - 1] を求めます。
    * @param l 始端の仕切り
    * @param r 終端の仕切り
    * @return a[l] + ... + a[r - 1]
    */
   T operator ()(int l, int r) const { return get(l, r); }

   /**
    * @brief a[0] + ... + a[x] <= val の二分探索をします。 
    * @param val 検索する値
    * @return a[0] + ... + a[x] <= val の上界
    */
   int lower_bound(T val) const {
      return distance(cbegin(sums) + 1, lower_bound(cbegin(sums) + 1, sums.cend(), val));
   }

   /**
    * @brief a[0] + ... + a[x] <= val の二分探索をします。 
    * @param val 検索する値
    * @return a[0] + ... + a[x] <= val の下界
    */
   int upper_bound(T val) const {
      return distance(cbegin(sums) + 1, upper_bound(cbegin(sums) + 1, sums.cend(), val));
   }

   vector<T> sums;
};