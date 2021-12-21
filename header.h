// Copyright 2021 roflanpotsan l1sZ@ya.ru

#ifndef CALC_HOMEWORK_HEADER_H
#define CALC_HOMEWORK_HEADER_H

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <set>
#include <cmath>

using namespace std;

bool is_num(string num);
int get_priority(const string &operation);
void split_expression(string &in, vector<string> &split_exp);
void get_rpn(const vector<string> &split_exp, vector<string> &rpn_expression);
double calculate(const vector<string> &rpn_expression, const double &x);


#endif //CALC_HOMEWORK_HEADER_H
