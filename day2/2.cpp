#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::string line;
    int sum = 0;


    while(std::getline(std::cin, line)) {
        int length = 0;
        int start = 0;
        int currBefore = -1;
        int downCount = 0;
        int upCount = 0;

        std::vector<int> nums;

        while(start + length < line.size()) {
            while(start + length < line.size() && line[start + length] != ' ') {
                length++;
            }
            int curr = std::stoi(line.substr(start, length));
            nums.push_back(curr);

            if(currBefore >= 0) {

                if(currBefore - curr == 1 || currBefore - curr == 2 || currBefore - curr == 3) {
                    downCount++;
                }
                else if(currBefore - curr == -1 || currBefore - curr == -2 || currBefore - curr == -3) {
                    upCount++;
                }

            }


            start += length + 1;
            length = 0;
            currBefore = curr;
        }

        if(upCount >= downCount) {
            bool passed = false;
            bool ok = true;
            for (int i = 0; i < nums.size() - 1; ++i) {
                if(nums[i] - nums[i+1] != -1 && nums[i] - nums[i+1] != -2 && nums[i] - nums[i+1] != -3) {
                    if(passed) {
                        ok = false;
                        break;
                    }
                    if(i + 2 > nums.size() - 1 || nums[i] - nums[i+2] == -1 || nums[i] - nums[i+2] == -2 || nums[i] - nums[i+2] == -3) {
                        i++;
                        passed = true;
                    }
                    else if(i - 1 < 0 || i + 1 > nums.size() - 1 || nums[i-1] - nums[i+1] == -1 || nums[i-1] - nums[i+1] == -2 || nums[i-1] - nums[i+1] == -3) {
                        passed = true;
                    }

                    else {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) {
                sum++;
            }
        }
        else {
            bool passed = false;
            bool ok = true;
            for (int i = 0; i < nums.size() - 1; ++i) {
                if(nums[i] - nums[i+1] != 1 && nums[i] - nums[i+1] != 2 && nums[i] - nums[i+1] != 3) {
                    if(passed) {
                        ok = false;
                        break;
                    }
                    if(i + 2 > nums.size() - 1 || nums[i] - nums[i+2] == 1 || nums[i] - nums[i+2] == 2 || nums[i] - nums[i+2] == 3) {
                        i++;
                        passed = true;
                    }
                    else if(i - 1 < 0 || i + 1 > nums.size() - 1 || nums[i-1] - nums[i+1] == 1 || nums[i-1] - nums[i+1] == 2 || nums[i-1] - nums[i+1] == 3) {
                        passed = true;
                    }

                    else {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) {
                sum++;
            }
        }


    }


    std::cout << sum << std::endl;
}
