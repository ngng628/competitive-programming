use proconio::input;
use std::cmp::max;

fn main() {
   input! {
      h: usize, w: usize, n_items: usize,
      items: [(usize, usize, u64); n_items]
   }
   let mut a = vec![vec![0; w + 1]; h + 1];
   for &(i, j, c) in items.iter() {
      a[i][j] = c;
   }

   let mut dp = vec![vec![vec![0; 4]; w + 1]; h + 1];
   for i in 1..=h {
      for j in 1..=w {
         for k in 0..=3 {
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][3]);
            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
            if k >= 1 {
               dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][3] + a[i][j]);
               dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + a[i][j]);
            }
         }
      }
   }

   println!("{}", dp[h][w][3]);
}