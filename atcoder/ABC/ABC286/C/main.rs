use std::io::*;
use std::str::FromStr;
use std::collections::VecDeque;
use std::cmp::min;

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
    let a: u64 = read();
    let b: u64 = read();
    let s: String = read();

    let mut ans = std::u64::MAX;
    let mut dq : VecDeque<char> = s.chars().collect();
    for i in 0..n {
        let s = a * (i as u64);
        let t = b * ((0..n / 2).filter(|j| dq[*j] != dq[n - j - 1]).count() as u64);
        ans = min(ans, s + t);
        let buf = dq.pop_front().unwrap();
        dq.push_back(buf);
    }

    println!("{}", ans);
}