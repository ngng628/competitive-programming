use proconio::{fastout, input};

#[fastout]
fn main() {
   input! {
      d: u32,
      n: u64
   }
   if n == 100 {
      println!("{}", 100u64.pow(d) * (n + 1));
   }
   else {
      println!("{}", 100u64.pow(d) * n);
   }
}
