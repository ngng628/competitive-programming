use proconio::input;
use itertools::Itertools;

fn sq(a: i32) -> i32 {
   return a * a;
}

fn main() {
   input! {
      n: usize,
      positions: [(i32, i32); n]
   }
   
   let mut ave = 0.0;
   let mut n_loops = 0;
   for p in positions.iter().permutations(n) {
      let mut sum = 0.0;
      for i in 0..n - 1 {
         sum += ((sq(p[i + 1].0 - p[i].0) + sq(p[i + 1].1 - p[i].1)) as f64).sqrt();
      }
      ave += sum;
      n_loops += 1;
   }
   ave /= n_loops as f64;

   println!("{}", ave);
}
