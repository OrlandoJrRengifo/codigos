package main

import (
	"fmt"
	"math"
	"os"
	"time"
)

func isPrime(n int) bool {
	if n < 2 {
		return false
	}
	limit := int(math.Sqrt(float64(n)))
	for i := 2; i <= limit; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	N := 1000
	start := time.Now()
	var sum int64 = 0
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			num := i*N + j + 1
			if isPrime(num) {
				sum += int64(num)
			}
		}
	}
	elapsed := time.Since(start).Milliseconds()
	
	// Guardar el resultado en output.txt
	f, err := os.Create("output.txt")
	if err != nil {
		panic(err)
	}
	defer f.Close()
	fmt.Fprintf(f, "%d", sum)
	
	// Imprimir únicamente el tiempo de ejecución
	fmt.Printf("%d ms", elapsed)
}
