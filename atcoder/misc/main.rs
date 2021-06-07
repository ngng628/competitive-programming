// struct Foo {
//    x: i32
// }

// fn do_something(foo: Foo) {
//    println!("foo.x = {}", foo.x);
// }

fn main() {
   let n = 10;
   let a = &n;
   let b = a;
   println!("{}", b);
}