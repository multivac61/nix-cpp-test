#include "acme/Fibonacci.h"
#include <boost/ut.hpp>

int main() {

  using namespace boost::ut;

  "exception"_test = [] {
    expect(throws([] { throw 0; })) << "throws any exception";
  };

  "failure"_test = [] { expect(nothrow([] {})); };

  "Fibonacci"_test = [] {
    expect(Fibonacci::fibonacci(0) == 0);
    expect(Fibonacci::fibonacci(1) == 1);
    expect(Fibonacci::fibonacci(2) == 1);
    expect(Fibonacci::fibonacci(10) == 55);
  };

  "bar"_test = [] { expect(1 + 2 == 3); };

  "baz"_test = [] { expect(1 + 222 == 223) << "this is not true"; };
}
