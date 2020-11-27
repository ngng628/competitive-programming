// 立っているビットの数を返す。( O(loglogx) )
__builtin_popcount(unsigned x)
__builtin_popcountl(long x)
__builtin_popcountll(long long x)
assert(__builtin_popcount(0b10111000) == 4);

// 立ってるビット数の偶奇を返す。(popcount % 2 に相当) ( O(loglogx) )
__builtin_parity(unsigned x)
__builtin_parityl(long x)
__builtin_parityll(long long x)
assert(__builtin_parity(0b10001) == 0);
assert(__builtin_parity(0b1010111) == 1);

// 2進で表した場合に小さい方から何桁目に初めて1が現れるか。1-based
__builtin_ffs(unsigned x)
__builtin_ffsl(long x)
__builtin_ffsll(long long x)
assert(__builtin_ffs(0b111) == 1);
assert(__builtin_ffs(0b1000) == 4);
assert(__builtin_ffs(0b0) == 0);

// 2進で表した場合に左側にいくつ0を埋める必要があるか (the number of leading 0-bits in x)
// __builtin_clz(0) は未定義
__builtin_clz(unsigned x)
__builtin_clzl(long x)
__builtin_clzll(long long x)
assert(__builtin_clz(0b111) == 29); // sizeof(unsigned) == 32 bit の場合

// 2進で表した場合に、1の位からいくつ0が連なっているか (the number of trailing 0-bits in x)
// __builtin_clz(0) は未定義
__builtin_ctz(unsigned x)
__builtin_ctzl(long x)
__builtin_ctzll(long long x)
assert(__builtin_ctz(0b1000) == 3);
