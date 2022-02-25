use proconio::input;
fn main() {
    input! {
        h: usize,
        w: usize,
        a: [[usize; w]; h]
    };
    let mut row = vec![0; h];
    let mut col = vec![0; w];

    for j in 0..h {
        for i in 0..w {
            row[j] += a[j][i];
            col[i] += a[j][i];
        }
    }

    for j in 0..h {
        if j != 0 {
            println!();
        }
        for i in 0..w {
            if i != 0 {
                print!(" ");
            }
            print!("{}", row[j] + col[i] - a[j][i]);
        }
    }
}
