// Copyright 2021 roflanpotsan l1sZ@ya.ru
//gets a rpn expression from split expression

#include "header.h"

void get_rpn(const vector<string> &split_exp, vector<string> &rpn_expression) {
    stack<string> operations;
    set<string> operands = {"+", "-", "*", "/",}, functions = {"sin", "cos", "tg", "ctg", "exp"};
    for (const auto &x: split_exp) {
        if (is_num(x)) rpn_expression.push_back(x);

        else if (operands.find(x) != operands.end() || functions.find(x) != functions.end()) {
            if (!operations.empty()) {
                if (get_priority(x) <= get_priority(operations.top())) {
                    rpn_expression.push_back(operations.top());
                    operations.pop();
                }
                operations.push(x);
            } else operations.push(x);
        } else if (x == "(") operations.push(x);
        else if (x == ")") {
            while (operations.top() != "(") {
                rpn_expression.push_back(operations.top());
                operations.pop();
            }
            operations.pop();
            if (functions.find(operations.top()) != functions.end()) {
                rpn_expression.push_back(operations.top());
                operations.pop();
            }
        }
    }
    while (!operations.empty()) {
        rpn_expression.push_back(operations.top());
        operations.pop();
    }
}
