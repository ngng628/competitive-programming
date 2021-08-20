use proconio::{fastout, input};

#[fastout]
fn main() {
   input! {
      n: usize,
      mut a: [u64; n]
   }

   let tot: u64 = a.iter().sum();
   let mut b = vec![0; 2*n];
   for i in 0..n {
      b[i] = a[i];
      b[n + i] = a[i];
   }

   let mut ans = false;
   let mut right = 0;
   let mut sum = 0;
   for left in 0..2*n {
      while right < 2*n && 10*(sum + b[right]) <= tot && right - left <= n {
         sum += b[right];
         right += 1;
      }

      if 10*sum == tot {
         ans = true;
         break;
      }

      if right == left {
         right += 1;
      }
      else {
         sum -= b[left];
      }
   }

   println!("{}", if ans { "Yes" } else { "No" } );
}