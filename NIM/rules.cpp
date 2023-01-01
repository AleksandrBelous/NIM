#include<Windows.h>
#include<iostream>
#include"prototypes.h"
#include"NIM.h"

using std::cout;

void gameRules(int i)
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (register int i = 0; i < 16; i++)
        cout << "\n";
    cout << "                                                                     *** Правила игры \"NIM\" ***\n";
    cout << "                                      Ним — игра, в которой два игрока по очереди берут предметы, разложенные по нескольким кучкам.\n";
    cout << "                                      За один ход может быть взято любое количество предметов (больше нуля) из одной кучки.\n";
    cout << "                                      Выбранные предметы нельзя вернуть!\n";
    cout << "                                      Выигрывает игрок, взявший последний предмет в игре.\n";
    switch (i)
    {
    case 1:
        cout << "\n";
        cout << "                                                                   << НАЧАТЬ ИГРУ >>     МЕНЮ   \n";
        break;
    case 2:
        cout << "\n";
        cout << "                                                                      НАЧАТЬ ИГРУ     << МЕНЮ >>\n";
        break;
    default:
        break;
    }
    char choice = analysis();
    switch (choice)
    {
    case'R': // движение вправо по меню
        gameRules(3 - i);
        break;
    case'L':// движение влево по меню
        gameRules(3 - i);
        break;
    case'E': // нажат Enter
        if (i == 1)
        {
            system("cls");
            NIM obj;
        }
        if (i == 2)
        {
            system("cls");
            menu(2);
        }
        break;
    default:
        gameRules(i);
        break;
    }
}

void reference(int i)
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (register int i = 0; i < 15; i++)
        cout << "\n";
    cout << "                                                                      *** УПРАВЛЕНИЕ ***\n";
    cout << "                                         Чтобы выбрать предмет, следует указать на него сверху символом 'V'\n";
    cout << "                                         Указатель 'V' передвигается по игровому полю клавишами 'w', 's', 'a', 'd' или стрелками.\n";
    cout << "                                         Нажмите пробел или Enter, и выбранный предмет удалится из игры.\n";
    cout << "                                         Помните, что выбранный предмет нельзя вернуть!\n";
    cout << "                                         В любой момент во время своего хода нажмите:\n";
    cout << "                                                                               Esc - поставить игру на паузу.\n";
    cout << "                                                                               'h' - показать выигрышный ход.\n";
    cout << "                                                                               'i' - передать ход компьютеру.\n";
    cout << "                                                                               'b' - завершить игру.\n";
    switch (i)
    {
    case 1:
        cout << "\n";
        cout << "                                                               << НАЧАТЬ ИГРУ >>     МЕНЮ   \n";
        break;
    case 2:
        cout << "\n";
        cout << "                                                                  НАЧАТЬ ИГРУ     << МЕНЮ >>\n";
    default:
        break;
    }
    char choice = analysis();
    switch (choice)
    {
    case'R': // движение вправо по меню
        reference(3 - i);
        break;
    case'L':// движение влево по меню
        reference(3 - i);
        break;
    case'E': // нажат Enter
        if (i == 1)
        {
            system("cls");
            NIM obj;
        }
        if (i == 2)
        {
            system("cls");
            menu(3);
        }
        break;
    default:
        reference(i);
        break;
    }
}