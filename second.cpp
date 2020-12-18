#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

const string author = "Поздняков Данил | 28-1 | 18.12.2020\n\n";
const int m = 3;
const int z = 2;
const int n = 2;

struct structItems
{
    char name[15];
    int assessment[z];
};
struct structStudent
{
    char name[20];
    structItems item[n];
};

void second()
{
    structStudent student[m];

    cout << "Введите информацию об учениках" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "Введите имя ученика " << i + 1 << ": "; cin >> student[i].name;
        for (int j = 0; j < n; j++)
        {
            cout << "Название предмета " << j + 1 << ": "; cin >> student[i].item[j].name;
            for (int k = 0; k < z; k++)
            {
                cout << "Введите балл " << k + 1 << ": "; cin >> student[i].item[j].assessment[k];
            }
        }

        cout << endl;
    }

    for (int i = 0; i < m; i++)
    {
        cout << "Ученик: " << student[i].name << endl;
        for (int j = 0; j < n; j++)
        {
            cout << "Название предмета: " << student[i].item[j].name << endl;
            int allAssessments = 0;
            for (int k = 0; k < z; k++)
            {
                allAssessments += student[i].item[j].assessment[k];
            }
            cout << "Средний балл по предмету: " << allAssessments / z << endl;
        }

        cout << endl;
    }

    cout << "Выводим учеников у которых второй тест имеет меньше баллов" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (student[i].item[j].assessment[0] > student[i].item[j].assessment[1])
            {
                cout << "Ученик: " << student[i].name << endl;
                cout << "Предмет: " << student[i].item[j].name << endl;
            }
        }

        cout << endl;
    }

    cout << "Выводим учеников у которых второй тест имеет больше баллов" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (student[i].item[j].assessment[0] < student[i].item[j].assessment[1])
            {
                cout << "Ученик: " << student[i].name << endl;
                cout << "Предмет: " << student[i].item[j].name << endl;
            }
        }

        cout << endl;
    }
}

int main()
{
    //setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << author;

    second();

    return 0;
}
