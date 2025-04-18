#include "modulesbuliukin.h"

using namespace std;

void setUTF8(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

float s_calculation(float x, float y, float z) {
    if (x + y <= 0) {
        cout << "Помилка: x + y має бути більше 0.";
    }

    float S = sin(x) + (3 * pow(y, 5)) / sqrt(x + y);

    return S;
}

void task1() {
    string word;
    ifstream in("input.txt");
    if (!in.is_open()) {
        cout << "Помилка відкриття вхідного файлу!" << endl;
        return;
    }
    in >> word;
    in.close();

    ofstream out("output.txt");
    if (!out.is_open()) {
        cout << "Помилка відкриття вихідного файлу!" << endl;
        return;
    } else {
        cout << "Файл вiдкритий успiшно!\n";
    }

    out << "Розробник: Булюкiн В.Ю." << endl
        << "Центральноукраїнський Нацiональний Технiчний Унiверситет" << endl
        << "Кропивницький, Україна" << endl
        << "Рiк розробки: 2025" << endl << endl;

    int vowels = 0;
    string ukrainianVowels = "аеєиіїоуюяАЕЄИІЇОУЮЯ";
    for (char c : word) {
        if (ukrainianVowels.find(c) != string::npos) {
            vowels++;
        }
    }
    out << "Кількість голосних літер у слові \"" << word << "\": " << vowels << endl;


    string poem = "До щастя не пускає лінощів орава. У чім воно ніхто не знає до пуття. "
                 "Навчитись радісно робити кожну справу Найперше правило щасливого життя.";
    
    out << "Слово \"" << word << "\" " << (poem.find(word) != string::npos ? "є" : "відсутнє") 
        << " у вірші Віталія Іващенка" << endl;
    out.close();
}

void task2() {
    ifstream in("input.txt");
    if (!in.is_open()) {
        cout << "Помилка відкриття вхідного файлу!" << endl;
        return;
    }

    string content, line;
    while (getline(in, line)) {
        content += line + "\n";
    }
    in.close();

    int consonants = 0;
    for (char c : content) {
        if (isalpha(c) && !strchr("аеєиіїоуюяАЕЄИІЇОУЮЯ", c)) {
            consonants++;
        }
    }
    
    ofstream out("input.txt", ios::app);
    if (!out.is_open()) {
        cout << "Помилка відкриття файлу для дозапису!" << endl;
        return;
    }
    
    time_t now = time(0);
    char* dt = ctime(&now);
    
    out << "\nКількість приголосних літер у файлі: " << consonants << endl;
    out << "Дата та час дозапису: " << dt;
    out.close();
}

void task3(float x, float y, float z, int b) {
    ofstream out("output.txt", ios::app);
    if (!out.is_open()) {
        cout << "Помилка відкриття файлу для дозапису!" << endl;
        return;
    }

    out << "\nРезультати обчислень:" << endl;
    out << "s_calculation(" << x << ", " << y << ", " << z << ") = " << s_calculation(x, y, z) << endl;

    out << "Число " << b << " у двійковому коді: ";
    for (int i = 31; i >= 0; i--) {
        out << ((b >> i) & 1);
    }
    out << endl;
    
    out.close();
}
