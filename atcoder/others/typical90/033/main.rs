use proconio::{fastout, input};

fn ceil(a: u32, b: u32) -> u32 {
   (a + b - 1) / b
}

#[fastout]
fn main() {
   input! {
      h: u32,
      w: u32,
   }

   println!("{}", 
      if w == 1 || h == 1 {
         h*w
      } else {
         ceil(h, 2) * ceil(w, 2)
      }
   );
}
