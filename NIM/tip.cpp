#include"NIM.h"
//#include <stdlib.h>
#include <iostream>
#include <bitset>
#include<iomanip>
#include <string>
#include <conio.h>

using std::cout;
using std::bitset;
using std::string;

void NIM::tip() // ��������� �� �������� ��������� �� ������� �����������
{
    system("cls");
    unsigned int m2 = m;
    unsigned int mcount = 0;
    while (m2)
    {
        m2 /= 10;
        mcount++; // mcount ������ ����������, ������� ���� � ����� m
    }
    unsigned int n2 = n;
    unsigned int ncount = 0;
    while (n2)
    {
        n2 /= 10;
        ncount++; // ncount ������ ����������, ������� ���� � ����� n
    }
    unsigned int* set_of_hips_sums = new unsigned int[2 * n];
    // ������ ������ ���� �����
    for (register unsigned int i = 1; i < 2 * n; i += 2)
    {
        unsigned int sum = 0;
        for (register unsigned int j = 1; j < 2 * m; j += 2)
            if (plain[i][j] == '|')
                sum++;
        set_of_hips_sums[i] = sum; // ���-�� ��������� � i-��� �����
    }
    for (register unsigned int i = 0; i < (26 - n) / 2; i++)
        cout << "\n";
    for (register unsigned int i = 1, k = 0; i < 2 * n && k < n; i += 2, k++)
        cout << "                                                        � " << std::setw(ncount) << std::right << i - k << " ����� ���������: " << std::setw(mcount) << std::right << set_of_hips_sums[i] << "; � �������� ����: " << bitset<8>(set_of_hips_sums[i]) << "\n";
    // �������� ������� ����� � Z/2 � ����� ���-����� ������� �������
    unsigned int nim = 0;
    for (register unsigned int i = 1; i < 2 * n; i += 2)
        nim = nim ^ set_of_hips_sums[i];
    bitset<8> bitnim(nim);
    if (nim == 0)
    {
        cout << "\n                                                        ���-����� ������� ����� ����. ���������� ����� ���!";
    }
    else
    {
        cout << "\n                                                        ���-����� �������: " << nim << "; � �������� ����: " << bitnim << "\n";
        for (register int i = 0; i < 8; i++)
            cout << "\n                                                        [" << i << "] ��� ���-�����: " << bitnim[i];
        // ����� ���� ������� ������ d=1
        string nimstr = bitnim.to_string<char, std::char_traits<char>, std::allocator<char> >();
        cout << "\n";
        unsigned int d = 7 - nimstr.find('1');
        cout << "\n                                                        ������ �������� ���������� ���� ���-�����: " << d;
        for (register unsigned int i = 1, k = 0; i < 2 * n && k < n; i += 2, k++)
        {
            bitset<8> bit_mas_of_hips_sums(set_of_hips_sums[i]);
            string bit_mas_of_hips_sums_str = bit_mas_of_hips_sums.to_string<char, std::char_traits<char>, std::allocator<char> >();
            string rewers_bit_mas_of_hips_sums_str = string(bit_mas_of_hips_sums_str.crbegin(), bit_mas_of_hips_sums_str.crend());
            if (rewers_bit_mas_of_hips_sums_str[d] == '1')
            {
                cout << "\n                                                        ����� #" << i - k << " ����� �� [" << d << "] ������� ���, ������ 1";
                bitset<8> xk = bitnim ^ bit_mas_of_hips_sums;
                cout << "\n                                                        ����� ��������, � ���� ����� ������ �������� " << xk.to_ulong() << " ���������";
                cout << "\n                                                        ����� ��� ������ ������� ������ " << set_of_hips_sums[i] - xk.to_ulong() << " ��������� �� ���� #" << i - k;
                break;
            }
        }
    }
    cout << "\n\n                                                        Esc - ���������� ����";
    char answer = _getch();
    if (answer == 27)
    {
        system("cls");
        delete[] set_of_hips_sums;
        paint();
    }
    else
        tip();
}