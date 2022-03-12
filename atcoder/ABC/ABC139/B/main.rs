use proconio::{fastout, input};

fn f(a:u32, size: usize) -> u32 {
   match size {
      0 => 0,
      1 => a,
      _ => (size as u32 - 1)*(a - 1) + a
   }
}

#[fastout]
fn main() {
   input! { a: u32, b: u32 }

   let mut ans = 0;
   for i in 0..=40 {
      if f(a, i) >= b {
         ans = i;
         break;
      }
   }
   if b == 1 {
      ans = 0;
   }

   println!("{}", ans);
}