#include"prototypes.h"

class NIM
{
private:
    
public:
    unsigned int n = 0, m = 0, y = 0, x = 1;
    bool easy = true, dif = true;
    char** plain; //= new char* [2 * n]; // plain - ��� ������� �����������

    NIM()
    {
        selectLevel(1);
    }
    
	void selectLevel(int); // => selectType()
	void selectType(int); // => create()
    void create(); // => paint()
    // ---------- �������� �������� ������ � ��������� ������� ����������� ---------- //
    unsigned int number_of_hip(unsigned int);
    void paint(); // => logic()
    void logic(); // => paint()
    void rules(); // ��� ����������� ������� ���������� ����������
    // ---------- ����� ���� ---------- //
    bool isFinish(); // �������� ����� ����
    void winRestart(); // ��� ����������� ���� ����� ������ ������
    void loseRestart(); // ��� ����������� ���� ����� ��������� ������
    void buy();
    // ---------- ����� ���������� ��������� ---------- //
    void tip(); // ��������� �� �������� ��������� �� ������� �����������
    // ---------- ��� �������� ai ---------- //
    void AImove(); // ��� ���� ����������
    unsigned int randomHip() // ��� ������ ����� �� ����� ��
    {
        unsigned int some_hip = random() % (2 * n) + 1; // ������� ������ �� 1 �� 2n
        if (some_hip % 2 != 0)
        {
            unsigned int count = 0;
            for (register unsigned int j = 1; j < 2 * m; j += 2)
                if (plain[some_hip][j] == '|')
                    count++;
            if (count > 0)
                return some_hip; // ������� ������ �������� � �������� ������
            else
                return randomHip();
        }
        else
            return randomHip();
    }

    ~NIM()
    {
        for (register unsigned int i = 0; i < 2 * n; i++)
            delete[] plain[i];
        delete[] plain;
        //Sleep(10000);
    }
};