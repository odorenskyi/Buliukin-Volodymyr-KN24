#include "ModulesBuliukin.h"

using namespace std;

void printDeveloperInfo() {
    cout << "© Розробник: Булюкiн В.Ю." << endl;
}
float s_calculation(float x, float y, float z) {
    if (x + y <= 0) {
        throw invalid_argument("Помилка: x + y має бути більше 0.");
    }
    float S = sin(x) + (3 * pow(y, 5)) / sqrt(x + y);
    return S;
}