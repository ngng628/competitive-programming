use proconio::{fastout, input};
use std::cmp::{Ordering, min};
use num::clamp;

#[fastout]
fn main() {
   input! {
      n: usize,
      mut a: [i64; n],
      q: usize,
      b:[i64; q]
   }
   a.sort();

   for rate in b.iter() {
      let ub = a.upper_bound(rate);
      let ans = min((a[clamp(ub, 0, n-1)] - rate).abs(), (a[clamp(ub-1, 0, n-1)] - rate).abs());
      println!("{}", ans);
   }
}

pub trait BinarySearch<T> {
   fn lower_bound(&self, x: &T) -> usize;
   fn upper_bound(&self, x: &T) -> usize;
}

impl<T: Ord> BinarySearch<T> for [T] {
   fn lower_bound(&self, x: &T) -> usize {
      let mut low = 0;
      let mut high = self.len();

      while low != high {
         let mid = (low + high) / 2;
         match self[mid].cmp(x) {
            Ordering::Less => {
               low = mid + 1;
            }
            
            Ordering::Equal | Ordering::Greater => {
               high = mid;
            }
         }
      }
      low
   }

   fn upper_bound(&self, x: &T) -> usize {
      let mut low = 0;
      let mut high = self.len();

      while low != high {
         let mid = (low + high) / 2;
         match self[mid].cmp(x) {
            Ordering::Less | Ordering::Equal => {
               low = mid + 1;
            }
            Ordering::Greater => {
               high = mid;
            }
         }
      }
      low
   }
}