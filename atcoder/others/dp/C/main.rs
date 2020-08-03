use proconio::{fastout, input};
use std::cmp::max;

const N_MAX: usize = 1e5 as usize;

#[fastout]
fn main() {
    input!{
        n: usize,
        t: [(i32, i32, i32); n],
    };

    let mut dp = [[0; N_MAX + 1]; 3];

    for k in 1..n+1 {
        for i in 0..3 {
            if i == 0 {
                dp[i][k] = max(dp[1][k-1] + t[k-1].1, dp[2][k-1] + t[k-1].2);
            } else if i == 1 {
                dp[i][k] = max(dp[0][k-1] + t[k-1].0, dp[2][k-1] + t[k-1].2);
            } else {
                assert_eq!(i, 2);
                dp[i][k] = max(dp[1][k-1] + t[k-1].1, dp[0][k-1] + t[k-1].0);
            }
            //dp[i][k] = max(dp[][k-1])
        }
    }

    println!("{}", max(dp[0][n], max(dp[1][n], dp[2][n])));
}
