use proconio::{fastout, input};

#[fastout]
fn main() {
   input! {
      n: usize,
      xy: [(i64, i64); n]
   }

   let mut x: Vec<i64> = xy.iter().map(|p| p.0).collect();
   let mut y: Vec<i64> = xy.iter().map(|p| p.1).collect();

   x.sort();
   y.sort();

   let a = x[x.len() / 2];
   let b = y[y.len() / 2];

   let ans = xy.iter().fold(0, |s, (x, y)| s + (x - a).abs() + (y - b).abs());

   println!("{}", ans);
}