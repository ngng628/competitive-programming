use proconio::{fastout, input};
use proconio::maker::Usize1;

#[fastout]
fn main() {
   input! {
      n: Usize1,
      s: String
   }
   println!("{}", if s[n] == 'o' { "Yes" } else { "No" });
}