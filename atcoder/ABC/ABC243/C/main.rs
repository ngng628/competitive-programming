use proconio::input;
use std::collections::BTreeMap;

fn main() {
   input! {
      n: usize,
      pos: [(usize, usize); n],
      s: proconio::marker::Chars
   }

   let mut max_right = vec![-1; n];
   let mut min_left = vec![1010101010; n];
   let mut f = BTreeMap::new();
   for i in 0..n {
      let x = pos[i].0;
      if f.get(&pos[i].1) == None {
         f.insert(pos[i].1, f.len());
      }
      let y = *f.get(&pos[i].1).unwrap();
      if s[i] == 'L' {
         max_right[y] = std::cmp::max(max_right[y], x as i32);
      }
      if s[i] == 'R' {
         min_left[y] = std::cmp::min(min_left[y], x as i32);
      }
   }

   let ans = (0..n).filter(|&y| min_left[y] < max_right[y]).count();
   println!("{}", if ans == 0 { "No" } else { "Yes" });
}