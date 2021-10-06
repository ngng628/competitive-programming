use proconio::{fastout, input};
use std::cmp::max;

#[fastout]
fn main() {
   input! {
      n: usize,
      abc: [[u64; 3]; n]
   }

   let mut dp = vec![[0; 3]; n + 1];
   for i in 1..=n {
      for act in 0..3 {
         dp[i][act] = max(dp[i - 1][(act + 1) % 3], dp[i - 1][(act + 2) % 3]) + abc[i - 1][act];
      }
   }

   println!("{}", dp[n].iter().max().unwrap());
}