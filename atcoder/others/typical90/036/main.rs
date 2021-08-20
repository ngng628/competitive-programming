use proconio::{fastout, input};
use proconio::marker::Usize1;

#[fastout]
fn main() {
   input! {
      n: usize,
      q: usize,
      xy: [(i64, i64); n],
      query: [Usize1; q]
   }

   let x: Vec<i64> = (0..n).map(|i| xy[i].0 - xy[i].1).collect();
   let y: Vec<i64> = (0..n).map(|i| xy[i].0 + xy[i].1).collect();

   let x_max = x.iter().fold(std::i64::MIN, |acc, &i| acc.max(i));
   let x_min = x.iter().fold(std::i64::MAX, |acc, &i| acc.min(i));
   let y_max = y.iter().fold(std::i64::MIN, |acc, &i| acc.max(i));
   let y_min = y.iter().fold(std::i64::MAX, |acc, &i| acc.min(i));

   for index in query {
      let ans = std::i64::MIN
               .max((x[index] - x_max).abs())
               .max((x[index] - x_min).abs())
               .max((y[index] - y_max).abs())
               .max((y[index] - y_min).abs());
      println!("{}", ans);
   }
}