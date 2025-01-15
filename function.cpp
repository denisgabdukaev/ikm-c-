#include "header.h"

string sum(const string& a, const string& b) { // сложение двух чисел типа string
    string res;
    int c = 0, i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || c) { // пока длины чисел >= 0 или С > 0
        int op1 = (i >= 0) ? a[i--] - '0' : 0; // незначущие нули
        int op2 = (j >= 0) ? b[j--] - '0' : 0;
        int temp = op1 + op2 + c; // сложение цифр + переход в новый разряд
        res.push_back(temp % 10 + '0');
        c = temp / 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

string diff(const string& a, const string& b) { // вычитание двух чисел типа string
    string res;
    int c = 0, i = a.length() - 1, j = b.length() - 1;

    while (i >= 0 || j >= 0) {
        int op1 = (i >= 0) ? a[i--] - '0' : 0;
        int op2 = (j >= 0) ? b[j--] - '0' : 0;
        int temp = op1 - op2 - c; // вычитание цифр - переход в новый разряд
        if (temp < 0) {
            temp += 10;
            c = 1;
        } else {
            c = 0;
        }
        res.push_back(temp + '0');
    }

    while (res.length() > 1 && res.back() == '0') { // удаление незначащих нулей
        res.pop_back();
    }

    reverse(res.begin(), res.end());
    return res;
}

string karatsuba(const string& x, const string& y) { // алгоритм карацубы 
    if (x == "0" || y == "0") return "0"; // обработка умножения на ноль

    int n = max(x.size(), y.size()); // max длина числа
    n = (n + 1) / 2;

    // деление каждого числа на две части  
    string a = x.substr(0, x.size() - n); // извлечение подстроки из строки x начиная с 1 символа 
    string b = x.substr(x.size() - n); // ... начиная с последнего символа
    string c = y.substr(0, y.size() - n);
    string d = y.substr(y.size() - n);

    string ac = karatsuba(a, c); // рекурсивное деление на части
    string bd = karatsuba(b, d);
    string ad_bc = diff(karatsuba(sum(a, b), sum(c, d)), sum(ac, bd));

    return sum(sum(ac + string(2 * n, '0'), ad_bc + string(n, '0')), bd);
}

string square(const string& num) { // возведение в квадрат 
    return karatsuba(num, num);
}

string sumsquares(const string& input) { // сложение квадратов с n = 20001
    long long n = stoll(input);
    string res = "0";

    for (long long i = 20001; i <= n; ++i) {
        res = sum(res, square(to_string(i)));
    }

    return sum(res, res20k);
}

bool check(const string& input) { // проверка на цифры
    for (char c : input) { // разбиваем строку на символы 
        if (!isdigit(c)) { // проверяем выбраный символ цифра или нет
            return false;
        }
    }
    return true;
}

