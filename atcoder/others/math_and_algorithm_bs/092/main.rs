use proconio::input;

fn main() {
   input! { n: i64 }

   let mut i = 1;
   let mut ans = 100000000000000;
   while i * i <= n {
      if n % i == 0 {
         let t = 2*(i + (n / i));
         if t < ans {
            ans = t;
         }
      }
      i += 1;
   }

   println!("{}", ans);
}