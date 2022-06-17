namespace BitOperations {
   constexpr int Popcount(int x) { return __builtin_popcountll(x); }
   constexpr int Parity(int x) { return __builtin_parityll(x); }
   constexpr int Ffs(int x) { return __builtin_ffsll(x); }
   constexpr int Clz(int x) { return __builtin_clzll(x); }
   constexpr int Ctz(int x) { return __builtin_ctzll(x); }

   constexpr int Bit(int x) { return 1LL << x; }
   constexpr bool Isbit(int x) { return x and (x & -x) == x; }
   constexpr int Msb(int x) { return x == 0 ? -1 : 63 - Clz(x); }
   constexpr int Lsb(int x) { return x == 0 ? 64 : Ctz(x); }

   /**
    * @brief n - 1 桁目までの bit が全て立ったビット列を返します
    * @param n 立たせるビットの個数
    * @return n - 1 桁目までの bit が全て立ったビット列
    * @details (1 << n) - 1 を返します
    */
   constexpr int Allbit(int n) { return (1LL << n) - 1; }

   /**
    * @brief x の i 桁目が立っているかを判定します
    * @param x 対象のビット列
    * @param i i 桁目 (0-index)
    * @return i 桁目が立っているか
    */
   constexpr bool Stand(int x, int i) { return x & Bit(i); }

   /**
    * @brief floor(log2(x)) を正確に求めます
    * @param x 対象の数
    * @return floor(log2(x))
    */
   constexpr int Log2i(int x) { return Msb(x); }
}
using namespace BitOperations;
