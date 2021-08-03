use proconio::fastout;
use std::collections::BinaryHeap;
use std::io::*;
use std::str::FromStr;

#[fastout]
fn main() {
   let query_size: usize = read();

   let mut sum = 0;
   let mut heap = BinaryHeap::new();

   for _ in 0..query_size {
      let p: usize = read();
      match p {
         1 => {
            let x: i64 = read();
            heap.push(sum - x);
         },
         2 => {
            let x: i64 = read();
            sum += x;
         },
         3 => {
            let x = heap.pop().unwrap();
            println!("{}", sum - x);
         },
         _ => (),
      }
   }
}

fn read<T: FromStr>() -> T {
   let stdin = stdin();
   let stdin = stdin.lock();
   let token: String = stdin
       .bytes()
       .map(|c| c.expect("failed to read char") as char) 
       .skip_while(|c| c.is_whitespace())
       .take_while(|c| !c.is_whitespace())
       .collect();
   token.parse().ok().expect("failed to parse token")
}