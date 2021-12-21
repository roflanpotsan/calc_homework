// Copyright 2021 roflanpotsan l1sZ@ya.ru
//extra functions

#include "header.h"

bool is_num(string num) {
    bool ans = true;
    if (num[0] == '-' && num.size() > 1) num.erase(0, 1);
    if (num == "x") return true;
    for (auto x: num) ans = (isdigit(x) || (x == '.')) && ans;
    return ans;
}

int get_priority(const string &operation) {
    if (operation == "+" || operation == "-") return 1;
    else if (operation == "*" || operation == "/") return 2;
    else if (operation == "sin" || operation == "cos" ||
             operation == "tg" || operation == "ctg" || operation == "exp")
        return 3;
    else return 0;
}
