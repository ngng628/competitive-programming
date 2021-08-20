use proconio::{fastout, input};
use proconio::marker::Usize1;
use petgraph::algo::dijkstra;
use petgraph::graph::UnGraph;

#[fastout]
fn main() {
   input! {
      n: usize,
      m: usize,
      edges: [(Usize1, Usize1, usize); m]
   }

   let graph = UnGraph::<usize, usize, usize>::from_edges(&edges);
   let dist_from_start = dijkstra(&graph, 0.into(), None, |e| *e.weight());
   let dist_from_goal = dijkstra(&graph, (n - 1).into(), None, |e| *e.weight());

   for k in 0..n {
      println!("{}", dist_from_start[&k.into()] + dist_from_goal[&k.into()]);
   }
}