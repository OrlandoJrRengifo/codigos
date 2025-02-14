const fs = require('fs');

function isPrime(n) {
  if(n < 2) return false;
  const limit = Math.floor(Math.sqrt(n));
  for (let i = 2; i <= limit; i++) {
    if(n % i === 0) return false;
  }
  return true;
}

const N = 1000;
const start = process.hrtime();
let sum = 0;
for(let i = 0; i < N; i++){
  for(let j = 0; j < N; j++){
    const num = i * N + j + 1;
    if(isPrime(num)) {
      sum += num;
    }
  }
}
const diff = process.hrtime(start);
const elapsed_ms = Math.round(diff[0] * 1000 + diff[1] / 1e6);

// Guardar el resultado en output.txt
fs.writeFileSync("output.txt", sum.toString());

// Imprimir únicamente el tiempo de ejecución
console.log(elapsed_ms + " ms");
