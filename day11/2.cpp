#include <bitset>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>



int main() {
    std::string line;
    std::vector<std::string> input;

    std::getline(std::cin, line);

    std::map<std::string, size_t> currMap;

    size_t start = 0;
    for (size_t i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            currMap[line.substr(start, i-start)] =  1;
            start = i + 1;
        }
    }
    currMap[line.substr(start)] =  1;



    for (int cnt = 0; cnt < 75; ++cnt) {

        std::map<std::string, size_t> newMap;

        for (auto elem: currMap) {
            if (elem.first == "0") {
                if (!newMap.contains("1")) {
                    newMap["1"] = 0;
                }
                newMap["1"] += elem.second;
            }
            else if (elem.first.size() % 2 == 0) {
                std::string one = elem.first.substr(0, elem.first.size() / 2);
                std::string two = elem.first.substr(elem.first.size() / 2);

                two = std::to_string(std::stol(two));

                if (!newMap.contains(one)) {
                    newMap[one] = 0;
                }
                if (!newMap.contains(two)) {
                    newMap[two] = 0;
                }

                newMap[one] += elem.second;
                newMap[two] += elem.second;
            }
            else {
                unsigned long int curr = std::stol(elem.first);
                curr *= 2024;
                std::string newS = std::to_string(curr);

                if (!newMap.contains(newS)) {
                    newMap[newS] = 0;
                }

                newMap[newS] += elem.second;
            }
        }

        currMap = newMap;
    }

    size_t res = 0;
    for (auto line1: currMap) {
        res += line1.second;
    }


    std::cout << res << std::endl;

}
