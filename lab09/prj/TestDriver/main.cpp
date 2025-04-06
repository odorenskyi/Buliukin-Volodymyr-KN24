#include <iostream>
#include <cmath>
#include "ModulesBuliukin.h"

using namespace std;

int main() {
    setUTF8();
    printDeveloperInfo();

    // s_calc() test
    try {
        float x = 2.0f, y = 3.0f, z = 1.0f;
        float result = s_calculation(x, y, z);
        cout << "Результат обчислення S: " << result << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    // wind_strange
    short windScore = 7;
    cout << "\nТест для wind_strange (швидкість вітру):\n";
    wind_strange(windScore);

    windScore = 15; // out of range
    cout << "\nТест для wind_strange (неправильний індекс):\n";
    wind_strange(windScore);

    // test func getSocksSizeFromUA
    short uaSize = 25;
    cout << "\nТест для getSocksSizeFromUA (розмір Україна):\n";
    getSocksSizeFromUA(uaSize);

    uaSize = 30; // out of range
    cout << "\nТест для getSocksSizeFromUA (неправильний розмір):\n";
    getSocksSizeFromUA(uaSize);

    return 0;
}
