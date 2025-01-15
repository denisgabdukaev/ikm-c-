#ifndef ikm13
#define ikm13

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const string res20k = "2666866670000"; // сумма квадратов от 1 до 20000

string sum(const string& a, const string& b);
string diff(const string& a, const string& b);
string karatsuba(const string& x, const string& y);
string square(const string& num);
string sumsquares(const string& input);
bool check(const string& input);

#endif
