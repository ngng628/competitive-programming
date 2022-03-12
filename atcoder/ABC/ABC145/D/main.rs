use proconio::{fastout, input};
const MOD: u64 = 1_000_000_007;

fn inv(mut a: i64) -> u64 {
   let mut b = MOD as i64;
   let mut u = 1;
   let mut v = 0;

   while b > 0 {
      let t = a / b;
      a -= t * b;
      std::mem::swap(&mut a, &mut b);
      u -= t * v;
      std::mem::swap(&mut u, &mut v);
   }

   u %= MOD as i64;
   if u < 0 {
      u += MOD as i64;
   }

   return u as u64;
}

#[fastout]
fn main() {
   input! {
      x: u64,
      y: u64
   }

   let mut fact = vec![1u64; 2_000_001];
   let mut ifact = vec![1u64; 2_000_001];
   for i in 0..=2_000_000 {
      if i == 0 {
         fact[i] = 1;
         ifact[i] = 1;
      }
      else {
         fact[i] = i as u64 * fact[i - 1] % MOD;
         ifact[i] = inv(fact[i] as i64);
      }
   }

   if (x + y) % 3 != 0 {
      println!("0");
   }
   else {
      let u = (2*x as i64 - y as i64) / 3;
      let v = (2*y as i64 - x as i64) / 3;
      if u < 0 || v < 0 {
         println!("0");
      }
      else {
         println!("{}", ((fact[(u + v) as usize] * ifact[u as usize]) % MOD * ifact[v as usize]) % MOD);
      }
   }
}