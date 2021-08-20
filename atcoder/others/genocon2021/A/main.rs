use proconio::{fastout, input};

#[fastout]
fn main() {
   input! {
      m: usize,
      s: [String; m]
   }

   for i in 0..m {
      let ans = s[i].chars()
                    .rev()
                    .map(|c|
                       match c {
                          'A' => 'T',
                          'C' => 'G',
                          'G' => 'C',
                           _  => 'A'
                       }
                    )
                    .collect::<Vec<char>>();
      for c in ans.iter() {
         print!("{}", c);
      }
      println!();
   }
}