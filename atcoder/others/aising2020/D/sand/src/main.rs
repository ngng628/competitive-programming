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

fn popcount(n:u32) -> u32 {
    let mut cnt = 0;
    let mut tmp = n;
    while tmp != 0 {
        cnt += if tmp % 2 == 0 { 0 } else { 1 };
        tmp /= 2;
    }

    return cnt;
}

fn f(mut x:u32) -> u32 {
    let mut cnt = 0;
    while x != 0 {
        x = x % popcount(x);
        cnt += 1;
    }

    return cnt;
}

fn main() {
    let n: u32 = read();
    let x: String = read();

    for i in 0..100000 {
        println!("f({:b}) = {}", i, f(i));
    }
}
