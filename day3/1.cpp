#include <iostream>
struct State {
    std::string num1;
    std::string num2;
    int state = 0;

    void updateState(char c) {

        if (state == 0 && c == 'm') {
            state++;
        }
        else if (state == 1 && c == 'u') {
            state++;
        }
        else if (state == 2 && c == 'l') {
            state++;
        }
        else if (state == 3 && c == '(') {
            state++;
        }
        else if (state == 4 && isdigit(c) && num1.length() < 3) {
            num1 += c;
        }
        else if (state == 4 && c == ',' && num1.length() >= 1) {
            state++;
        }
        else if (state == 5 && isdigit(c) && num2.length() < 3) {
            num2 += c;
        }
        else if (state == 5 && c == ')' && num2.length() >= 1) {
            state++;
        }
        else if (c == 'm'){
            reset();
            state++;
        }
        else {
            reset();
        }
    }

    int getResult() {
        int res = std::stoi(num1) * std::stoi(num2);
        reset();
        return res;
    }

    bool isFinal() const{
        return state == 6;
    }

    void reset() {
        num1 = "";
        num2 = "";
        state = 0;
    }

};


int main() {
    std::string line;
    int sum = 0;
    State state;

    while(std::getline(std::cin, line)) {
        for (auto c: line) {
            state.updateState(c);
            if (state.isFinal()) {
                sum += state.getResult();
            }
        }
    }

    std::cout << sum << std::endl;
}

