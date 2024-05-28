// #include <juce_gui_extra/juce_gui_extra.h>
// #include <juce_core/juce_core.h>
#include "acme/Fibonacci.h"
#include <boost/ut.hpp>
#include <fstream>
#include <nlohmann/json.hpp>

int main() {
  using namespace boost::ut;
  using json = nlohmann::json;

  // create a JSON object
  json j = {{"pi", 3.141},
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
