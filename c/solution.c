#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1000

int isPrime(int n) {
    if(n < 2)
        return 0;
    int limit = (int)sqrt(n);
    for (int i = 2; i <= limit; i++) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    clock_t start = clock();
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num = i * N + j + 1;
            if(isPrime(num))
                sum += num;
        }
    }
    clock_t end = clock();
    double elapsed_ms = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
    
    // Guardar el resultado en output.txt
    FILE *fp = fopen("output.txt", "w");
    if(fp) {
        fprintf(fp, "%lld", sum);
        fclose(fp);
    }
    
    // Imprimir únicamente el tiempo de ejecución
    printf("%.0f ms", elapsed_ms);
    return 0;
}
