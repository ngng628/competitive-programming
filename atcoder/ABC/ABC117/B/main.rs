use proconio::{fastout, input};

#[fastout]
fn main() {
   input! {
      n: usize,
      l: [u32; n]
   }

   let l_max = l.iter().max().unwrap();
   let s = l.iter().sum::<u32>() - l_max;
   println!("{}", if l_max < &s { "Yes" } else { "No" });
}
