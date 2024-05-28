#pragma once

class Fibonacci {
public:
  static constexpr int fibonacci(int n);

private:
  static constexpr int fibonacci(int n, int a, int b);
  static constexpr int start = 0;
  static constexpr int next = 1;
};
