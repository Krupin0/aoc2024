#include <iostream>
struct State {
    std::string num1;
    std::string num2;
    int state = 0;
    int currDo = 1;
    int doState = 0;

    void updateState(char c) {

        if (c == 'm') {
            reset();
            doState = 0;
            state = 1;
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

        else if (c == 'd') {
            doState = 1;
            reset();
        }
        else if (doState == 1 && c == 'o') {
            doState++;
        }
        else if (doState == 2 && c == '(') {
            doState++;
        }
        else if (doState == 2 && c == 'n') {
            doState = 4;
        }
        else if (doState == 3 && c == ')') {
            doState = 0;
            currDo = 1;
        }
        else if (doState == 4 && c == '\'') {
            doState++;
        }
        else if (doState == 5 && c == 't') {
            doState++;
        }
        else if (doState == 6 && c == '(') {
            doState++;
        }
        else if (doState == 7 && c == ')') {
            doState = 0;
            currDo = 0;
        }

        else {
            reset();
            doState = 0;
        }
    }

    int getResult() {
        int res = std::stoi(num1) * std::stoi(num2) * currDo;
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
