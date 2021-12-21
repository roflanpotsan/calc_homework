// Copyright 2021 roflanpotsan l1sZ@ya.ru
//calculates the result

#include "header.h"

double calculate(const vector<string> &rpn_expression, const double &x) {
    stack<double> numbers;
    double temp_res;
    for (const auto &param: rpn_expression) {
        if (is_num(param)) {
            if (param == "x") numbers.push(x);
            else if (param == "-x") numbers.push(-x);
            else numbers.push(stod(param));
        } else {
            if (param == "sin") {
                temp_res = sin(numbers.top());
                numbers.pop();
                numbers.push(temp_res);
            } else if (param == "cos") {
                temp_res = cos(numbers.top());
                numbers.pop();
                numbers.push(temp_res);
            } else if (param == "tg") {
                if ((cos(numbers.top()) == 0)) {
                    cout << "Division by 0 is not allowed.\n";
                    exit(12);
                }
                temp_res = tan(numbers.top());
                numbers.pop();
                numbers.push(temp_res);
            } else if (param == "ctg") {
                if ((sin(numbers.top()) == 0)) {
                    cout << "Division by 0 is not allowed.\n";
                    exit(12);
                }
                temp_res = (1.0 / tan(numbers.top()));
                numbers.pop();
                numbers.push(temp_res);
            } else if (param == "exp") {
                temp_res = exp(numbers.top());
                numbers.pop();
                numbers.push(temp_res);
            } else if (param == "+") {
                temp_res = numbers.top();
                numbers.pop();
                temp_res = numbers.top() + temp_res;
                numbers.pop();
                numbers.push(temp_res);
            } else if (param == "-") {
                temp_res = numbers.top();
                numbers.pop();
                temp_res = numbers.top() - temp_res;
                numbers.pop();
                numbers.push(temp_res);
            } else if (param == "*") {
                temp_res = numbers.top();
                numbers.pop();
                temp_res = numbers.top() * temp_res;
                numbers.pop();
                numbers.push(temp_res);
            } else if (param == "/") {
                temp_res = numbers.top();
                if (temp_res == 0) {
                    cout << "Division by 0 is not allowed.\n";
                    exit(12);
                }
                numbers.pop();
                temp_res = numbers.top() / temp_res;
                numbers.pop();
                numbers.push(temp_res);
            }
        }
    }
    return numbers.top();
}
