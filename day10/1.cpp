#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

struct position {
    size_t x;
    size_t y;

    auto operator<=>(const position &) const = default;
};

bool isIn(position curr, const std::vector<std::vector<int>> & input) {
    return !(curr.x < 0 || curr.y < 0 || curr.x >= input[0].size() || curr.y >= input.size());
}

int main() {
    size_t res = 0;
    std::string line;

    std::vector<std::vector<int>> maze;
    std::queue<position> starts;
    size_t j = 0;

    while(std::getline(std::cin, line)) {
        maze.emplace_back();
        for (size_t i = 0; i < line.size(); ++i) {
            maze[maze.size() - 1].push_back(line[i] - 48);
            if (line[i] == '0') {
                starts.emplace(i, j);
            }
        }
        j++;
    }


    while (!starts.empty()) {
        std::queue<position> toCheck;
        std::set<position> found;

        toCheck.push(starts.front());
        found.insert(starts.front());

        starts.pop();

        while (!toCheck.empty()) {
            position curr = toCheck.front();
            toCheck.pop();


            position left = {curr.x - 1, curr.y};
            position right = {curr.x + 1, curr.y};
            position down = {curr.x, curr.y + 1};
            position up = {curr.x, curr.y - 1};

            if (!found.contains(left) && isIn(left, maze) && maze[curr.y][curr.x] + 1 == maze[left.y][left.x]) {
                toCheck.push(left);
                found.insert(left);
                if (maze[left.y][left.x] == 9) {
                    res++;
                }
            }
            if (!found.contains(right) && isIn(right, maze) && maze[curr.y][curr.x] + 1 == maze[right.y][right.x]) {
                toCheck.push(right);
                found.insert(right);
                if (maze[right.y][right.x] == 9) {
                    res++;
                }
            }
            if (!found.contains(up) && isIn(up, maze) && maze[curr.y][curr.x] + 1 == maze[up.y][up.x]) {
                toCheck.push(up);
                found.insert(up);
                if (maze[up.y][up.x] == 9) {
                    res++;
                }
            }
            if (!found.contains(down) && isIn(down, maze) && maze[curr.y][curr.x] + 1 == maze[down.y][down.x]) {
                toCheck.push(down);
                found.insert(down);
                if (maze[down.y][down.x] == 9) {
                    res++;
                }
            }
        }
    }

    std::cout << res << std::endl;
}
