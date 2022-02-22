use proconio::input;

fn main() {
   input! { n: u32 }
   let odd = (1..=n).filter(|i| i % 2 == 1).count();
   let ans = odd as f64 / n as f64;
   println!("{:.*}", 7, ans);
}