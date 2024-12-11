#include <bitset>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>


int main() {
    std::string line;
    std::vector<std::string> input;

    std::getline(std::cin, line);

    size_t start = 0;
    for (size_t i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            input.push_back(line.substr(start, i-start));
            start = i + 1;
        }
    }
    input.push_back(line.substr(start));


    for (int cnt = 0; cnt < 25; ++cnt) {
        size_t len = input.size();
        for (size_t i = 0; i < len; ++i) {
            if (input[i] == "0") {
                input[i] = "1";
            }
            else if (input[i].size() % 2 == 0) {
                std::string one = input[i].substr(0, input[i].size() / 2);
                std::string two = input[i].substr(input[i].size() / 2);

                input[i] = one;
                input.push_back(std::to_string(std::stol(two)));
            }
            else {
                unsigned long int curr = std::stol(input[i]);
                curr *= 2024;
                input[i] = std::to_string(curr);
            }
        }

        size_t res = 0;
        for (auto line1: input) {
            if (line1 == "1") {
                res++;
            }
        }
        std::cout << res << std::endl;
    }


    std::cout << input.size() << std::endl;

}
