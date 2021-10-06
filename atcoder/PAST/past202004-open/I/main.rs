use proconio::{fastout, input};
use std::cmp::max;

#[fastout]
fn main() {
   input! {
      h: usize,
      w: usize,
      a: [[i64; w]; h]
   }

   // dp[y][x][k] = 区画 (y, x) までで、魚を全体で k 匹釣ったときの幸福度の最大値
   let mut dp = vec![vec![vec![0; w + h + 1]; w]; h];
   dp[0][0][1] = a[0][0];
   for y in 0..h {
      for x in 0..w {
         for k in 0..w + h + 1 {
            // 区画 (y, x) で魚を釣る場合
            if k >= 1 {
               if y >= 1 {
                  dp[y][x][k] = max(dp[y][x][k], dp[y-1][x][k-1] + a[y][x]);
               }
               if x >= 1 {
                  dp[y][x][k] = max(dp[y][x][k], dp[y][x-1][k-1] + a[y][x]);
               }
            }
            // 区画 (y, x) で魚を釣らない場合
            if y >= 1 {
               dp[y][x][k] = max(dp[y][x][k], dp[y-1][x][k]);
            }
            if x >= 1 {
               dp[y][x][k] = max(dp[y][x][k], dp[y][x-1][k]);
            }
         }
      }
   }

   for k in 1..=(h + w - 1) {
      println!("{}", dp[h - 1][w - 1][k]);
   }
}