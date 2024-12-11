#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

enum Direction {
    UP, DOWN, LEFT, RIGHT
};

struct Node {
    int x;
    int y;
    Direction direction;

    auto operator<=>(const Node &) const = default;
};

bool isIn(const Node & curr, const std::vector<std::vector<char>> & input) {
    return !(curr.x < 0 || curr.y < 0 || curr.x >= input[0].size() || curr.y >= input.size());
}

int main() {
    std::string line;

    std::vector<std::vector<char>> input;

    while(std::getline(std::cin, line)) {
        input.emplace_back(line.begin(), line.end());
    }


    Node start;
    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < input[0].size(); ++j) {
            if (input[i][j] == 'v') {
               start = {j, i, DOWN};
                i = input.size();
                break;
            }
            if (input[i][j] == '>') {
                start = {j, i, RIGHT};
                i = input.size();
                break;
            }
            if (input[i][j] == '<') {
                start = {j, i, LEFT};
                i = input.size();
                break;
            }
            if (input[i][j] == '^') {
                start ={j, i, UP};
                i = input.size();
                break;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < input[0].size(); ++j) {
            if ((j == start.x && i == start.y) || input[i][j] == '#') {
                continue;
            }
            input[i][j] = '#';

            std::set<Node> checked;
            Node curr = start;


            while (isIn(curr, input)) {
                if (checked.contains(curr)) {
                    sum++;
                    break;
                }
                checked.insert(curr);

                if (curr.direction == UP && isIn({curr.x, curr.y - 1, UP}, input) && input[curr.y-1][curr.x] == '#') {
                    curr.direction = RIGHT;
                    continue;
                }
                if (curr.direction == DOWN && isIn({curr.x, curr.y + 1, DOWN}, input) && input[curr.y+1][curr.x] == '#') {
                    curr.direction = LEFT;
                    continue;
                }
                if (curr.direction == RIGHT && isIn({curr.x + 1, curr.y, RIGHT}, input) && input[curr.y][curr.x + 1] == '#') {
                    curr.direction = DOWN;
                    continue;
                }
                if (curr.direction == LEFT && isIn({curr.x - 1, curr.y, LEFT}, input) && input[curr.y][curr.x - 1] == '#') {
                    curr.direction = UP;
                    continue;
                }

                if (curr.direction == UP) {
                    curr.y--;
                }
                else if (curr.direction == DOWN) {
                    curr.y++;
                }
                else if (curr.direction == LEFT) {
                    curr.x--;
                }
                else if (curr.direction == RIGHT) {
                    curr.x++;
                }
            }
            input[i][j] = '.';
        }
        std::cout << i << std::endl;
    }



    std::cout << sum << std::endl;
}
