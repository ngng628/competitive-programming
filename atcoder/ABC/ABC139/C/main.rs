use proconio::{fastout, input};

#[fastout]
fn main() {
   input! {
      nn: usize,
      hh: [u32; nn]
   }
   let h: Vec<u32> = (0..=nn).map(|i| if i < nn { hh[i] } else { std::u32::MAX }).collect();
   let n = nn + 1;

   let mut ans = 0;
   let mut begin = 0;
   while begin < n {
      let mut end = begin;
      while end + 1 < n && h[end] >= h[end + 1] {
         end += 1;
      }
      end += 1;
      ans = std::cmp::max(ans, end - begin - 1);
      begin = end;
   }

   println!("{}", ans);
}