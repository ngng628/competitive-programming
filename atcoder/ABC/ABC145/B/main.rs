use proconio::input;

fn main() {
   input! {
      n: usize,
      s: String
   }

   println!("{}", if n & 1 == 0 && s[..n/2] == s[n/2..] { "Yes" } else { "No" });
}
