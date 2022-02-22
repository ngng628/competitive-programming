use proconio::{fastout, input};
use proconio::marker::Usize1;
use petgraph::unionfind::UnionFind;

#[fastout]
fn main() {
   input! {
      n: usize,
      m: usize,
      xyz: [(Usize1, Usize1, u32); m]
   }

   let mut ut = UnionFind::new(n);
   for &(x, y, _z) in xyz.iter() {
      ut.union(x, y);
   }

   let mut labels = ut.into_labeling();
   labels.sort();
   labels.dedup();
   println!("{}", labels.len());
}
