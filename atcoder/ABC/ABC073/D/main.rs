use itertools::Itertools;
use std::cmp::min;
use proconio::{fastout, input, marker::Usize1};
use petgraph::algo::dijkstra;
use petgraph::graph::{NodeIndex, UnGraph};

#[fastout]
fn main() {
   input! {
      n: usize, m: usize, r: usize,
      rs: [Usize1; r],
      edges: [(Usize1, Usize1, usize); m]
   }

   let graph = UnGraph::<usize, usize, usize>::from_edges(&edges);
   let dists = (0..n).map(|s| dijkstra(&graph, NodeIndex::new(s), None, |e| *e.weight())).collect::<Vec<_>>();

   let mut ans = std::usize::MAX;
   for indices in (0..r).permutations(r) {
      let mut dist = 0;
      for i in 0..r-1 {
         let a = rs[indices[i]];
         let b = rs[indices[i+1]];
         dist += dists[a][&NodeIndex::new(b)];
      }
      ans = min(ans, dist);
   }

   println!("{}", ans);
}