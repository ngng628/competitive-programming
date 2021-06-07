use proconio::{fastout, input};
use std::cmp::{min, max};

#[fastout]
fn main() {
   input!{
      a: i32,
      b: i32,
      c: i32,
      d: i32,
   }

   let lower = max(a, c);
   let upper = min(b, d);

   println!("{}", max(0, upper - lower));
}