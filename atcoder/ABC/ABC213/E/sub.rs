use proconio::{fastout, input};
use proconio::marker::Chars;
use std::collections::VecDeque;

#[fastout]
fn main() {
   input! {
      h: usize,
      w: usize,
      s: [Chars; h]
   }

   let mut dist = vec![vec![std::u32::MAX - 1; w]; h];
   dist[0][0] = 0;
   let mut que = VecDeque::new();
   que.push_back((0, 0));

   while !que.is_empty() {
      let &(y, x) = que.front().unwrap();
      que.pop_front();
      for dy in -2..=2 as isize {
         for dx in -2..=2 as isize {
            if dy.abs() + dx.abs() >= 4 || dy + dx == 0 {
               continue;
            }

            let ny = y + dy;
            let nx = x + dx;
            if ny < 0 || ny >= h as isize || nx < 0 || nx >= w as isize {
               continue;
            }

            if dy.abs() + dx.abs() == 1 && s[ny as usize][nx as usize] != '#' {
               if dist[ny as usize][nx as usize] > dist[y as usize][x as usize] {
                  dist[ny as usize][nx as usize] = dist[y as usize][x as usize];
                  que.push_front((ny, nx));
               }
            }
            if dist[ny as usize][nx as usize] > dist[y as usize][x as usize] + 1 {
               dist[ny as usize][nx as usize] = dist[y as usize][x as usize] + 1;
               que.push_back((ny, nx));
            }
         }
      }
   }

   println!("{}", dist[h-1][w-1]);
}
