#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>


int main() {
    std::string line;
    std::vector<int> input;

    std::getline(std::cin, line);

    for (size_t i = 0; i < line.size(); ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < line[i] - 48; ++j) {
                input.push_back(i / 2);
            }
        }
        else {
            for (int j = 0; j < line[i] - 48; ++j) {
                input.push_back(-1);
            }
        }
    }

    size_t leftIndex = 0;
    size_t rightIndex = input.size() - 1;

    while (leftIndex < rightIndex) {
        if (input[leftIndex] != -1) {
            leftIndex++;
            continue;
        }
        if (input[rightIndex] == -1) {
            rightIndex--;
            continue;
        }
        input[leftIndex] = input[rightIndex];
        input[rightIndex] = -1;
    }

    long unsigned int sum = 0;


    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == -1) {
            break;
        }
        sum += i * input[i];
    }

    std::cout << sum << std::endl;

}
