#include "../ModulesBuliukin/ModulesBuliukin.h"

using namespace std;

void printDeveloperInfo() {
    cout << "© Розробник: Булюкiн В.Ю." << endl;
}

bool logicalExpression(char a, char b) {
    return (a + 1) < (b + 3);
}

void printNumbersInDecAndHex(float x, float y, float z) {
    cout << "Десяткова система: x = " << x << ", y = " << y << ", z = " << z << endl;
    cout << hex << showbase << "Шістнадцяткова система: x = " << (int)x << ", y = " << (int)y << ", z = " << (int)z << endl;
    cout << dec;
}

int main() {
    printDeveloperInfo();

    float x, y, z;
    char a, b;

    cout << "Введіть два символи (a та b): ";
    cin >> a >> b;
    cout << "Результат логічного виразу (a + 1 < b + 3): " << logicalExpression(a, b) << endl;

    cout << "Введіть три числа (x, y, z): ";
    cin >> x >> y >> z;
    printNumbersInDecAndHex(x, y, z);

    try {
        float S; // = s_calculation(x, y, z);
        cout << "Результат обчислення S: " << fixed << setprecision(2) << S << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
