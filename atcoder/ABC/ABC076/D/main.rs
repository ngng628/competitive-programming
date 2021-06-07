use proconio::{fastout, input};
macro_rules! chmin { ($base:expr, $($cmps:expr),+ $(,)*) => {{ let cmp_min = min!($($cmps),+); if $base > cmp_min { $base = cmp_min; true } else { false } }}; }
macro_rules! min { ($a:expr $(,)*) => {{ $a }}; ($a:expr, $b:expr $(,)*) => {{ std::cmp::min($a, $b)}}; ($a:expr, $($rest:expr),+ $(,)*) => {{ std::cmp::min($a, min!($($rest),+)) }}; }

#[fastout]
fn main() {
   input! {
      n: usize,
      t: [u32; n],
      v: [u32; n],
   }
   let sum_time = t.iter().sum::<u32>();
   let mut dp = vec![10000000000.0f64; (2*sum_time + 1) as usize];

   dp[0] = 0.0;
   dp[2*sum_time as usize] = 0.0;
   let mut acc = 0;
   for i in 0..n {
      for j in 0..=(2*t[i]) as usize {
         chmin!(dp[acc + j], v[i] as f64);
      }
      acc += 2*t[i] as usize;
   }

   for i in 1..=2*sum_time as usize {
      chmin!(dp[i], dp[i-1] + 0.5);
   }
   for i in (0..=(2*sum_time - 1) as usize).rev() {
      chmin!(dp[i], dp[i+1] + 0.5);
   }

   let mut ans = 0.0;
   for i in 0..=(2*sum_time - 1) as usize {
      ans += (dp[i] + dp[i+1]) * 0.25;
   }

   println!("{:.4}", ans);
}