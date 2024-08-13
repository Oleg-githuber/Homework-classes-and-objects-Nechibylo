// Counter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <string>

class Counter
{
private:

    int count{ 1 };

public:

    //Counter() = default;

    Counter(int value = 1) : count{ value }
    {

    }

    void increaseCount()
    {
        ++count;
    }

    void decreaseCount()
    {
        --count;
    }

    int getCount()
    {
        return count;
    }
};

int enterStartCount();
void enterCommand(Counter* counter);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Counter counter(enterStartCount());
    enterCommand(&counter);

    system("pause");
    return EXIT_SUCCESS;
}

// Функция ввода начального значения счётчика, или значения счётчика по умолчанию = 1
int enterStartCount()
{
    int startCount{ 1 };

    while (true)
    {
        std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: " << std::flush;
        std::string word{};
        std::getline(std::cin, word);
        if (word == "да")
        {
            std::cout << std::flush << "Введите начальное значение счётчика: " << std::flush;
            std::cin >> startCount;
            break;
        }
        else if (word != "нет")
        {
            std::cout << std::flush << "Ответ должен быть да или нет!" << std::endl;
            continue;
        }
        else
        {
            break;
        }
    }

    return startCount;
}

// Функция управления счётчиком
void countController(Counter* counter, char command)
{
    switch (command)
    {
    case '+':
        counter->increaseCount();
        break;
    case '-':
        counter->decreaseCount();
        break;
    case '=':
        std::cout << counter->getCount() << std::endl;
        break;
    case 'x':
        std::cout << "До свидания!" << std::endl;
        break;
    default:
        std::cout << "Введена некорректная команда!" << std::endl;
    }
}

// Функция ввода команды ('+', '-', '=' или 'x')
void enterCommand(Counter* counter)
{
    char command{};
    while (command != 'x')
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;
        countController(counter, command);
    }
}