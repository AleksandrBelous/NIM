#include"prototypes.h"
#include<Windows.h>
#include<iostream>
#include<conio.h>
#include"NIM.h"

using std::cout;

void NIM::winRestart() // для перезапуска игры после победы игрока
{
    system("cls");
    for (register int i = 0; i < 19; i++)
        cout << "\n";
    cout << "                                                                      Поздравляем! Вы победили!!!\n\n";
    cout << "                                                                       Начать новую игру? [Y/n]";
    char answer = _getch();
    switch (answer)
    {
    case'y':
        system("cls");
        menu(1);
        break;
    case -83:
        system("cls");
        menu(1);
        break;
    case'n':
        buy();
        break;
    case -30:
        buy();
        break;
    default:
        winRestart();
        break;
    }
}

void NIM::loseRestart() // для перезапуска игры после поражения игрока
{
    system("cls");
    for (register int i = 0; i < 19; i++)
        cout << "\n";
    cout << "                                                                         Сожалеем! Вы проиграли\n\n";
    cout << "                                                                        Начать новую игру? [Y/n]";
    char answer = _getch();
    switch (answer)
    {
    case 'y':
        system("cls");
        menu(1);
        break;
    case -83:
        system("cls");
        menu(1);
        break;
    case 'n':
        buy();
        break;
    case -30:
        buy();
        break;
    default:
        winRestart();
        break;
    }
}

void NIM::buy()
{
    system("cls");
    for (register int i = 0; i < 20; i++)
        cout << "\n";
    cout << "                                                                        Приходите играть снова!\n";
    exit(0);
}