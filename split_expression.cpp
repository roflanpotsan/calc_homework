// Copyright 2021 roflanpotsan l1sZ@ya.ru
//splits expression and checks for mistakes

#include "header.h"

void split_expression(string &in, vector<string> &split_exp) {

    string key1, key2;

    set<string> operands = {"+", "-", "*", "/",}, functions = {"sin", "cos", "tg", "ctg", "exp"};

    for (size_t i = 1; i < in.size() - 1; i++) {
        if (isdigit(in[i - 1]) && isdigit(in[i + 1]) && in[i] == ' ') {
            cout << "Missing an operand between numbers. Check input for mistakes.\n";
            exit(1);
        }
    }

    while (in.find(' ') != string::npos) in.erase(in.find(' '), 1);

    size_t counter = 0;
    for (auto x: in) {
        if (x == '(') counter++;
        else if (x == ')') counter--;
        if (counter < 0) {
            cout << "The amounts of open and close braces do not match. Check input for mistakes.\n";
            exit(2);
        }
    }
    if (counter > 0) {
        cout << "The amounts of open and close braces do not match. Check input for mistakes.\n";
        exit(2);
    }

    if (in.find("()") != string::npos) {
        cout << "There can't be empty braces. Check input for mistakes.\n";
        exit(3);
    }

    for (size_t i = 0; i < in.length() - 1; i++) {
        if (isdigit(in[i]) && in[i + 1] == '(' ||
            in[i] == ')' && isdigit(in[i + 1]) || in[i] == ')' && in[i + 1] == 'x' ||
            in[i] == 'x' && in[i + 1] == '(' || in[i] == ')' && in[i + 1] == '(') {
            cout << "Missing an operand next to a brace. Check input for mistakes.\n";
            exit(4);
        }
    }

    for (const auto &x: functions) {
        size_t pos = 0;
        while ((pos = in.find(x, pos)) != string::npos) {
            if (in[pos + x.length()] != '(') {
                cout << "Missing braces in a function. Check input for mistakes.\n";
                exit(5);
            }
            pos += x.length();
        }
    }

    string number;
    string function;
    string operation;

    for (auto x: in) {
        if (isdigit(x) || x == '.') number += x;
        else {
            if (!number.empty()) {
                if (count(number.begin(), number.end(), '.') != number.length()) split_exp.push_back(number);
                else {
                    cout << "Stray '.'; Check input for mistakes.\n";
                    exit(6);
                }
                number.clear();
            }
            if (x != '(' && x != ')' && x != '+' && x != '-' && x != '*' && x != '/') function += x;
            else {
                if (!function.empty() && (functions.find(function) != functions.end() || function == "x")) {
                    split_exp.push_back(function);
                    function.clear();
                } else if (!function.empty() && (functions.find(function) == functions.end() || function != "x")) {
                    cout << "Stray symbols. Check input for mistakes.\n";
                    exit(7);
                }
                operation.clear();
                operation += x;
                split_exp.emplace_back(operation);
            }
        }
    }

    if (!number.empty()) {
        if (count(number.begin(), number.end(), '.') != number.length()) split_exp.push_back(number);
        else {
            cout << "Stray '.'; Check input for mistakes.\n";
            exit(6);
        }
    }
    if (!function.empty() && (functions.find(function) != functions.end() || function == "x"))
        split_exp.push_back(function);
    else if (!function.empty() && (functions.find(function) == functions.end() || function != "x")) {
        cout << "Stray symbols. Check input for mistakes.\n";
        exit(7);
    }

    int func_c = 0, num_c = 0;
    for (const auto &x: split_exp) {
        if (is_num(x)) num_c++;
        if (functions.find(x) != functions.end()) func_c++;
    }
    if (num_c + func_c < 2) {
        cout
                << "Expression must contain at least 1 function and an argument or 2 arguments and 1 operand. "
                   "Check input for mistakes.\n";
        exit(8);
    }

    if (operands.find(split_exp[0]) != operands.end() && operands.find(split_exp[1]) != functions.end()) {
        cout << "An expression can not start with an operand and a function following it. Check input for mistakes.\n";
        exit(9);
    }

    for (std::__wrap_iter<std::vector<string> *>::difference_type(i) = 2; i < split_exp.size() - 1; i++) {
        if (is_num(split_exp[i]) && split_exp[i - 1] == "-"
            && split_exp[i - 2] == "(" && split_exp[i + 1] == ")") {
            split_exp[i] = split_exp[i - 1] + split_exp[i];
            split_exp.erase(split_exp.begin() + i - 2, split_exp.begin() + i);
            split_exp.erase(split_exp.begin() + i - 1, split_exp.begin() + i);
        } else if (is_num(split_exp[i]) && operands.find(split_exp[i - 1]) != operands.end() &&
                   split_exp[i - 2] == "(" &&
                   split_exp[i + 1] != ")" ||
                   is_num(split_exp[i]) && operands.find(split_exp[i - 1]) != operands.end() &&
                   split_exp[i - 2] == "(" &&
                   split_exp[i + 1] == ")" && split_exp[i - 1] != "-") {
            cout << "Redundant operand or a negative number without braces. Check input for mistakes.\n";
            exit(10);
        }
    }
    for (size_t i = 0; i < split_exp.size() - 1; i++) {
        if (is_num(split_exp[i]) && is_num(split_exp[i + 1])) {
            cout << "Missing an operand between numbers. Check input for mistakes.\n";
            exit(1);
        }
    }
    for (size_t i = 0; i < split_exp.size() - 1; i++) {
        key1.clear();
        key1 += split_exp[i];
        key2.clear();
        key2 += split_exp[i + 1];
        if (operands.find(key1) != operands.end() && operands.find(key2) != operands.end()) {
            cout << "Two operands can not follow each other. Check input for mistakes.\n";
            exit(11);
        }
    }

}
