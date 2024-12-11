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

    const std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    while(std::getline(std::cin, line)) {
        input.emplace_back(line.begin(), line.end());
    }

    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < input[i].size(); ++j) {
            if (input[i][j] == 'X') {
                for (auto direction: directions) {
                    std::pair currPos = {i,j};
                    char currChar = 'X';
                    while (isInArray(input.size(), input[0].size(), currPos.first + direction.first, currPos.second + direction.second)) {
                        if (currChar == 'X' && input[currPos.first + direction.first][currPos.second + direction.second] == 'M') {
                            currChar = 'M';
                            currPos = {currPos.first + direction.first, currPos.second + direction.second};

                        }
                        else if (currChar == 'M' && input[currPos.first + direction.first][currPos.second + direction.second] == 'A') {
                            currChar = 'A';
                            currPos = {currPos.first + direction.first, currPos.second + direction.second};
                        }
                        else if (currChar == 'A' && input[currPos.first + direction.first][currPos.second + direction.second] == 'S') {
                            sum++;
                            break;
                        }
                        else {
                            break;
                        }
                    }
                }
            }

        }
    }

    std::cout << sum << std::endl;
}

