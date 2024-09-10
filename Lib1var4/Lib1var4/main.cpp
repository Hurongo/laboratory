#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<Windows.h>
#include<iomanip>// ��� �++, ��� ���� ��� �����

const float PI = 3.14159;

bool C_syntax(long int& A,long int& T, float& V, float& W,bool& Error)
{
	printf("Please enter the distance in kilometers from the earth to the sun in the range from 100 000 000 (10^8) to 200 000 000 (2*10^8) :\n");
	printf("������ ���� ����� ������� � ��������� �� ���� �� ����� � ������� �� 100 000 000 (10^8) �� 200 000 000 (2*10^8) :\n");
	if (scanf_s("%d", &A) && A > 10e7 && A < 2*10e7)
	{
		printf(" Please enter the time of the earth's rotation around the sun in seconds :\n");
		printf(" ������ ���� ����� ��� ��������� ���� ������� ����� � �������� :\n");
		if (scanf_s("%d", &T))
		{
			//Linear speed formula
			V = float(2 * PI * A) / T;

			//Angular velocity formula
			W = float(2 * PI) / T;

			printf("\nLinear speed :\n");
			printf("˳���� �������� :\n");
			printf_s("%.4f = 2Pi * %d : %d \n", V, A, T);

			printf("\nAngular velocity :\n");
			printf("������ �������� :\n");
			printf_s("%.4f = 2Pi : %d \n", W, A, T);
			return Error = 1;
		}
	}
	else
	{
		printf("Error! You entered an incorrect sequence of characters or a number outside the specified range from 100,000,000 (10^8) to 200,000,000 (2*10^8) try again\n");
		printf("�������!�� ����� �� �������� ����������� ������� ��� ����� ��� �������� �� ��� ��������� �������� �� 100 000 000 (10^8) �� 200 000 000 (2*10^8) ��������� �� ���\n");
		return Error = 0;
	}
}
bool Cpp_syntax(long int& A,long int& T, float& V, float& W,bool& Error)
{
	std::cout << "Please enter the distance in kilometers from the earth to the sun in the range from 100 000 000 (10^8) to 200 000 000 (2*10^8) :\n";
	std::cout << "������ ���� ����� ������� � ��������� �� ���� �� ����� � ������� �� 100 000 000 (10^8) �� 200 000 000 (2*10^8) :\n";
	if (std::cin >> A && A > 10e7 && A < 2*10e7)
	{
		std::cout << "Please enter the time of the earth's rotation around the sun in seconds :" << std::endl;
		std::cout << "������ ���� ����� ��� ��������� ���� ������� ����� � �������� :" << std::endl;
		if (std::cin >> T)
		{
			//Linear speed formula
			V = float(2 * PI * A) / T;

			//Angular velocity formula
			W = float(2 * PI) / T;

			std::cout << "\nLinear speed :" << std::endl;
			std::cout << "˳���� �������� :" << std::endl;
			//floating point settings
			std::cout << std::fixed << std::showpoint;
			std::cout << std::setprecision(4);

			std::cout << V;
			std::cout <<  " = 2PI * " << A << " : " << T << std::endl;


			std::cout << "\nAngular velocity :" << std::endl;
			std::cout << "������ �������� :" << std::endl;
			std::cout << W <<  " = 2PI" << " : " << T << std::endl;
			return Error = 1;
		}
	}
	else
	{

		std::cout << "Error! You entered an incorrect sequence of characters "
			<< "or a number outside the specified range from 100,000,000 (10^8)  to 200, 000, 000 (2*10^8) try again " << std::endl;

		std::cout << "�������! �� ����� �� �������� ����������� ������� "
			<< "��� ����� ��� �������� �� ��� ��������� �������� �� 100 000 000 (10^8) �� 200 000 000 (2*10^8) ��������� �� ���" << std::endl;
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
		std::cout << "��� ����� ������ ������ � �� �++?\n���� � �� ������ 1 , ���� �++ �� ������ 2,���� ����� �� 3" << std::endl;
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