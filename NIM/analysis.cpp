#include<conio.h>

char analysis()
{
    char choice = _getch();
    switch (choice)
    {
    case'd': // �������� ������
        return 'R';
        break;
    case -94: // �������� ������
        return 'R';
        break;
    case 77: // �������� ������
        return 'R';
        break;
    case'a': // �������� �����
        return 'L';
        break;
    case -28: // �������� �����
        return 'L';
        break;
    case 75: // �������� �����
        return 'L';
        break;
    case'w': // �������� �����
        return 'U';
        break;
    case -26: // �������� �����
        return 'U';
        break;
    case 72: // �������� �����
        return 'U';
        break;
    case's': // �������� ����
        return 'D';
        break;
    case -21: // �������� ����
        return 'D';
        break;
    case 80: // �������� ����
        return 'D';
        break;
    case 13: // ����� Enter
        return 'E';
        break;
    case 32: // ����� ������
        return 'E';
        break;
    case 27: // ������� Esc
        return 'S';
        break;
    case't': // ���������
        return 'T';
        break;
    case -91: // ���������
        return 'T';
        break;
    case'i': // �������� ��� ����������
        return 'A';
        break;
    case -24: // �������� ��� ����������
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