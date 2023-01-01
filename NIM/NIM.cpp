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
        cout << "                                                             ������� ����:   << ������� >>    �������   ";
        break;
    case 2:
        cout << "                                                             ������� ����:      �������    << ������� >>";
    default:
        break;
    }
    char choice = analysis();
    switch (choice)
    {
    case 'R': // �������� ������ �� ����
        selectLevel(3 - i);
        break;
    case 'L':// �������� ����� �� ����
        selectLevel(3 - i);
        break;
    case 'E': // ����� Enter
        if (i == 1) // ������ ������� �������
        {
            system("cls");
            easy = true;
            selectType(1);
        }
        if (i == 2) // ������ ������� �������
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
        cout << "                                                                  ���������� ��������� � ������:\n\n";
        cout << "                                                                   << ��������� >>    ������   ";
        break;
    case 2:
        cout << "                                                                  ���������� ��������� � ������:\n\n";
        cout << "                                                                      ���������    << ������ >>";
    default:
        break;
    }
    char choice = analysis();
    switch (choice)
    {
    case 'R': // �������� ������ �� ����
        selectType(3 - i);
        break;
    case 'L':// �������� ����� �� ����
        selectType(3 - i);
        break;
    case 'E': // ����� Enter
        if (i == 1) // ������� ������ ���-�� ���������
        {
            dif = true;
            create();
        }
        if (i == 2) // ������� ���������� ���-�� ���������
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
    cout << "                                             ���������� ����� (�� ����� 21 ��� ����������� ����������� �� ������� ����): ";
    std::cin >> n; // number_of_piles, ���-�� �����
    if (n <= 0)
    {
        cout << "\n                                              ������! ���������� ����� ������ ���� �������� ����������� ������\n\n";
        system("pause");
        system("cls");
        menu(1);
    }
    cout << "\n                                  ������������ ���������� ��������� � ����� (�� ����� 81 ��� ����������� ����������� �� ������� ����): ";
    //unsigned int m; 
    std::cin >> m; // max_of_objects, ����. ��������� ���-�� ��������� � ����� �����
    if (m <= 0)
    {
        cout << "\n                                              ������! ���������� ��������� ������ ���� �������� ����������� ������\n\n";
        system("pause");
        system("cls");
        menu(1);
    }
    // ���������� ��������� ���-�� ��������� ��� i-��� �����, �� �� ����� max ���������
    unsigned int* number_of_objects_in_one_pile = new unsigned int[2 * n]; // ������������� �� ���-�� ����� n 
    if (dif) // ������ ���-�� ��������� � ������
        for (register unsigned int i = 1; i < 2 * n; i += 2)
            number_of_objects_in_one_pile[i] = random() % m + 1; // � ����� ����� ����� �� 1 �� m ���������
    else // ���������� ���-�� ��������� � ������
        for (register unsigned int i = 1; i < 2 * n; i += 2)
            number_of_objects_in_one_pile[i] = m;
    // ��� ����������� ���������� ��������, ����������� �� ������, � ��������� ����
    plain = new char* [2 * n]; // plain - ��� ������� �����������
    for (register unsigned int i = 0; i < 2 * n; i++)
        plain[i] = new char[2 * m];
    // �������� ��� ������� ����������� ��������� �� ���������
    for (register unsigned int i = 0; i < 2 * n; i++)
        for (register unsigned int j = 0; j < 2 * m; j++)
            plain[i][j] = ' ';
    // �������� �������� � ���� |
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
    coord.Y = (44 - 2 * n) / 2; // ������ ������ // 44
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (register unsigned int i = 0; i < 2 * n; i++)
    {
        unsigned int left_margin = (168 - 2 * m - 6) / 2; // ������ ����� // 168
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
    case'R': // �������� ������, y=const, x++
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
    case'L': // �������� �����, y=const, x--
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
    case'U': // �������� �����, y--, x=const
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
    case'D': // �������� ����, y++, x=const
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
    case'E': // ����� Enter
        plain[y + 1][x] = ' ';
        if (isFinish() == false)
            winRestart();
        else
            paint();
        break;
    case'S': // ������� Esc
        rules();
        break;
    case'T': // ���������
        tip();
        break;
    case'A': // �������� ��� ����������
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
    cout << "                                                                      *** ����� ������� ***\n";
    cout << "                                          ��� ������ �� ������� ����� ��������, ����������� �� ���������� ������.\n";
    cout << "                                          �� ���� ��� ����� ���� ����� ����� ���������� ��������� (������ ����) �� ����� �����.\n";
    cout << "                                          ��������� �������� ������ �������!\n";
    cout << "                                          ���������� �����, ������� ��������� ������� � ����.\n";
    cout << "                                          ����� ������� �������, ������� ������� �� ���� ������ �������� 'V'\n";
    cout << "                                          ��������� 'V' ������������� �� �������� ���� ��������� 'w', 's', 'a', 'd' ��� ���������.\n";
    cout << "                                          ������� ������ ��� Enter, � ��������� ������� �������� �� ����.\n";
    cout << "                                          � ����� ������ �� ����� ������ ���� �������:\n";
    cout << "                                                                                Esc - ��������� ���� �� �����.\n";
    cout << "                                                                                't' - �������� ���������� ���.\n";
    cout << "                                                                                'i' - �������� ��� ����������.\n";
    cout << "                                                                                'b' - ��������� ����.\n";
    cout << "                                          Esc - ��������� � ����.\n";
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