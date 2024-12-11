#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>


int main() {
    std::string line;
    std::vector<int> input;

    std::getline(std::cin, line);

    for (size_t i = 0; i < line.size(); ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < line[i] - 48; ++j) {
                input.push_back(i / 2);
            }
        }
        else {
            for (int j = 0; j < line[i] - 48; ++j) {
                input.push_back(-1);
            }
        }
    }


    size_t rightIndex = input.size() - 1;

    size_t currFileStart = input.size() - 1;
    size_t currFileLength = 0;



    int fileFoundId = -1;


    while (rightIndex > 0) {
        if (fileFoundId == -1) {
            if (input[rightIndex] == -1) {
                rightIndex--;
                continue;
            }
            fileFoundId = input[rightIndex];
            currFileStart = rightIndex;
            currFileLength = 0;
            continue;
        }
        if (fileFoundId != -1) {
            if (input[rightIndex] == fileFoundId) {
                rightIndex--;
                currFileLength++;
                continue;
            }
            //std::cout << fileFoundId << " - " << currFileStart << " - " << currFileLength << std::endl;

            fileFoundId = -1;


            size_t currSpaceStart = 0;;
            size_t currSpaceLength = 0;
            bool inSpace = false;


            size_t leftIndex = 0;

            while (leftIndex <= rightIndex + 1) {
                if (inSpace) {
                    if (input[leftIndex] == -1) {
                        leftIndex++;
                        currSpaceLength++;
                        continue;
                    }
                    inSpace = false;
                    if (currSpaceLength >= currFileLength) {
                        for (size_t k = 0; k < currFileLength; ++k) {
                            input[currSpaceStart + k] = input[currFileStart - k];
                            input[currFileStart - k] = -1;
                        }



                        break;
                    }

                }
                if (!inSpace) {
                    if (input[leftIndex] != -1) {
                        leftIndex++;
                        continue;
                    }
                    inSpace = true;
                    currSpaceLength = 0;
                    currSpaceStart = leftIndex;
                    continue;
                }
            }

        }

    }

    long unsigned int sum = 0;


    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] != -1) {
            sum += i * input[i];
        }
    }

    std::cout << sum << std::endl;

}
