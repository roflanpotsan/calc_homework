// Copyright 2021 roflanpotsan l1sZ@ya.ru

#include "header.h"

int main() {
    string in;
    cout << "Enter an expression:" << endl;
    getline(cin, in);
    if (!in.empty()) {
        double x = 0;
        vector<string> rpn, split_exp;
        split_expression(in, split_exp);
        if (find(split_exp.begin(), split_exp.end(), "x") != split_exp.end()) {
            cout << "Enter a value of x.\nx = ";
            cin >> x;
        }
        get_rpn(split_exp, rpn);
        x = calculate(rpn, x);
        cout << "The result is: " << x << '\n';
    }
    else cout << "The input can not be empty.\n";
    return 0;
}
