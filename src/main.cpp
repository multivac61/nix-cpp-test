// #include <juce_gui_extra/juce_gui_extra.h>
// #include <juce_core/juce_core.h>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// ...


int main() {

    // juce::String myString = "Hello, World!";
    // juce::MessageBoxOptions options;
    // const auto msg = options.withMessage("What's up??");
    // juce::AlertWindow::showAsync(msg, [](int result) {
    //     if (result == 0) {
    //         juce::Logger::writeToLog("User pressed OK");
    //     } else {
    //         juce::Logger::writeToLog("User pressed Cancel");
    //     }
    // });
std::ifstream f("example.json");
json data = json::parse(f);

    return 0;
}
