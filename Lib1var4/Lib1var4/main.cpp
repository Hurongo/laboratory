#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<Windows.h>
#include<iomanip>// ƒл€ с++, л≥м≥т нул≥в дл€ флоат

const float PI = 3.14159;

bool C_syntax(long int& A,long int& T, float& V, float& W,bool& Error)
{
	printf("Please enter the distance in kilometers from the earth to the sun in the range from 100 000 000 (10^8) to 200 000 000 (2*10^8) :\n");
	printf("¬вед≥ть будь ласка в≥дстань в к≥лометрах в≥д земл≥ до сонц€ в д≥апазон≥ в≥д 100 000 000 (10^8) до 200 000 000 (2*10^8) :\n");
	if (scanf_s("%d", &A) && A > 10e7 && A < 2*10e7)
	{
		printf(" Please enter the time of the earth's rotation around the sun in seconds :\n");
		printf(" ¬вед≥ть будь ласка час обертанн€ земл≥ навколо сонц€ в секундах :\n");
		if (scanf_s("%d", &T))
		{
			//Linear speed formula
			V = float(2 * PI * A) / T;

			//Angular velocity formula
			W = float(2 * PI) / T;

			printf("\nLinear speed :\n");
			printf("Ћ≥н≥йна швидк≥сть :\n");
			printf_s("%.4f = 2Pi * %d : %d \n", V, A, T);

			printf("\nAngular velocity :\n");
			printf(" утова швидк≥сть :\n");
			printf_s("%.4f = 2Pi : %d \n", W, A, T);
			return Error = 1;
		}
	}
	else
	{
		printf("Error! You entered an incorrect sequence of characters or a number outside the specified range from 100,000,000 (10^8) to 200,000,000 (2*10^8) try again\n");
		printf("ѕомилка!¬и ввели не коректну посл≥довн≥сть символ≥в або число €ке виходить за меж≥ вказаного д≥апазону в≥д 100 000 000 (10^8) до 200 000 000 (2*10^8) спробуйте ще раз\n");
		return Error = 0;
	}
}
bool Cpp_syntax(long int& A,long int& T, float& V, float& W,bool& Error)
{
	std::cout << "Please enter the distance in kilometers from the earth to the sun in the range from 100 000 000 (10^8) to 200 000 000 (2*10^8) :\n";
	std::cout << "¬вед≥ть будь ласка в≥дстань в к≥лометрах в≥д земл≥ до сонц€ в д≥апазон≥ в≥д 100 000 000 (10^8) до 200 000 000 (2*10^8) :\n";
	if (std::cin >> A && A > 10e7 && A < 2*10e7)
	{
		std::cout << "Please enter the time of the earth's rotation around the sun in seconds :" << std::endl;
		std::cout << "¬вед≥ть будь ласка час обертанн€ земл≥ навколо сонц€ в секундах :" << std::endl;
		if (std::cin >> T)
		{
			//Linear speed formula
			V = float(2 * PI * A) / T;

			//Angular velocity formula
			W = float(2 * PI) / T;

			std::cout << "\nLinear speed :" << std::endl;
			std::cout << "Ћ≥н≥йна швидк≥сть :" << std::endl;
			//floating point settings
			std::cout << std::fixed << std::showpoint;
			std::cout << std::setprecision(4);

			std::cout << V;
			std::cout <<  " = 2PI * " << A << " : " << T << std::endl;


			std::cout << "\nAngular velocity :" << std::endl;
			std::cout << " утова швидк≥сть :" << std::endl;
			std::cout << W <<  " = 2PI" << " : " << T << std::endl;
			return Error = 1;
		}
	}
	else
	{

		std::cout << "Error! You entered an incorrect sequence of characters "
			<< "or a number outside the specified range from 100,000,000 (10^8)  to 200, 000, 000 (2*10^8) try again " << std::endl;

		std::cout << "ѕомилка! ¬и ввели не коректну посл≥довн≥сть символ≥в "
			<< "або число €ке виходить за меж≥ вказаного д≥апазону в≥д 100 000 000 (10^8) до 200 000 000 (2*10^8) спробуйте ще раз" << std::endl;
		return Error = 0;
	}
	
}



int main()
{
	//localization
	setlocale(LC_ALL, "Ukrainian");
	std::system("chcp 1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	long int A, T;
	float V, W;

	bool Error = 1;
	for (int i = 0; i < 1; )
	{
		int choose;
		std::cout << "Which version do you want to choose c or c++?\nIf c then enter 1, if c++ then enter 2, if you leave, then 3" << std::endl;
		std::cout << "яку верс≥ю бажаЇте обрати с чи с++?\nякщо с то введ≥ть 1 , €кщо с++ то введ≥ть 2,€кщо вийти то 3" << std::endl;
		std::cin >> choose;
		if (choose == 1)
		{
			C_syntax(A, T, V, W, Error);
		}
		else if (choose == 2)
		{
			Cpp_syntax(A, T, V, W, Error);
		}
		else if (choose == 3)
		{
			++i;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}