use proconio::{fastout, input};

#[fastout]
fn main() {
   input! {
      m1: u32, _d1: u32,
      m2: u32, _d2: u32
   }
   println!("{}", (m2 - m1 == 1) as u8);
}