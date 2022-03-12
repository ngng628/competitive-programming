use proconio::{fastout, input};
use std::collections::BTreeSet as Set;

fn sqrt(n: u64) -> u64 {
   (n as f64).sqrt() as u64 + 1
}

fn f(mut n: u64, i: u64) -> u64 {
   if i == 1 {
      return n;
   }
   while n % i == 0 {
      n /= i;
   }
   return n;
}

#[fastout]
fn main() {
   input! { n: u64 }

   let mut st = Set::new();
   st.insert(n);
   if n - 1 != 1 {
      st.insert(n - 1);
   }
   for i in 1..=sqrt(n) {
      if (n - 1) % i == 0 && i != 1 {
         st.insert(i);
         st.insert((n - 1) / i);
      }
      if n % i == 0 {
         if f(n, i) % i == 1 {
            st.insert(i);
         }
      }
   }

   println!("{}", st.len());
}