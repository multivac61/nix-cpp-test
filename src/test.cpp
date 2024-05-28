// #include <juce_gui_extra/juce_gui_extra.h>
// #include <juce_core/juce_core.h>
#include "acme/Fibonacci.h"
#include <fstream>
#include <nlohmann/json.hpp>

int main() {
  using json = nlohmann::json;
  std::ifstream f("example.json");
  json data = json::parse(f);

  "Fibonacci"_test = [] {
    expect(Fibonacci::fibonacci(0) == 0);
    expect(Fibonacci::fibonacci(1) == 1);
    expect(Fibonacci::fibonacci(2) == 1);
    expect(Fibonacci::fibonacci(10) == 55);
  };

  return 0;
}
