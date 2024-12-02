#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::string line;
    std::vector<int> a;
    std::vector<int> b;

    while(std::getline(std::cin, line)) {
        int i = 0;
        while(line[i] != ' ') {
            i++;
        }
        a.push_back(std::stoi(line.substr(0, i)));
        b.push_back(std::stoi(line.substr(i+3)));
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());


    int sum = 0;
    for (size_t i = 0; i < a.size(); i++) {
        sum += std::abs(a[i] - b[i]);
    }

    std::cout << sum << std::endl;
}
