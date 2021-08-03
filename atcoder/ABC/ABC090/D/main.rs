use proconio::input;

// #[fastout]
fn main() {
   input! {
      n: i64,
      k: i64,
   }

   if k == 0 {
      println!("{}", n * n);
      std::process::exit(0);
   }

   let mut ans = 0;
   for b in k+1..=n as i64 {
      let r = (n + 1) / b;
      let mut d = (b - k) * r;
      let l = k + b*r;
      let r = n;
      if l <= r {
         d += r - l + 1;
      }

      ans += d;
   }

   println!("{}", ans);
}