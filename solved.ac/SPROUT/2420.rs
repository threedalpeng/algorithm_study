use std::fmt::Write;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let mut output = String::new();

    io::stdin().read_to_string(&mut input).unwrap();
    let mut tokens = input.split_whitespace();

    let f: i64 = tokens.next().unwrap().parse().unwrap();
    let s: i64 = tokens.next().unwrap().parse().unwrap();
    let q = if f > s { f - s } else { s - f };
    writeln!(output, "{}", q).unwrap();

    print!("{}", output);
}
