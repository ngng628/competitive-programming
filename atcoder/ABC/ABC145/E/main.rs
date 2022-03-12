use proconio::{fastout, input};
use std::cmp::max;

#[fastout]
fn main() {
   input! {
      n: usize,
      time_limit: usize,
      ab0: [(u32, u32); n]
   }
   let ab: Vec<(u32, u32)> = (0..=n).map(|i| if i == 0 { (0, 0) } else { ab0[i - 1] }).collect();

   let mut dp_left = vec![vec![0; time_limit + 1]; n + 1];
   let mut dp_right = vec![vec![0; time_limit + 1]; n + 2];
   for i in 1..=n {
      for t in 0..=time_limit {
         dp_left[i][t] = dp_left[i - 1][t];
         if t >= ab[i].0 as usize {
            dp_left[i][t] = max(dp_left[i][t], dp_left[i - 1][t - ab[i].0 as usize] + ab[i].1);
         }
         let j = n - i + 1;
         dp_right[j][t] = dp_right[j + 1][t];
         if t >= ab[j + 1].0 as usize {
            dp_right[j][t] = max(dp_right[j][t], dp_right[j + 1][t - ab[j + 1].0 as usize] + ab[j + 1].1);
         }
      }
   }

   let mut ans = 0;
   for i in 1..=n {
      for t in 0..time_limit {
         ans = max(ans, dp_left[i - 1][t] + dp_right[i][time_limit - 1 - t] + ab[i].1);
      }
      ans = max(ans, dp_left[i - 1][time_limit]);
   }
   ans = max(ans, dp_left[n][time_limit]);

   println!("{}", ans);
}