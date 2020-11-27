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

fn is_prime(n:i32) -> bool {
    let mut i:i32 = 2;
    while i*i <= n {
        if n % i == 0 {
            return false;
        }
        i += 1;
    }
    return true;
}

fn main() {
    loop {
        let n:i32 = read();
        if n == 0 {
            break;
        }
        let ans = ((n+1)..(2*n+1)).filter(|&x| is_prime(x)).count();
        println!("{}", ans);
    }
}
