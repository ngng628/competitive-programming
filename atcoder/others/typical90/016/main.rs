use proconio::{fastout, input};

#[fastout]
fn main() {
   input! {
      n: i64,
      a: i64,
      b: i64,
      c: i64,
   }

   let mut ans = 1001001001001001001;
   for i in 0..10000 {
      for j in 0..10000 {
         let t = n - a*i - b*j;
         if t < 0 {
            continue;
         }
         if t % c == 0 {
            ans = std::cmp::min(ans, i + j + t / c);
         }
      }
   }

   println!("{}", ans);
}