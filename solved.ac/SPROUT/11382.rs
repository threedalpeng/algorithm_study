use std::fmt::Write;
use std::io;

fn main() {
    let mut input = String::new();
    let mut output = String::new();

    io::stdin().read_line(&mut input).unwrap();
    let mut tokens = input.split_ascii_whitespace();
    let abc: i64 = tokens
        .by_ref()
        .take(3)
        .map(str::parse::<i64>)
        .map(Result::unwrap)
        .sum();

    writeln!(output, "{}", abc).unwrap();
    print!("{}", output)
}
