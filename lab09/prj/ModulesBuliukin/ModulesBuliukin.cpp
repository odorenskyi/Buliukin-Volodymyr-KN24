#include <iostream>
#include "ModulesBuliukin.h"

using namespace std;

void setUTF8(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

void printDeveloperInfo() {
    cout << "© Розробник: Булюкiн В.Ю.\n" << endl;
}

float s_calculation(float x, float y, float z) { // валiдацiя та обчислення по формулi
    if (x + y <= 0) {
        throw invalid_argument("Помилка: x + y має бути більше 0.");
    }
    float S = sin(x) + (3 * pow(y, 5)) / sqrt(x + y);
    return S;
}

void wind_strange(short score){
    string speed_table[] = { // перелiк швидкостей
        "< 0.3", "0.3 - 1.5", "1.6 - 9.4", "9.4 - 5.4", "5.5 - 7.9",
        "8.0 - 10.7", "10.8 - 13.8", "13.9 - 17.1", "17.2 - 20.7",
        "20.8 - 24.4", "24.5 - 28.4", "28.5 - 32.6", ">= 32.7"
    };

    string description_table[] = { // перелiк опису
        "Штиль", "Тихий", "Легкий", "Слабкий", "Помірний",
        "Свіжий", "Сильний", "Міцний", "Дуже міцний",
        "Шторм", "Сильний шторм", "Шквальний шторм", "Ураган (буревій)"
    };

    if(score >= 0 && score <= 12){ // валiдацiя та виклик через iндекс
        cout << "Швидкість: " << speed_table[score] << " м/с\n";
        cout << "Характеристика: " << description_table[score] << endl;
    } else {
        cout << "Аут оф ренж друже..\n";
    }
}

void getSocksSizeFromUA(short uaSize){
    int ua_table[] = {23, 25, 27, 29, 31};
    string eu_table[] = {"37/38", "39/40", "41/42", "43/44", "45/46"};
    int us_uk_table[] = {8, 9, 10, 11, 12};

    for(int i = 0; i < 5; i++){
        if(uaSize == ua_table[i]){
            cout << "Розмір Україна: " << ua_table[i] << endl;
            cout << "Розмір ЄС: " << eu_table[i] << endl;
            cout << "Розмір США/Великобританія: " << us_uk_table[i] << endl;
            return;
        }
    }

    cout << "Невідомий розмір. Спробуйте ще раз.\n";
}

