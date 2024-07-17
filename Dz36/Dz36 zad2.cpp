#include <iostream>
#include <string>
#include <stack>
#include <sstream>

int calculate(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*") {
            if (stack.size() < 2) {
                throw std::runtime_error("Invalid expression");
            }
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();
            int result;
            if (token == "+") {
                result = operand1 + operand2;
            }
            else if (token == "-") {
                result = operand1 - operand2;
            }
            else {
                result = operand1 * operand2;
            }
            stack.push(result);
        }
        else {
            stack.push(std::stoi(token));
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }

    return stack.top();
}

int main() {
    std::string expression = "1 2 3 * +";
    try {
        int result = calculate(expression);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}