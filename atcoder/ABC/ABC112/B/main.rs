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
    let n: usize = read();
    let limit: u32 = read();
    let route: Vec<(u32, u32)> = (0..n).map(|_| (read(), read())).collect();

    let ans = route.into_iter().filter(|x| x.1 <= limit).fold(4294967295, |m, p| p.0.min(m));
    println!("{}", if ans == 4294967295 { "TLE".to_string() } else { ans.to_string() });
}
