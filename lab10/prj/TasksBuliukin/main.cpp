#include "modulesbuliukin.h"

using namespace std;

int main()
{
    setUTF8();

    ifstream checkFile("input.txt");
    if (!checkFile.is_open()) {
        ofstream createFile("input.txt");
        if (createFile.is_open()) {
            createFile << "щастя" << endl;
            createFile.close();
            cout << "Створено файл input.txt з тестовим словом 'щастя'" << endl;
        } else {
            cout << "Помилка! Неможливо створити файл input.txt" << endl;
            return 1;
        }
    }
    checkFile.close();

    task1();
    task2();
    task3(1.5, 2.3, 3.7, 42);

    return 0;
}
