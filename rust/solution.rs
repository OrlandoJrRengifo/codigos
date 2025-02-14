use std::time::Instant;
use std::fs::File;
use std::io::Write;

fn is_prime(n: u32) -> bool {
    if n < 2 { return false; }
    let limit = (n as f64).sqrt() as u32;
    for i in 2..=limit {
        if n % i == 0 {
            return false;
        }
    }
    true
}

fn main() {
    let n = 1000;
    let start = Instant::now();
    let mut sum: u64 = 0;
    for i in 0..n {
        for j in 0..n {
            let num = i * n + j + 1;
            if is_prime(num as u32) {
                sum += num as u64;
            }
        }
    }
    let elapsed_ms = start.elapsed().as_millis();
    
    // Guardar el resultado en output.txt
    let mut file = File::create("output.txt").expect("No se pudo crear output.txt");
    write!(file, "{}", sum).expect("No se pudo escribir en output.txt");
    
    // Imprimir únicamente el tiempo de ejecución
    println!("{} ms", elapsed_ms);
}
