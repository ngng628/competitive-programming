use proconio::{fastout, input};

#[fastout]
fn main() {
   input! {
      h: usize, w: usize,
      a: [[i64; w]; h],
      b: [[i64; w]; h],
   }

   let mut diff = vec![vec![0i64; w]; h];
   for (i, j) in (0..h*w).map(|i| (i / w, i % w)) {
      diff[i][j] = b[i][j] - a[i][j];
   }

   let mut cnt = 0;
   for (i, j) in (0..h*w).map(|i| (i / w, i % w)) {
      if i == h - 1 || j == w - 1 {
         continue;
      }
      if diff[i][j].abs() > 0 {
         let d = diff[i][j];
         diff[i][j] -= d;
         diff[i+1][j] -= d;
         diff[i][j+1] -= d;
         diff[i+1][j+1] -= d;
         cnt += d.abs();
      }
   }

   let mut can = true;
   for (i, j) in (0..h*w).map(|i| (i / w, i % w)) {
      if diff[i][j].abs() > 0 {
         can = false;
         break;
      }
   }

   if can {
      println!("Yes");
      println!("{}", cnt);
   }
   else {
      println!("No");
   }
}