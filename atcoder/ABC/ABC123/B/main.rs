use std::io::*;
use std::str::FromStr;

fn read<T: FromStr>() -> T {
    let stdin = stdin();
    let stdin = stdin.lock();
    let token: String = stdin
        .bytes()
        .map(|c| c.expect("failed to read char") as char) 
        .skip_while(|c| c.is_whitespace())
        .take_while(|c| !c.is_whitespace())
        .collect();
    token.parse().ok().expect("failed to parse token")
}

fn main() {
    let mut a: Vec<usize> = (0..5).map(|_| read()).collect();
    a.sort_unstable_by(|x, y| y.cmp(x));

    let mut ans: usize = 0;
    for i in 0..4 {
        if a[i] % 10 == 0 {
            ans += a[i];
        } else {
            ans += ((a[i] >> 1) << 1) + 10;
        }
    }

    println!("{}", ans + a[4]);
}
