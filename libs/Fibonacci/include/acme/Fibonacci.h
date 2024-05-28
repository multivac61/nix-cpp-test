#pragma once

class Fibonacci {
public:
  static int fibonacci(int n);

private:
  static int fibonacci(int n, int a, int b);
  static constexpr int start = 0;
  static constexpr int next = 1;
};
