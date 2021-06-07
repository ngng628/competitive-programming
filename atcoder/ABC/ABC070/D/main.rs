use proconio::{fastout, input};
use std::collections::VecDeque;

#[fastout]
fn main() {
   input! {
      n: usize,
      edges: [(usize, usize, i64); n-1],
      q: usize,
      k: usize,
      pairs: [(usize, usize); q],
   }

   let mut graph = vec![Vec::new(); n]; 
   for (a, b, c) in edges {
      graph[a].push((b, c));
      graph[b].push((a, c));
   }

   for from in 0..n {
      println!("{}", graph[from]);
      println!("");
   }

   // let mut que = VecDeque::new();
   // que.push_front(k);
   // let mut dist = vec![-1; n];
   // dist[k] = 0;
   // while let Some(from) = que.pop_back() {
   //    for (to, cost) in graph[from]x {
   //       if dist[to] != -1 { continue; }
   //       dist[to] = dist[from] + cost;
   //       que.push_front(to);
   //    }
   // }

}