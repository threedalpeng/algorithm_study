use std::collections::HashSet;
use std::fmt::Write;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let mut output = String::new();

    io::stdin().read_to_string(&mut input).unwrap();
    let mut tokens = input.split_whitespace();

    let mut set: HashSet<i32> = (1..31).collect();
    for _ in 0..28 {
        let x: i32 = tokens.next().unwrap().parse().unwrap();
        set.remove(&x);
    }
    let mut v: Vec<i32> = set.into_iter().collect();
    v.sort();

    writeln!(output, "{}", v[0]).unwrap();
    writeln!(output, "{}", v[1]).unwrap();

    print!("{}", output);
}
