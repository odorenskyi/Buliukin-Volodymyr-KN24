#include "ModulesBuliukin.h"

using namespace std;

// test s_calculation
void test_s_calculation() {
    try {
        float x = 2.0f, y = 3.0f, z = 1.0f;
        float result = s_calculation(x, y, z);
        cout << "Результат обчислення S: " << result << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}

// Функция для теста wind_strange
void test_wind_strange() {
    short windScore = 7;
    cout << "\nТест для wind_strange (швидкість вітру):\n";
    wind_strange(windScore);

    windScore = 15; // out of range
    cout << "\nТест для wind_strange (неправильний індекс):\n";
    wind_strange(windScore);
}

// Функция для теста getSocksSizeFromUA
void test_getSocksSizeFromUA() {
    short uaSize = 25;
    cout << "\nТест для getSocksSizeFromUA (розмір Україна):\n";
    getSocksSizeFromUA(uaSize);

    uaSize = 30; // out of range
    cout << "\nТест для getSocksSizeFromUA (неправильний розмір):\n";
    getSocksSizeFromUA(uaSize);
}

// Функция для теста countBits
void test_countBits() {
    unsigned int testCases[] = {0, 255, 128, 7483650, 1, 1024};
    unsigned int expectedResults[] = {24, 16, 23, 15, 23, 23};

    cout << "\nТест для countBits:\n";
    for (int i = 0; i < 6; i++) {
        unsigned int N = testCases[i];
        unsigned int expected = expectedResults[i];
        unsigned int result = countBits(N);

        cout << "Вхідне значення: " << N << "\n";
        cout << "Очікуваний результат: " << expected << "\n";
        cout << "Отриманий результат: " << result << "\n";
        if (result == expected) {
            cout << "Тест пройшов успішно!\n\n";
        } else {
            cout << "Тест не пройшов!\n\n";
        }
    }
}

int main() {
    setUTF8();
    printDeveloperInfo();

    test_s_calculation();
    test_wind_strange();
    test_getSocksSizeFromUA();
    test_countBits();

    return 0;
}
