#include "../ModulesBuliukin/ModulesBuliukin.h"

using namespace std;

void runTests() {
    try {
        float S = s_calculation(1.5, 2.0, 3.0);
        cout << "Тест 1: Успішно. S = " << S << endl;
    } catch (...) {
        cout << "Тест 1: Провалено" << endl;
    }

    try {
        s_calculation(-2.0, -1.0, 0.0);
        cout << "Тест 2: Провалено" << endl;
    } catch (const invalid_argument& e) {
        cout << "Тест 2: Успішно. Виявлено помилку: " << e.what() << endl;
    }
}

int main() {
    runTests();
    return 0;
}