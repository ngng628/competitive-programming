use proconio::input;
use std::collections::BTreeSet;
use std::iter::FromIterator;

fn main() {
   input! {
      n: usize,
      a: [u32; n],
      b: [u32; n]
   }

   let ans1 = (0..n).filter(|&i| a[i] == b[i]).count();
   println!("{}", ans1);
   let sta = BTreeSet::from_iter(a.iter());
   let stb = BTreeSet::from_iter(b.iter());
   let mut ans2 = 0;
   for e in sta.iter() {
      if stb.contains(e) {
         ans2 += 1;
      }
   }

   println!("{}", ans2 - ans1);
}