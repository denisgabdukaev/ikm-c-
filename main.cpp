#include "header.h"

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    
    cout << "Введите натуральное число n (n >= 20000): ";
    getline(cin, input); // ввод строки 

    if (!check(input)) { // проверка на корректность ввода
        cerr << "Ошибка: Ввод должен содержать только цифры." << endl;
        return 1;
    }

    long long n = stoll(input);

    if (n < 20000) { // проверка на минимальное значение
        cerr << "Ошибка: n должен быть больше или равен 20000." << endl;
        return 1;
   }

    string result = sumsquares(input);

    cout << "Сумма квадратов первых " << n << " натуральных чисел: " << result << endl;
    
    return 0;
}
