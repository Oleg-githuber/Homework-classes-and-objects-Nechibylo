#include <iostream>
#include <clocale>

class Calculator
{
private:
	double num1{};
	double num2{};

	

public:
	Calculator() = default;

	double add()
	{
		return num1 + num2;
	}

	double multiply()
	{
		return num1 * num2;
	}

	double substract_1_2()
	{
		return num1 - num2;
	}

	double substract_2_1()
	{
		return num2 - num1;
	}

	double divide_1_2()
	{
		return num1 / num2;
	}

	double divide_2_1()
	{
		return num2 / num1;
	}

	bool set_num1(double num1)
	{
		if (num1 == 0)
		{
			return false;
		}
		this->num1 = num1;
		return true;
	}

	bool set_num2(double num2)
	{
		if (num2 == 0)
		{
			return false;
		}
		this->num2 = num2;
		return true;
	}
};


void calculation();


int main()
{
	setlocale(LC_ALL, "Russian");

	int num1{}, num2{};
	Calculator calculator;

	while (true)
	{
		std::cout << "Введите num1: " << std::flush;
		std::cin >> num1;
		if (!calculator.set_num1(num1))
		{
			std::cout << "Неверный ввод!" << std::endl;
			continue;
		}
		break;
	}

	while (true)
	{
		std::cout << "Введите num2: " << std::flush;
		std::cin >> num2;
		if (!calculator.set_num2(num2))
		{
			std::cout << "Неверный ввод!" << std::endl;
			continue;
		}
		break;
	}

	std::cout.precision(2);
	std::cout << "num1 + num2 = " << calculator.add() << std::endl <<
		"num1 - num2 = " << calculator.substract_1_2() << std::endl <<
		"num2 - num1 = " << calculator.substract_2_1() << std::endl <<
		"num1 / num2 = " << std::fixed << calculator.divide_1_2() << std::endl <<
		"num2 / num1 = " << std::fixed << calculator.divide_2_1() << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}
