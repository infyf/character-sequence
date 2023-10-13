#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 
using namespace std;

int main() {
    // Встановлюємо кодування для вводу і виводу
    SetConsoleCP(1251);       
    SetConsoleOutputCP(1251);  

    const int max_sequence_length = 257;
    char line[max_sequence_length + 1]; // +1 для завершального нуля
    string search_sequence; 
    while (true) {
        cout << "Введіть послідовність для пошуку (або введіть 'exit' для виходу): ";
        getline(cin, search_sequence); // Зчитуємо всю строку, включаючи пробіли

        if (search_sequence == "exit") {
            break; // Вихід з програми
        }

        ifstream file("text_city_ukr.txt"); 

        if (!file) {
            cout << "Помилка відкриття файлу!" << endl;
            continue; // Перейти до наступної ітерації циклу
        }

        bool found = false;

        
        while (file.getline(line, max_sequence_length + 1)) {
            string current_line = line;
            if (current_line.find(search_sequence) != string::npos) {
                found = true;
                break;
            }
        }

      
        if (found) {
            cout << "Послідовність '" << search_sequence << "' знайдена!" << endl;
        }
        else {
            cout << "Послідовність '" << search_sequence << "' не знайдена!" << endl;
        }

        file.close(); // Закриваємо файл
    }

    return 0;
}
