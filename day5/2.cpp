#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>


int main() {
    std::string line;

    int sum = 0;

    std::queue<int> q;

    std::map<int, std::set<int>> children;
    std::map<int, std::set<int>> parents;


    while(std::getline(std::cin, line)) {
        if(line == ""){
          break;
        }
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '|') {
                int a = std::stoi(line.substr(0, i));
                int b = std::stoi(line.substr(i+1));
                children[a].insert(b);
                parents[b].insert(a);
            }
        }
    }



    while(std::getline(std::cin, line)) {
        std::set<int> inNumbers;
        std::vector<int> inNumbersVec;

      int start = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ',') {
                inNumbers.insert(std::stoi(line.substr(start, i-start)));
                inNumbersVec.push_back(std::stoi(line.substr(start, i-start)));
                start = i + 1;
            }
        }

        inNumbers.insert(std::stoi(line.substr(start)));
        inNumbersVec.push_back(std::stoi(line.substr(start)));

        std::map<int,int> inDegrees;
        std::vector<int> topSorted;

        for (auto num : inNumbers) {
            inDegrees[num] = 0;
            for (auto parent: parents[num]) {
                if (inNumbers.contains(parent)) {
                    inDegrees[num]++;
                }
            }
        }

        for (auto inDegree : inDegrees) {
            if (inDegree.second == 0) {
                q.push(inDegree.first);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            topSorted.push_back(curr);

            for (auto child: children[curr]) {
                inDegrees[child]--;
                if (inDegrees[child] == 0) {
                    q.push(child);
                }
            }
        }

        if (inNumbersVec.size() != topSorted.size()) {
            continue;
        }
        bool ok = true;
      for (int i = 0; i < inNumbersVec.size(); ++i) {
          if (inNumbersVec[i] != topSorted[i]) {
              ok = false;
              break;
          }
      }
        if (!ok) {
            sum += topSorted[inNumbersVec.size() / 2];
        }

    }





    std::cout << sum << std::endl;
}

