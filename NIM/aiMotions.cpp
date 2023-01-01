#include"NIM.h"
#include <Windows.h>
#include <bitset>
#include <string>
#include "prototypes.h"
//#include<Windows.h>
#include<time.h>
//#include<stdlib.h>
#include<random>
using std::bitset;
using std::string;

unsigned int random() // адекватный рандомайзер
{
    Sleep(5);
    unsigned int itime = clock() % 255 + 255;
    srand(itime);
    unsigned int rand_number = rand() % 255 + 255;
    return rand_number;
}
// для поиска номера выбранной кучки, т.к. номер кучки отличен от её индекса
unsigned int NIM::number_of_hip(unsigned int h)
{
    for (register unsigned int i = 1, k = 0; i < 2 * n && k < n; i += 2, k++)
        if (i == h)
            return i - k;
}

void NIM::AImove() // для хода компьютера
{
    Sleep(500);
    unsigned int* mas_of_hips_sums = new unsigned int[2 * n];
    // найдем размер всех кучек
    for (register unsigned int i = 1; i < 2 * n; i += 2)
    {
        unsigned int sum = 0;
        for (register unsigned int j = 1; j < 2 * m; j += 2)
            if (plain[i][j] == '|')
                sum++;
        mas_of_hips_sums[i] = sum; // кол-во предметов в i-той кучке
    }
    if (easy == false)
    {   // ---------- сложный ai вычислит ним-сумму и найдёт выигрышных ход ---------- //
        // переведём размеры кучек в Z/2 и найдём ним-сумму текущей позиции
        unsigned int nim = 0;
        for (register unsigned int i = 1; i < 2 * n; i += 2)
            nim = nim ^ mas_of_hips_sums[i];
        bitset<8> bitnim(nim);
        if (nim != 0)
        {
            // далее ищем старший разряд d=1
            string nimstr = bitnim.to_string<char, std::char_traits<char>, std::allocator<char> >();
            unsigned int d = 7 - nimstr.find('1');
            for (register unsigned int i = 1, k = 0; i < 2 * n && k < n; i += 2, k++)
            {
                bitset<8> bit_mas_of_hips_sums(mas_of_hips_sums[i]);
                string bit_mas_of_hips_sums_str = bit_mas_of_hips_sums.to_string<char, std::char_traits<char>, std::allocator<char> >();
                string rewers_bit_mas_of_hips_sums_str = string(bit_mas_of_hips_sums_str.crbegin(), bit_mas_of_hips_sums_str.crend());
                if (rewers_bit_mas_of_hips_sums_str[d] == '1')
                {
                    bitset<8> xk = bitnim ^ bit_mas_of_hips_sums;
                    unsigned int mount = mas_of_hips_sums[i] - xk.to_ulong();
                    for (register unsigned int j = 0; j < 2 * m; j++)
                    {
                        if (plain[i][j] == '|')
                        {
                            plain[i][j] = ' ';
                            mount--;
                        }
                        if (mount == 0)
                            break;
                    }
                    break;
                }
            }
        }
        else
        {
            unsigned int some_hip = randomHip(); // выбрали индекс кучки
            unsigned int mas_in_hip = mas_of_hips_sums[some_hip];
            unsigned int mount = random() % mas_of_hips_sums[some_hip] + 1; // выбрали кол-во забираемых предметов из кучки some_hip
            for (register unsigned int j = 0; j < 2 * m; j++)
            {
                if (plain[some_hip][j] == '|')
                {
                    plain[some_hip][j] = ' ';
                    mount--;
                }
                if (mount == 0)
                    break;
            }
        }
    }
    else
    {   // ---------- для простого уровня сложности ai случайно выберет кучку и кол-во забираемых предметов ---------- //
        unsigned int some_hip = randomHip(); // выбрали индекс кучки
        unsigned int mas_in_hip = mas_of_hips_sums[some_hip];
        unsigned int mount = random() % mas_of_hips_sums[some_hip] + 1; // выбрали кол-во забираемых предметов из кучки some_hip
        for (register unsigned int j = 0; j < 2 * m; j++)
        {
            if (plain[some_hip][j] == '|')
            {
                plain[some_hip][j] = ' ';
                mount--;
            }
            if (mount == 0)
                break;
        }
    }
    delete[] mas_of_hips_sums;
    if (isFinish() == 0)
        loseRestart();
    else
        paint();
}

//unsigned int NIM::randomHip() // для выбора кучки от имени ии
//{
//    unsigned int some_hip = random() % (2 * n) + 1; // выбрали строку от 1 до 2n
//    if (some_hip % 2 != 0)
//    {
//        unsigned int count = 0;
//        for (register unsigned int j = 1; j < 2 * m; j += 2)
//            if (plain[some_hip][j] == '|')
//                count++;
//        if (count > 0)
//            return some_hip; // вернули индекс нечётной и непустой строки
//        else
//            return randomHip();
//    }
//    else
//        return randomHip();
//}

bool NIM::isFinish()
{
    bool count = false;
    for (register unsigned int i = 0; i < 2 * n; i++)
        for (register unsigned int j = 0; j < 2 * m; j++)
            if (plain[i][j] == '|')
            {
                count = true;
                break;
            }
    return count;
}