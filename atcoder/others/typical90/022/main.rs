use proconio::{fastout, input};
use num::integer::gcd;

#[fastout]
fn main() {
   input! {
      a: u64,
      b: u64,
      c: u64,
   }

   let g = gcd(a, gcd(b, c));
   println!("{}", a / g + b / g + c / g - 3)
}