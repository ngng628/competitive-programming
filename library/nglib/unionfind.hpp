# include "atcoder.hpp"

class UnionFind {
public:
   /// <summary>
   /// 0 頂点の UnionFind を作ります
   /// </summary>
   UnionFind() : _n(0) {}

   /// @brief n 頂点 0 辺の UnionFind を作ります。
   /// @param n 頂点数
   UnionFind(int n) : _n(n), parent_or_size(n, -1) {}

   /// @brief 頂点 a と頂点 b をくっつけます
   /// @param a 頂点
   /// @param b 頂点
   /// @return (a, b) の代表元
   int unite(int a, int b) {
      assert(0 <= a && a < _n);
      assert(0 <= b && b < _n);
      int x = leader(a), y = leader(b);
      if (x == y) return x;
      if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
      parent_or_size[x] += parent_or_size[y];
      parent_or_size[y] = x;
      return x;
   }

   /// @brief a と b が同じグループかを判定します
   /// @param a 頂点
   /// @param b 頂点
   /// @return a と b が同じグループか
   bool equiv(int a, int b) {
      assert(0 <= a && a < _n);
      assert(0 <= b && b < _n);
      return leader(a) == leader(b);
   }

   /// @brief 頂点 a の代表元を取得します
   /// @return 頂点 a の代表元
   int leader(int a) {
      assert(0 <= a && a < _n);
      if (parent_or_size[a] < 0) return a;
      return parent_or_size[a] = leader(parent_or_size[a]);
   }

   /// @brief 頂点 a の属するグループの大きさを取得します
   /// @return 頂点 a の属するグループの大きさ
   int size(int a) {
      assert(0 <= a && a < _n);
      return -parent_or_size[leader(a)];
   }

   /// @brief グループのリストを取得します
   /// @return 「一つの連結成分の頂点番号のリスト」のリスト
   vvi groups() {
      vi leader_buf(_n), group_size(_n);
      rep (i, _n) {
         leader_buf[i] = leader(i);
         group_size[leader_buf[i]]++;
      }
      vvi result(_n);
      rep (i, _n) result[i].reserve(group_size[i]);
      rep (i, _n) result[leader_buf[i]].pb(i);
      result.erase(
            remove_if(all(result), [&](const vi& v) { return v.empty(); }), result.end());
      return result;
   }

private:
   int _n;

   // root node: -1 * component size
   // otherwise: parent
   vi parent_or_size;
};