#include "ModulesBuliukin.h"

using namespace std;

void info(char &choose){
    cout << "Введiть символ для вибору модуля.\n"
         << "'u' - для виклику формули з 8 лаби\n"
         << "'o' - для виклику обчислення за шкалою Бофорта\n"
         << "'p' - калькулятор розмiру шкарпеток\n"
         << "'s' - вихiд з програми\n\n";
    cin >> choose;
}

void choose_module(char func_choose){
    if (func_choose == 'u' || func_choose == 'U'){ // лаба 08 s_calc()
        float x, y, S;
        system("cls");
        cout << "Обрано модуль: u\n\n"
             << "Введiть x: ";
        cin >> x;
        cout << "Введiть y: ";
        cin >> y;

        S = s_calculation(y, x, NULL); // виклик формули з записом результату
        cout << "Обчислено: " << S << endl;
    }
    else if (func_choose == 'o' || func_choose == 'O'){ // шкала Бофорта 9.1
        short score;
        system("cls");
        cout << "Обрано модуль: o\n\n"
             << "Введiть бал для обчислення за шкалою: ";
        cin >> score;
        wind_strange(score);
    }
    else if (func_choose == 'p' || func_choose == 'P'){ // шкарпетки 9.2
        short uaSize;
        system("cls");
        cout << "Обрано модуль: p\n\n"
             << "\nВведiть розмiр шкарпеток (UA):\n";
        cin >> uaSize;
        getSocksSizeFromUA(uaSize);
    }
    else if (func_choose == 'a' || func_choose == 'A'){
        unsigned int N;
        system("cls");
        cout << "Обрано модуль: b\n\n"
             << "Введiть число для підрахунку бітів: ";
        cin >> N;

        unsigned int result = countBits(N);
        cout << "Результат підрахунку бітів: " << result << endl;
    }
    else if (func_choose == 's' || func_choose == 'S'){
        //
    }
    else {
        cout << "\aНема такого варiанту\n";
    }
}

int main(){
    char func_choose;

    setUTF8();
    printDeveloperInfo();

    info(func_choose);

    if(func_choose == 's' || func_choose == 'S'){
        cout << "Програму завершено користувачем.\n";
        return 0;
    }

    choose_module(func_choose);

    cout << "Бажаєте повторно викликати модулi программи? (Y/N): ";
    char again;
    cin >> again;

    if (again == 'y' || again == 'Y'){
        info(func_choose);
        choose_module(func_choose);
    }

    return 0;
}
