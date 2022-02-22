use proconio::input;

fn main() {
   input! {
      n: usize,
      k: u32,
      h: [u32; n]
   }

   println!("{}", h.iter().filter(|&&hi| hi >= k).count());
}