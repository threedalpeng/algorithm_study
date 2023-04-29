use std::fmt::Write;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    let mut output = String::new();

    io::stdin().read_to_string(&mut input).unwrap();
    let mut tokens = input.split_whitespace();

    let x: i32 = tokens.next().unwrap().parse().unwrap();
    let y: i32 = tokens.next().unwrap().parse().unwrap();
    let q = if x > 0 {
        if y > 0 {
            1
        } else {
            4
        }
    } else {
        if y > 0 {
            2
        } else {
            3
        }
    };
    writeln!(output, "{}", q).unwrap();

    print!("{}", output)
}
