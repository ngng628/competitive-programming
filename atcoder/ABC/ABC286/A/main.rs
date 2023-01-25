use proconio::input;
use proconio::marker::Usize1;

fn main() {
    input! {
        n: usize, p: Usize1, q: usize, r: Usize1, s: usize,
        a: [u32; n]
    }

    let mut b = vec![0; 0];

    for i in 0..p {
        b.push(a[i]);
    }

    for i in r..s {
        b.push(a[i]);
    }

    for i in q..r {
        b.push(a[i]);
    }

    for i in p..q {
        b.push(a[i]);
    }

    for i in s..n {
        b.push(a[i]);
    }

    let ans = b.iter().map(|x| x.to_string()).collect::<Vec<String>>().join(" ");

    println!("{}", ans);
}