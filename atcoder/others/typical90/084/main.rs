use proconio::{fastout, input};
use proconio::marker::Chars;

#[fastout]
fn main() {
   input! {
      n: usize,
      s: Chars
   }

   let a: Vec<usize> = s.iter().map(|&c| if c == 'o' { 0 } else { 1 }).collect();
   
   let mut ans = 0;
   let mut right = 0;
   let mut cnt = vec![0; 2];
   for left in 0..n {
      while right < n {
         cnt[a[right]] += 1;
         if cnt[0] * cnt[1] == 0 {
            right += 1;
         }
         else {
            break;
         }
      }
      ans += right - left;

      if right < n {
         cnt[a[right]] -= 1;
      }
      if left == right {
         right += 1;
      }
      else {
         cnt[a[left]] -= 1;
      }
   }

   println!("{}", n*(n - 1) / 2 - (ans - n));
}