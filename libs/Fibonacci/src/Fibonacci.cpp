#include "Fibonacci.h"
#include <algorithm>

int Fibonacci::fibonacci(int n) { return fibonacci(n, start, next); }

int Fibonacci::fibonacci(int n, int a, int b) {
  return n == 0 ? a : fibonacci(n - 1, b, a + b);
}
