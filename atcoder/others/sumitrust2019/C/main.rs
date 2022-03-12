use proconio::input;

fn main() {
   input! { x: usize }
   let a = vec![0, 100, 101, 102, 103, 104, 105];
   let n = a.len() - 1;

   let mut dp = vec![vec![false; x + 1]; n + 1];
   dp[0][0] = true;
   for i in 1..=n {
      for j in 0..=x {
         dp[i][j] |= dp[i - 1][j];
         if j >= a[i] {
            dp[i][j] |= dp[i - 1][j - a[i]] | dp[i][j - a[i]];
         }
      }
   }

   println!("{}", if dp[n][x] { 1 } else { 0 });
}