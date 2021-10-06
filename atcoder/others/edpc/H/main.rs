use proconio::{fastout, input};
use proconio::marker::Chars;
const MOD: i32 = 1000000007;

#[fastout]
fn main() {
   input! {
      h: usize,
      w: usize,
      a: [Chars; h]
   }

   let mut dp = vec![vec![0; w]; h];
   dp[0][0] = 1;
   for (i, j) in (0..h*w).map(|nd| (nd / w, nd % w)) {
      if a[i][j] == '#' {
         dp[i][j] = 0;
         continue;
      }
      if i >= 1 {
         dp[i][j] += dp[i - 1][j];
      }
      if j >= 1 {
         dp[i][j] += dp[i][j - 1] ;
      }
      dp[i][j] %= MOD;
   }

   println!("{}", dp.last().unwrap().last().unwrap());
}