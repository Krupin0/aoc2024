#include <bitset>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

int powOfThree(int num) {
    int sum = 1;
    for (int i = 0; i < num; ++i) {
        sum *= 3;
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

        std::vector<int> arrBase3;
        for (int i = 0; i < inNumbersVec.size() - 1; ++i) {
            arrBase3.push_back(0);
        }

        for (int i = 0; i < powOfThree(inNumbersVec.size() - 1); ++i) {
            long unsigned int sum = inNumbersVec[0];


            for (int j = 0; j < arrBase3.size(); ++j) {
                if (arrBase3[j] == 0) {
                    sum += inNumbersVec[j + 1];
                }
                else if (arrBase3[j] == 1){
                    sum *= inNumbersVec[j + 1];
                }
                else {
                    std::string a = std::to_string(sum);
                    std::string b = std::to_string(inNumbersVec[j + 1]);
                    a.append(b);
                    sum = std::stol(a);
                }
                if (sum > wanted) {
                    break;
                }
            }
            if (sum == wanted) {
                totalSum += wanted;
                break;
            }

            for (int j = 0; j < arrBase3.size(); ++j) {
                if (arrBase3[j] == 0 || arrBase3[j] == 1) {
                    arrBase3[j]++;
                    break;
                }
                arrBase3[j] = 0;
            }
        }
    }
    std::cout << totalSum << std::endl;
}
