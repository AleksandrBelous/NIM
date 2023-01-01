#include"prototypes.h"

class NIM
{
private:
    
public:
    unsigned int n = 0, m = 0, y = 0, x = 1;
    bool easy = true, dif = true;
    char** plain; //= new char* [2 * n]; // plain - это игровая поверхность

    NIM()
    {
        selectLevel(1);
    }
    
	void selectLevel(int); // => selectType()
	void selectType(int); // => create()
    void create(); // => paint()
    // ---------- контроль действий игрока и отрисовка игровой поверхности ---------- //
    unsigned int number_of_hip(unsigned int);
    void paint(); // => logic()
    void logic(); // => paint()
    void rules(); // для отображения краткой справочной информации
    // ---------- финал игры ---------- //
    bool isFinish(); // проверка конца игры
    void winRestart(); // для перезапуска игры после победы игрока
    void loseRestart(); // для перезапуска игры после поражения игрока
    void buy();
    // ---------- поиск выигрышной стратегии ---------- //
    void tip(); // подсказка по удалению предметов из игровой поверхности
    // ---------- для контроля ai ---------- //
    void AImove(); // для хода компьютера
    unsigned int randomHip() // для выбора кучки от имени ии
    {
        unsigned int some_hip = random() % (2 * n) + 1; // выбрали строку от 1 до 2n
        if (some_hip % 2 != 0)
        {
            unsigned int count = 0;
            for (register unsigned int j = 1; j < 2 * m; j += 2)
                if (plain[some_hip][j] == '|')
                    count++;
            if (count > 0)
                return some_hip; // вернули индекс нечётной и непустой строки
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