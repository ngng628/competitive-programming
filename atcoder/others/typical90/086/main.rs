use proconio::{fastout, input};
use proconio::marker::Usize1;

const MOD: u64 = 1000000007;

#[fastout]
fn main() {
   input! {
      n: usize,
      q: usize,
      query: [(Usize1, Usize1, Usize1, u64); q]
   }

   let mut ans = 1;
   for d in 0..60 {
      let mut cnt = 0;
      for mask in 0..(1 << n) {
         let a: Vec<u64> = (0..n).map(|i| (mask >> i) & 1).collect();   
         let mut flg = true;
         for &(x, y, z, w) in query.iter() {
            if (a[x] | a[y] | a[z]) != ((w >> d) & 1) {
               flg = false;
               break;
            }
         }
         if flg {
            cnt += 1;
         }
      }
      ans *= cnt;
      ans %= MOD;
   }

   println!("{}", ans);
}