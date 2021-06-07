use proconio::{fastout, input};
use petgraph::Directed;
use petgraph::algo::dijkstra;
use petgraph::graph::{NodeIndex, Graph};

#[fastout]
fn main() {
   input! {
      k: usize
   }

   let mut edges = Vec::new();
   for i in 0..k {
      edges.push( (i, (i + 1) % k, 1) );
      edges.push( (i, (10*i) % k, 0) );
   }
   let graph = Graph::<usize, usize, Directed, usize>::from_edges(&edges);
   let dist = dijkstra(&graph, 1.into(), None, |e| *e.weight());

   println!("{}", dist[&NodeIndex::new(0)] + 1);
}