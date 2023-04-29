use std::fmt::Write;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let mut output = String::new();

    io::stdin().read_to_string(&mut input).unwrap();
    let mut tokens = input.split_whitespace();

    let n: usize = tokens.next().unwrap().parse().unwrap();
    let v: Vec<i64> = tokens
        .by_ref()
        .take(n)
        .map(|x| x.parse().unwrap())
        .collect();
    let target: i64 = tokens.next().unwrap().parse().unwrap();
    let cnt = v.iter().filter(|&x| *x == target).count();
    writeln!(output, "{}", cnt).unwrap();

    print!("{}", output);
}
