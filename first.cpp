#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

const string author = "Поздняков Данил | 28-1 | 18.12.2020\n\n";
const int n = 5;

struct room
{
    char name[50];
    double area;
    int numberOfRooms;
    int _floor;
};

void showRooms(string title, int counter, struct room rooms[n])
{
    cout << title << endl;
    for (int i = 0; i < counter; i++)
    {
        cout << "Имя владельца: " << rooms[i].name << endl;
        cout << "Площадь: " << rooms[i].area << endl;
        cout << "Кол. комнат: " << rooms[i].numberOfRooms << endl;
        cout << "Этаж: " << rooms[i]._floor << endl;
    }
}

void first()
{
    struct room all, list[n];

    cout << "Введите информацию о комнатах\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Фамилия владельца: "; cin >> all.name;
        cout << "Площадь: "; cin >> all.area;
        cout << "Количество комнат: "; cin >> all.numberOfRooms;
        cout << "Введите этаж: "; cin >> all._floor;
        list[i] = all;
        cout << endl;
    }
    cout << endl;

    double minArea;
    cout << "Какое минимальное количество площади Вам нужно, мы подберём лучший вариантик!: ";
    cin >> minArea;

    cout << "Вывод комнат где площадь меньше 30 кв.м\n";
    struct room oneRoom[n], twoRoom[n], threeRoom[n], moreRoom[n];
    int counter = 0, counterOneRoom = 0, counterTwoRoom = 0, counterThreeRoom = 0, counterMoreRoom = 0;
    for (int i = 0; i < n; i++)
    {
        struct room* pRoom = &list[i];

        if (list[i].area < 30)
        {
            cout << "Имя владельца: " << pRoom->name << endl;
            cout << "Площадь: " << pRoom->area << endl;
            cout << "Кол. комнат: " << pRoom->numberOfRooms << endl;
            cout << "Этаж: " << pRoom->_floor << endl;
            counter++;
        }

        if (pRoom->numberOfRooms == 1)
        {
            oneRoom[counterOneRoom] = list[i];
            counterOneRoom++;
        }
        else if (pRoom->numberOfRooms == 2)
        {
            twoRoom[counterTwoRoom] = list[i];
            counterTwoRoom++;
        }
        else if (pRoom->numberOfRooms == 3)
        {
            oneRoom[counterThreeRoom] = list[i];
            counterThreeRoom++;
        }
        else
        {
            if (pRoom->numberOfRooms != 0)
            {
                oneRoom[counterMoreRoom] = list[i];
                counterMoreRoom++;
            }
        }

        cout << endl;
    }
    cout << "Количество квартир где площадь менньше 30 кв.м: " << counter << endl;

    showRooms("Квартиры с одной комнатой", counterOneRoom, oneRoom); cout << endl;
    showRooms("Квартиры с двумя комнатами", counterTwoRoom, twoRoom); cout << endl;
    showRooms("Квартиры с тремя комнатами", counterThreeRoom, threeRoom); cout << endl;
    showRooms("Квартиры больше чем 3 комнаты", counterMoreRoom, moreRoom); cout << endl;

    cout << "Мы подобрали для вас вариантики!" << endl;
    for (int i = 0; i < n; i++)
    {
        struct room* pRoom = &list[i];

        if (pRoom->area > minArea)
        {
            cout << "Имя владельца: " << pRoom->name << endl;
            cout << "Площадь: " << pRoom->area << endl;
            cout << "Кол. комнат: " << pRoom->numberOfRooms << endl;
            cout << "Этаж: " << pRoom->_floor << endl;
            cout << endl;
        }
    }
}

int main()
{
    //setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << author;

    cout << "Певое задание\n";
    first();

    return 0;
}
