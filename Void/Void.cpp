#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string dir;
    stringstream ss;
    while (true)
    {
        cout << "Введите дерикторию файла: ";
        cin >> dir;
        ifstream ifs(dir);
        if (!ifs.is_open())
        {
            cout << "Не удалось открыть файл, возможно вы неправельно ввели путь" << endl << endl;
            ss.clear();
        }
        else
        {
            ss << noskipws;
            ss << ifs.rdbuf();
            ifs.close();
            break;
        }
    }

    ofstream ofs(dir);
    char a = '\0', b;
    char simvol;
    string simvoly;
    cin.ignore();
    cout << "Ведите символы который нужно сжать: ";
    getline(cin, simvoly);
    int prov;

    ss.clear();
    ss.seekg(0, ios::beg);
    while (ss >> b)
     {
        if (simvoly.find(b) != string::npos && a == b) continue;
        else
        {
            ofs.put(b);
            a = b;
        }
     }
}