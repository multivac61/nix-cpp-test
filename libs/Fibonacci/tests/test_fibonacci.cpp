#include "Fibonacci.h"
#include <boost/ut.hpp>

int main() {

  using namespace boost::ut;

  "exception"_test = [] {
    expect(throws([] { throw 0; })) << "throws any exception";
  };

  "failure"_test = [] { expect(nothrow([] {})); };

  "Fibonacci"_test = [] {
    expect(Fibonacci(0) == 0);
    expect(Fibonacci(1) == 1);
    expect(Fibonacci(2) == 1);
    expect(Fibonacci(10) == 55);
  };

  "bar"_test = [] { expect(1 + 2 == 3); };

  "baz"_test = [] { expect(1 + 222 == 223) << "this is not true"; };
}
