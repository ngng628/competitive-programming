use proconio::{fastout, input};
use proconio::marker::Chars;

#[fastout]
fn main() {
   input! {
      n: usize,
      s: Chars,
      t: Chars
   }

   for i in 0..n {
      print!("{}{}", s[i], t[i]);
   }
   println!();
}