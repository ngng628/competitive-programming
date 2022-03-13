use proconio::input;

fn main() {
   input! { mut v: i32, a: i32, b: i32, c: i32 }

   let mut ans = 'F';
   while v >= 0 {
      v -= if ans == 'F' { a } else if ans == 'M' { b } else { c };
      if v < 0 {
         break;
      }
      ans = if ans == 'F' { 'M' } else if ans == 'M' { 'T' } else { 'F' };
   }

   println!("{}", ans);
}