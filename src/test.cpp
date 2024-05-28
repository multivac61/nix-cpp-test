#include "acme/Fibonacci.h"
#include <boost/ut.hpp>
#include <nlohmann/json.hpp>

int main() {
  using namespace boost::ut;

  // create a JSON object
  nlohmann::json j = {{"pi", 3.141},
                      {"happy", true},
                      {"name", "Niels"},
                      {"nothing", nullptr},
                      {"answer", {{"everything", 42}}},
                      {"list", {1, 0, 2}},
                      {"object", {{"currency", "USD"}, {"value", 42.99}}}};

  // add new values
  j["new"]["key"]["value"] = {"another", "list"};

  // count elements
  auto s = j.size();
  j["size"] = s;

  expect(j["size"] == s);

  "Fibonacci"_test = [] {
    expect(Fibonacci::fibonacci(0) == 0);
    expect(Fibonacci::fibonacci(1) == 1);
    expect(Fibonacci::fibonacci(2) == 1);
    expect(Fibonacci::fibonacci(10) == 55);
  };

  return 0;
}
