use proconio::{fastout, input};

const MOD: u64 = 998244353;

#[fastout]
fn main() {
   input! {
      n: u64,
      k: u64,
      m: u64
   }
   println!("{}", if m % MOD == 0 { 0 } else { modpow(m, modpow(k, n, MOD - 1), MOD) });
}

fn modpow(a: u64, b: u64, m: u64) -> u64 {
   if b == 0 {
      return 1;
   }

   let mut res = modpow(a % m, b / 2, m);
   res *= res;
   res %= m;
   if b % 2 == 1 {
      res *= a % m;
      res %= m;
   }

   return res;
}
