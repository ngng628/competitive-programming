use proconio::{fastout, input};

const MOD: u64 = 998_244_353;

#[fastout]
fn main() {
   input! {
      n: usize,
      a: [u64; n]
   }

   let mut dp = vec![vec![0u64; 10]; n];
   dp[0][a[0] as usize] = 1;
   for i in 1..n {
      for r in 0..=9 {
         dp[i][(r + a[i] as usize) % 10] += dp[i - 1][r];
         dp[i][(r + a[i] as usize) % 10] %= MOD;

         dp[i][(r * a[i] as usize) % 10] += dp[i - 1][r];
         dp[i][(r * a[i] as usize) % 10] %= MOD;
      }
   }

   for k in 0..=9 {
      println!("{}", dp[n - 1][k]);
   }
}