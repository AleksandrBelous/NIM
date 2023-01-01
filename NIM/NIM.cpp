#include "NIM.h"
#include<Windows.h>
#include<iostream>
#include"prototypes.h"

using std::cout;
using std::cin;

void NIM::selectLevel(int i)
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (register int i = 0; i < 19; i++)
        cout << "\n";
    switch (i)
    {
    case 1:
        cout << "                                                             Уровень игры:   << ПРОСТОЙ >>    СЛОЖНЫЙ   ";
        break;
    case 2:
        cout << "                                                             Уровень игры:      ПРОСТОЙ    << СЛОЖНЫЙ >>";
    default:
        break;
    }
    char choice = analysis();
    switch (choice)
    {
    case 'R': // движение вправо по меню
        selectLevel(3 - i);
        break;
    case 'L':// движение влево по меню
        selectLevel(3 - i);
        break;
    case 'E': // нажат Enter
        if (i == 1) // выбран простой уровень
        {
            system("cls");
            easy = true;
            selectType(1);
        }
        if (i == 2) // выбран сложный уровень
        {
            system("cls");
            easy = false;
            selectType(1);
        }
        break;
    default:
        selectLevel(i);
        break;
    }
}

void NIM::selectType(int i)
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (register int i = 0; i < 19; i++)
        cout << "\n";
    switch (i)
    {
    case 1:
        cout << "                                                                  Количество предметов в кучках:\n\n";
        cout << "                                                                   << СЛУЧАЙНОЕ >>    РАВНОЕ   ";
        break;
    case 2:
        cout << "                                                                  Количество предметов в кучках:\n\n";
        cout << "                                                                      СЛУЧАЙНОЕ    << РАВНОЕ >>";
    default:
        break;
    }
    char choice = analysis();
    switch (choice)
    {
    case 'R': // движение вправо по меню
        selectType(3 - i);
        break;
    case 'L':// движение влево по меню
        selectType(3 - i);
        break;
    case 'E': // нажат Enter
        if (i == 1) // выбрано разное кол-во предметов
        {
            dif = true;
            create();
        }
        if (i == 2) // выбрано одинаковое кол-во предметов
        {
            dif = false;
            create();
        }
        break;
    default:
        selectType(i);
        break;
    }
}

void NIM::create()
{
    system("cls");
    for (register int i = 0; i < 19; i++)
        cout << "\n";
    cout << "                                             Количество кучек (не более 21 для корректного отображения на игровом поле): ";
    std::cin >> n; // number_of_piles, кол-во кучек
    if (n <= 0)
    {
        cout << "\n                                              Ошибка! Количество кучек должно быть выражено натуральным числом\n\n";
        system("pause");
        system("cls");
        menu(1);
    }
    cout << "\n                                  Максимальное количество предметов в кучке (не более 81 для корректного отображения на игровом поле): ";
    //unsigned int m; 
    std::cin >> m; // max_of_objects, макс. возможное кол-во предметов в одной кучке
    if (m <= 0)
    {
        cout << "\n                                              Ошибка! Количество предметов должно быть выражено натуральным числом\n\n";
        system("pause");
        system("cls");
        menu(1);
    }
    // генерируем случайное кол-во предметов для i-той кучки, но не более max предметов
    unsigned int* number_of_objects_in_one_pile = new unsigned int[2 * n]; // отталкиваемся от кол-ва кучек n 
    if (dif) // разное кол-во предметов в кучках
        for (register unsigned int i = 1; i < 2 * n; i += 2)
            number_of_objects_in_one_pile[i] = random() % m + 1; // в одной кучке будет от 1 до m предметов
    else // одинаковое кол-во предметов в кучках
        for (register unsigned int i = 1; i < 2 * n; i += 2)
            number_of_objects_in_one_pile[i] = m;
    // для наглядности представим предметы, разложенные по кучкам, в матричном виде
    plain = new char* [2 * n]; // plain - это игровая поверхность
    for (register unsigned int i = 0; i < 2 * n; i++)
        plain[i] = new char[2 * m];
    // заполним всю игровую поверхность пустотами по умолчанию
    for (register unsigned int i = 0; i < 2 * n; i++)
        for (register unsigned int j = 0; j < 2 * m; j++)
            plain[i][j] = ' ';
    // нарисуем предметы в виде |
    for (register unsigned int i = 1; i < 2 * n; i += 2)
        for (register unsigned int j = 1; j < 2 * number_of_objects_in_one_pile[i]; j += 2)
            plain[i][j] = '|';
    plain[y][x] = 'V';
    system("cls");
    delete[] number_of_objects_in_one_pile;
    paint();
}

void NIM::paint()
{
    COORD coord;
    coord.X = 0;
    coord.Y = (44 - 2 * n) / 2; // отступ сверху // 44
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (register unsigned int i = 0; i < 2 * n; i++)
    {
        unsigned int left_margin = (168 - 2 * m - 6) / 2; // отступ слева // 168
        for (register unsigned int a = 0; a < left_margin; a++)
            cout << " ";
        for (register unsigned int j = 0; j < 2 * m; j++)
            cout << plain[i][j];
        if (i % 2 != 0)
            cout << " [" << number_of_hip(i) << "]";
        cout << "\n";
    }
    logic();
}
void NIM::logic()
{
    char choice = analysis();
    switch (choice)
    {
    case'R': // движение вправо, y=const, x++
        plain[y][x] = ' ';
        if (x + 1 == 2 * m)
        {
            x = 1;
            plain[y][x] = 'V';
            paint();
        }
        else
        {
            x += 2;
            plain[y][x] = 'V';
            paint();
        }
        break;
    case'L': // движение влево, y=const, x--
        plain[y][x] = ' ';
        if (x - 1 == 0)
        {
            x = 2 * m - 1;
            plain[y][x] = 'V';
            paint();
        }
        else
        {
            x -= 2;
            plain[y][x] = 'V';
            paint();
        }
        break;
    case'U': // движение вверх, y--, x=const
        plain[y][x] = ' ';
        if (y - 1 == -1)
        {
            y = 2 * n - 2;
            plain[y][x] = 'V';
            paint();
        }
        else
        {
            y -= 2;
            plain[y][x] = 'V';
            paint();
        }
        break;
    case'D': // движение вниз, y++, x=const
        plain[y][x] = ' ';
        if (y + 2 == 2 * n)
        {
            y = 0;
            plain[y][x] = 'V';
            paint();
        }
        else
        {
            y += 2;
            plain[y][x] = 'V';
            paint();
        }
        break;
    case'E': // нажат Enter
        plain[y + 1][x] = ' ';
        if (isFinish() == false)
            winRestart();
        else
            paint();
        break;
    case'S': // клавиша Esc
        rules();
        break;
    case'T': // подсказка
        tip();
        break;
    case'A': // передать ход компьютеру
        AImove();
        break;
    case'F':
        buy();
        break;
    default:
        paint();
    }
}

void NIM::rules()
{
    system("cls");
    for (register int i = 0; i < 15; i++)
        cout << "\n";
    cout << "                                                                      *** Общие правила ***\n";
    cout << "                                          Два игрока по очереди берут предметы, разложенные по нескольким кучкам.\n";
    cout << "                                          За один ход может быть взято любое количество предметов (больше нуля) из одной кучки.\n";
    cout << "                                          Выбранные предметы нельзя вернуть!\n";
    cout << "                                          Выигрывает игрок, взявший последний предмет в игре.\n";
    cout << "                                          Чтобы выбрать предмет, следует указать на него сверху символом 'V'\n";
    cout << "                                          Указатель 'V' передвигается по игровому полю клавишами 'w', 's', 'a', 'd' или стрелками.\n";
    cout << "                                          Нажмите пробел или Enter, и выбранный предмет удалится из игры.\n";
    cout << "                                          В любой момент во время своего хода нажмите:\n";
    cout << "                                                                                Esc - поставить игру на паузу.\n";
    cout << "                                                                                't' - показать выигрышный ход.\n";
    cout << "                                                                                'i' - передать ход компьютеру.\n";
    cout << "                                                                                'b' - завершить игру.\n";
    cout << "                                          Esc - вернуться к игре.\n";
    char answer = analysis();
    switch (answer)
    {
    case'S':
        system("cls");
        paint();
        break;
    case'T':
        tip();
        break;
    case'A':
        AImove();
        break;
    case'F':
        buy();
        break;
    default:
        rules();
        break;
    }
}