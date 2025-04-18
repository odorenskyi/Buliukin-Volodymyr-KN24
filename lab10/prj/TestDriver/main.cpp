#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include "modulesbuliukin.h"

using namespace std;

void test_s_calculation() {
    // Test case 1: normal values
    float result1 = s_calculation(2.0f, 3.0f, 1.0f);
    assert(abs(result1 - (sin(2.0f) + (3 * pow(3.0f, 5)) / sqrt(2.0f + 3.0f))) < 0.0001f);

    // Test case 2: different values
    float result2 = s_calculation(1.5f, 2.3f, 3.7f);
    assert(abs(result2 - (sin(1.5f) + (3 * pow(2.3f, 5)) / sqrt(1.5f + 2.3f))) < 0.0001f);

    cout << "s_calculation tests passed!" << endl;
}

void test_task1() {
    // Test input.txt creation and reading
    ofstream test_file("input.txt");
    test_file << "тест" << endl;
    test_file.close();

    ifstream check_file("input.txt");
    string content;
    check_file >> content;
    assert(content == "тест");
    check_file.close();

    // Test task1 output
    task1();
    ifstream output_file("output.txt");
    string line;
    bool found_developer = false;
    bool found_vowels = false;

    while (getline(output_file, line)) {
        if (line.find("Булюкiн") != string::npos) found_developer = true;
        if (line.find("Кількість голосних") != string::npos) found_vowels = true;
    }
    output_file.close();

    assert(found_developer && found_vowels);
    cout << "File operations tests passed!" << endl;
}

void test_task2() {
    // Create test input
    ofstream test_file("input.txt");
    test_file << "абв" << endl;
    test_file.close();

    task2();

    // Check if consonants count was appended
    ifstream check_file("input.txt");
    string content((istreambuf_iterator<char>(check_file)),
                   istreambuf_iterator<char>());
    check_file.close();

    assert(content.find("Кількість приголосних") != string::npos);
    assert(content.find("Дата та час") != string::npos);

    cout << "Task2 tests passed!" << endl;
}

void test_task3() {
    task3(1.5f, 2.3f, 3.7f, 42);

    ifstream output_file("output.txt");
    string content((istreambuf_iterator<char>(output_file)),
                   istreambuf_iterator<char>());
    output_file.close();

    assert(content.find("s_calculation(1.5, 2.3, 3.7)") != string::npos);
    assert(content.find("Число 42 у двійковому коді") != string::npos);

    cout << "Task3 tests passed!" << endl;
}

int main() {
    setUTF8();

    cout << "Starting tests..." << endl;

    test_s_calculation();
    test_task1();
    test_task2();
    test_task3();

    cout << "All tests passed successfully!" << endl;

    return 0;
}
