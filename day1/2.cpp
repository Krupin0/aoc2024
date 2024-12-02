#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

int main() {
    std::string line;
    std::priority_queue<int> a;
    std::priority_queue<int> b;

    while(std::getline(std::cin, line)) {
        int i = 0;
        while(line[i] != ' ') {
            i++;
        }
        a.push(std::stoi(line.substr(0, i)));
        b.push(std::stoi(line.substr(i+3)));
    }

    int sum = 0;

    while(!a.empty() && !b.empty()) {
        int curr = a.top();
        int currCountA = 0;
        int currCountB = 0;


        while(!a.empty() && a.top() == curr) {
            currCountA++;
            a.pop();
        }

        while(!b.empty() && b.top() > curr) {
            b.pop();
        }

        while(!b.empty() && b.top() == curr) {
            currCountB++;
            b.pop();
        }

        sum += curr * currCountA * currCountB;
    }

    std::cout << sum << std::endl;
}
