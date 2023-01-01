#include<Windows.h>
#include<iostream>
#include<conio.h>
#include"prototypes.h"
#include"NIM.h"

using std::cout;

void menu(int i)
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (register int i = 0; i < 15; i++)
        cout << "\n";
    switch (i)
    {
    case 1:
        cout << "                                                                        -=-=-=-=-=-==-=-=-=-=-=-\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |   << ÍÀ×ÀÒÜ ÈÃÐÓ >>  |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |     ÏÐÀÂÈËÀ ÈÃÐÛ     |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |      ÓÏÐÀÂËÅÍÈÅ      |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |        ÂÛÕÎÄ         |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        -=-=-=-=-=-==-=-=-=-=-=-";
        break;
    case 2:
        cout << "                                                                        -=-=-=-=-=-==-=-=-=-=-=-\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |      ÍÀ×ÀÒÜ ÈÃÐÓ     |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |  << ÏÐÀÂÈËÀ ÈÃÐÛ >>  |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |      ÓÏÐÀÂËÅÍÈÅ      |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |        ÂÛÕÎÄ         |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        -=-=-=-=-=-==-=-=-=-=-=-";
        break;
    case 3:
        cout << "                                                                        -=-=-=-=-=-==-=-=-=-=-=-\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |      ÍÀ×ÀÒÜ ÈÃÐÓ     |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |     ÏÐÀÂÈËÀ ÈÃÐÛ     |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |   << ÓÏÐÀÂËÅÍÈÅ >>   |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |        ÂÛÕÎÄ         |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        -=-=-=-=-=-==-=-=-=-=-=-";
        break;
    case 4:
        //cout << "\n";
        cout << "                                                                        -=-=-=-=-=-==-=-=-=-=-=-\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |      ÍÀ×ÀÒÜ ÈÃÐÓ     |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |     ÏÐÀÂÈËÀ ÈÃÐÛ     |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |      ÓÏÐÀÂËÅÍÈÅ      |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        |     << ÂÛÕÎÄ >>      |\n";
        cout << "                                                                        |                      |\n";
        cout << "                                                                        -=-=-=-=-=-==-=-=-=-=-=-";
        break;
    default:
        break;
    }
    char choice = analysis();
    switch (choice)
    {
    case 'U': // äâèæåíèå ââåðõ ïî ìåíþ
        if (i != 1)
            menu(i - 1);
        else
            menu(4);
        break;
    case 'D': // äâèæåíèå âíèç ïî ìåíþ
        if (i != 4)
            menu(i + 1);
        else
            menu(1);
        break;
    case 'E': // íàæàò Enter
        if (i == 1)
        {
            system("cls");
            NIM obj;
        }
        if (i == 2)
        {
            system("cls");
            gameRules(1);
        }
        if (i == 3)
        {
            system("cls");
            reference(1);
        }
        if (i == 4)
        {
            system("cls");
            for (register int i = 0; i < 20; i++)
                cout << "\n";
            cout << "                                                                        Ïðèõîäèòå èãðàòü ñíîâà!\n";
            Sleep(10000);
            exit(0);
        }
        break;
    default:
        menu(i);
        break;
    }
}