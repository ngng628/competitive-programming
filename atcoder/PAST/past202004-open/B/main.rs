use proconio::{fastout, input};
use proconio::marker::Chars;
use std::cmp::max;

#[fastout]
fn main() {
   input!{ s: Chars }
   let a = s.iter().filter(|&c| *c == 'a').count();
   let b = s.iter().filter(|&c| *c == 'b').count();
   let c = s.iter().filter(|&c| *c == 'c').count();
   let mx = max(a, max(b, c));
   if mx == a { println!("a"); }
   if mx == b { println!("b"); }
   if mx == c { println!("c"); }
}