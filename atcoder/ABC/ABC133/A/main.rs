use proconio::input;
use std::cmp::min;

fn main() {
   input! {
      n: u32,
      a: u32,
      b: u32
   }
   println!("{}", min(n*a, b));
}