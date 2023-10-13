#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 
using namespace std;

int main() {
    // ������������ ��������� ��� ����� � ������
    SetConsoleCP(1251);       
    SetConsoleOutputCP(1251);  

    const int max_sequence_length = 257;
    char line[max_sequence_length + 1]; // +1 ��� ������������� ����
    string search_sequence; 
    while (true) {
        cout << "������ ����������� ��� ������ (��� ������ 'exit' ��� ������): ";
        getline(cin, search_sequence); // ������� ��� ������, ��������� ������

        if (search_sequence == "exit") {
            break; // ����� � ��������
        }

        ifstream file("text_city_ukr.txt"); 

        if (!file) {
            cout << "������� �������� �����!" << endl;
            continue; // ������� �� �������� �������� �����
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
            cout << "����������� '" << search_sequence << "' ��������!" << endl;
        }
        else {
            cout << "����������� '" << search_sequence << "' �� ��������!" << endl;
        }

        file.close(); // ��������� ����
    }

    return 0;
}
