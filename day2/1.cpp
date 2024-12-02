#include <algorithm>
#include <iostream>

int main() {
    std::string line;
    int sum = 0;


    while(std::getline(std::cin, line)) {
        int length = 0;
        int start = 0;
        int direction = 0;
        int currBefore = -1;
        bool ok = true;

        while(start + length < line.size()) {
            while(start + length < line.size() && line[start + length] != ' ') {
                length++;
            }
            int curr = std::stoi(line.substr(start, length));


            if(currBefore >= 0) {
                if(direction == 0) {
                    if(currBefore - curr == 1 || currBefore - curr == 2 || currBefore - curr == 3) {
                        direction = 1;
                    }
                    else if(currBefore - curr == -1 || currBefore - curr == -2 || currBefore - curr == -3) {
                        direction = 2;
                    }
                    else {
                        ok = false;

                        break;
                    }
                }
                else if(direction == 1) { //zmensuje se
                    if(currBefore - curr != 1 && currBefore - curr != 2 && currBefore - curr != 3) {
                        ok = false;

                        break;
                    }
                }
                else if(direction == 2) { //zvetsuje se
                    if(currBefore - curr != -1 && currBefore - curr != -2 && currBefore - curr != -3) {
                        ok = false;

                        break;
                    }
                }
            }


            start += length + 1;
            length = 0;
            currBefore = curr;
        }
        if(ok) {
            sum++;
        }
    }


    std::cout << sum << std::endl;
}
