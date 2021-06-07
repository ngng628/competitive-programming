use proconio::{fastout, input};

#[fastout]
fn main() {
   input! {
      n: String
   }

   println!("{}", if n == n.chars().rev().collect::<String>() {
      "Yes"
   }
   else {
      "No"
   });
}