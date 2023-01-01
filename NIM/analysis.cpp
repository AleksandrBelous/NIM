#include<conio.h>

char analysis()
{
    char choice = _getch();
    switch (choice)
    {
    case'd': // движение вправо
        return 'R';
        break;
    case -94: // движение вправо
        return 'R';
        break;
    case 77: // движение вправо
        return 'R';
        break;
    case'a': // движение влево
        return 'L';
        break;
    case -28: // движение влево
        return 'L';
        break;
    case 75: // движение влево
        return 'L';
        break;
    case'w': // движение вверх
        return 'U';
        break;
    case -26: // движение вверх
        return 'U';
        break;
    case 72: // движение вверх
        return 'U';
        break;
    case's': // движение вниз
        return 'D';
        break;
    case -21: // движение вниз
        return 'D';
        break;
    case 80: // движение вниз
        return 'D';
        break;
    case 13: // нажат Enter
        return 'E';
        break;
    case 32: // нажат пробел
        return 'E';
        break;
    case 27: // клавиша Esc
        return 'S';
        break;
    case't': // подсказка
        return 'T';
        break;
    case -91: // подсказка
        return 'T';
        break;
    case'i': // передать ход компьютеру
        return 'A';
        break;
    case -24: // передать ход компьютеру
        return 'A';
        break;
    case'b':
        return 'F';
        break;
    case -88:
        return 'F';
        break;
    default:
        return 'O';
    }
}