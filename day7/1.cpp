#include <bitset>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

int powOfTwo(int num) {
    int sum = 1;
    for (int i = 0; i < num; ++i) {
        sum *= 2;
    }
    return sum;
}

int main() {
    long unsigned int totalSum = 0;
    std::string line;


    while(std::getline(std::cin, line)) {
        std::vector<long unsigned int> inNumbersVec;
        long unsigned int wanted;

        int start = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ':') {
                wanted = (std::stol(line.substr(start, i-start)));
                start = i + 2;
                break;
            }
        }
        for (int i = start; i < line.size(); i++) {
            if (line[i] == ' ') {
                inNumbersVec.push_back(std::stol(line.substr(start, i-start)));
                start = i + 1;
            }
        }
        inNumbersVec.push_back(std::stol(line.substr(start)));


        for (int i = 0; i < powOfTwo(inNumbersVec.size()-1); ++i) {
            std::bitset<32> bits = i;
            long unsigned int sum = inNumbersVec[0];
            for (int j = 0; j < inNumbersVec.size() - 1; ++j) {
                if (bits[j]) {
                    sum += inNumbersVec[j + 1];
                }
                else {
                    sum *= inNumbersVec[j + 1];
                }
                if (sum > wanted) {
                    break;
                }
            }
            if (sum == wanted) {
                totalSum += wanted;
                break;
            }
        }
    }
    std::cout << totalSum << std::endl;
}
