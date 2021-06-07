use proconio::{fastout, input};
use proconio::marker::Chars;

const MOD: i32 = 1_000_000_007;

#[fastout]
fn main() {
   input!{
     n: usize,
     s1: Chars,
     s2: Chars,
   }

   let mut patterns = Vec::new();
   let mut i = if s1[0] == s2[0] { patterns.push(1); 1 } else { patterns.push(0); 2 };
   while i < n {
      if s1[i] == s2[i] {
         patterns.push(1);
      }
      else {
         patterns.push(0);
         i += 1;
      }
      i += 1;
   }

   let mut ans: u64 = 1;
   for i in 0..patterns.len() {
     if i == 0 {
       if patterns[i] == 0 { ans *= 6; }
       else { ans *= 3; }
       continue;
     }

     if patterns[i] == 0 {
       if patterns[i-1] == 0 { ans *= 3; }
       else { ans *= 2; }
     }
     else { // patterns[i] == 1
       if patterns[i-1] == 0 { ans *= 1; }
       else { ans *= 2; }
     }
     ans %= MOD as u64;
   }

   println!("{}", ans);
}