#include <iostream>
#include <vector>

bool isInArray(int xSize, int ySize, int newX, int newY) {
    if (newX < 0 || newY < 0) {
        return false;
    }
    if (newX >= xSize || newY >= ySize) {
        return false;
    }
    return true;
}

int main() {
    std::string line;

    int sum = 0;
    std::vector<std::vector<char>> input;

    const std::vector<std::pair<int, int>> directions = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    while(std::getline(std::cin, line)) {
        input.emplace_back(line.begin(), line.end());
    }

    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < input[i].size(); ++j) {
            if (input[i][j] == 'A') {
                bool ok = true;
                for (auto direction: directions) {
                    if (isInArray(input.size(), input[0].size(), i + direction.first, j + direction.second)) {
                        continue;
                    }
                    ok = false;
                }
                if (ok) {
                    if ((input[i+1][j+1] == 'M' && input[i-1][j-1] == 'S') || (input[i+1][j+1] == 'S' && input[i-1][j-1] == 'M')) {
                        if ((input[i-1][j+1] == 'M' && input[i+1][j-1] == 'S') || (input[i-1][j+1] == 'S' && input[i+1][j-1] == 'M')) {
                            sum++;
                        }
                    }
                }
            }
        }
    }

    std::cout << sum << std::endl;
}

