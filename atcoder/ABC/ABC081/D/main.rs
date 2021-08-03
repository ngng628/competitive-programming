use proconio::{fastout, input};

fn index(i: usize) -> usize {
   i + 1
}

#[fastout]
fn main() {
   input! {
      n: usize,
      a: [i32; n]
   }
   let max_element = a.iter().enumerate().max_by_key(|(_idx, &val)| val.abs()).map(|(idx, _val)| idx).unwrap();
   println!("{}", 2*(n - 1));
   for i in max_element..n - 1 {
      // a[i+1] = a[i];
      println!("{} {}", index(max_element), index(i+1));
   }
   for i in (1..=max_element).rev() {
      // a[i-1] += a[i];
      println!("{} {}", index(max_element), index(i-1));
   }

   if a[max_element] > 0 {
      for i in 0..n-1 {
         println!("{} {}", index(i), index(i+1));
      }
   }
   else {
      for i in (1..n).rev() {
         println!("{} {}", index(i), index(i-1));
      }
   }
}