use proconio::{fastout, input};

#[fastout]
fn main() {
   input! {
      n: usize,
      a: [i32; n]
   }

   // dp[i][j][k] = 1貫の皿が i 個、2貫の皿が j 個、3貫の皿が k 個

   // dp[i][j][k] += 1
   // dp[i][j][k] += dp[i - 1][j][k] * (1貫の皿が選ばれる確率)
   // dp[i][j][k] += dp[i][j - 1][k] * (2貫の皿が選ばれる確率)
   // dp[i][j][k] += dp[i][j][k - 1] * (3貫の皿が選ばれる確率)
   // dp[i][j][k] += dp[i][j][k] * (0貫の皿が選ばれる確率)
}