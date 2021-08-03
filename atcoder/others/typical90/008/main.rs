use proconio::{fastout, input};
use proconio::marker::Chars;

const MOD: u64 = 1000000000 + 7;

#[fastout]
fn main() {
   input! {
      n: usize,
      s: Chars
   }

   let atcoder: Vec<char> = "atcoder".chars().collect();
   let m = atcoder.len();

   let mut dp = vec![vec![0u64; m+1]; n+1];
   for i in 0..=n {
      dp[i][0] = 1;
   }

   for (i, j) in (0..n*m).map(|i| (i / m + 1, i % m + 1)) {
      dp[i][j] += dp[i-1][j];
      if s[i-1] == atcoder[j-1] {
         dp[i][j] += dp[i-1][j-1];
      }
      dp[i][j] %= MOD;
   }

   println!("{}", dp[n][m]);
}