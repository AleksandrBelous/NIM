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
    cout << "                                                                     *** ������� ���� \"NIM\" ***\n";
    cout << "                                      ��� � ����, � ������� ��� ������ �� ������� ����� ��������, ����������� �� ���������� ������.\n";
    cout << "                                      �� ���� ��� ����� ���� ����� ����� ���������� ��������� (������ ����) �� ����� �����.\n";
    cout << "                                      ��������� �������� ������ �������!\n";
    cout << "                                      ���������� �����, ������� ��������� ������� � ����.\n";
    switch (i)
    {
    case 1:
        cout << "\n";
        cout << "                                                                   << ������ ���� >>     ����   \n";
        break;
    case 2:
        cout << "\n";
        cout << "                                                                      ������ ����     << ���� >>\n";
        break;
    default:
        break;
    }
    char choice = analysis();
    switch (choice)
    {
    case'R': // �������� ������ �� ����
        gameRules(3 - i);
        break;
    case'L':// �������� ����� �� ����
        gameRules(3 - i);
        break;
    case'E': // ����� Enter
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
    cout << "                                                                      *** ���������� ***\n";
    cout << "                                         ����� ������� �������, ������� ������� �� ���� ������ �������� 'V'\n";
    cout << "                                         ��������� 'V' ������������� �� �������� ���� ��������� 'w', 's', 'a', 'd' ��� ���������.\n";
    cout << "                                         ������� ������ ��� Enter, � ��������� ������� �������� �� ����.\n";
    cout << "                                         �������, ��� ��������� ������� ������ �������!\n";
    cout << "                                         � ����� ������ �� ����� ������ ���� �������:\n";
    cout << "                                                                               Esc - ��������� ���� �� �����.\n";
    cout << "                                                                               'h' - �������� ���������� ���.\n";
    cout << "                                                                               'i' - �������� ��� ����������.\n";
    cout << "                                                                               'b' - ��������� ����.\n";
    switch (i)
    {
    case 1:
        cout << "\n";
        cout << "                                                               << ������ ���� >>     ����   \n";
        break;
    case 2:
        cout << "\n";
        cout << "                                                                  ������ ����     << ���� >>\n";
    default:
        break;
    }
    char choice = analysis();
    switch (choice)
    {
    case'R': // �������� ������ �� ����
        reference(3 - i);
        break;
    case'L':// �������� ����� �� ����
        reference(3 - i);
        break;
    case'E': // ����� Enter
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