import time, math

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

N = 1000

start = time.time()
s = 0
for i in range(N):
    for j in range(N):
        num = i * N + j + 1
        if is_prime(num):
            s += num
end = time.time()

elapsed_ms = int((end - start) * 1000)

# Guardar el resultado en output.txt
with open("output.txt", "w") as f:
    f.write(str(s))

# Imprimir únicamente el tiempo de ejecución
print(f"{elapsed_ms} ms")

