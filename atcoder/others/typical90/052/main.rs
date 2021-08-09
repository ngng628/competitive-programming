fn main() {
  proconio::input! {
    n: usize,
    a: [[u64; 6]; n]
  }
  println!("{}", (0..n).fold(1, |p, i| (p * a[i].iter().sum::<u64>()) % 1000000007));
}