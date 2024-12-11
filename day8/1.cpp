#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

struct Vec {
    int x;
    int y;

    auto operator<=>(const Vec &) const = default;
};

bool isIn(Vec curr, const std::vector<std::vector<char>> & input) {
    return !(curr.x < 0 || curr.y < 0 || curr.x >= input[0].size() || curr.y >= input.size());
}

int main() {
    std::string line;

    std::vector<std::vector<char>> input;

    while(std::getline(std::cin, line)) {
        input.emplace_back(line.begin(), line.end());
    }

    std::map<char, std::vector<Vec>> allAnt;

    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < input[i].size(); ++j) {
            if (isdigit(input[i][j]) || islower(input[i][j]) || isupper(input[i][j])) {
                allAnt[input[i][j]].push_back({j, i});
            }
        }
    }

    std::set<Vec> res;

    for (auto an: allAnt) {
        for (int i = 0; i < an.second.size(); ++i) {
            for (int j = 0; j < an.second.size(); ++j) {
                if (i != j) {
                    Vec shift = {an.second[i].x - an.second[j].x, an.second[i].y - an.second[j].y};
                    Vec new1 = {an.second[i].x + shift.x, an.second[i].y + shift.y};
                    Vec new2 = {an.second[j].x - shift.x, an.second[j].y - shift.y};
                    if (isIn(new1, input)) {
                        res.insert(new1);
                    }
                    if (isIn(new2, input)) {
                        res.insert(new2);
                    }
                }
            }
        }
    }

    std::cout << res.size() << std::endl;
}
