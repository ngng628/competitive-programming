use proconio::{input, fastout};

#[fastout]
fn main() {
    input!{
        x: usize,
    };

    println!("{}", 1000*(x/500) + 5*((x%500)/5));
}
