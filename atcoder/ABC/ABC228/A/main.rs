use proconio::{fastout, input};

#[fastout]
fn main() {
   input! {
      s: u32,
      t: u32,
      x: u32,
   }

   let mut mm = 0;
   let mut ss = 0;
   let mut ans = "No";
   let mut flag = false;
   for _ in 0..1000000 {
      // 電気の付け消し
      if mm == s && ss == 0 {
         flag = true;
      }
      if mm == t && ss == 0 {
         flag = false;
      }

      // 電気の確認
      if mm == x && ss == 30 {
         if flag {
            ans = "Yes";
         }
      }

      // 時を進める
      ss += 1;
      if ss == 60 {
         mm += 1;
         ss = 0;
      }
      if mm == 24 {
         mm = 0;
      }
   }

   println!("{}", ans);
}
