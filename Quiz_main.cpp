#include <iostream>
#include <vector>
#include <string>
#include "UserAuthorize.cpp"
#include "parsing.cpp"

void main(void) {

	setlocale(LC_ALL, "rus");

	int choice_menu, choice_signin, choice_registration;
	std::vector <std::string> login;
	std::string answer;
	bool flag = true;

	int index;

	std::cout << "����� ���������� �� ��������� '� �������'!" << std::endl;

	while (flag) {

		std::cout << "�������� ��������: \n" << std::endl;
		std::cout << "1 - ����\n" << "2 - �����������\n" << std::endl;
		std::cin >> choice_menu;

		switch (choice_menu)
		{
		case 1:

			Registration();

			std::cout << "������� ����� ������" << std::endl;
			std::cout << "������� �������� �� �������" << std::endl;
			std::cout << "������� ����������� ��������� ������" << std::endl;
			std::cout << "������� ��������� �� ���� � ���������" << std::endl;

			std::cout << "����(���������) { " << std::endl;


			std::cout << " ����� �� �����: ������� ��������������!" << std::endl;

			std::cout << "������ ���������? " << std::endl;
			std::cin >> answer;


			std::cout << "����(����� == ��) { " << std::endl;

			std::cout << "������� ����" << std::endl;

			std::cout << " } " << std::endl;


			std::cout << "���� ��(����� == ���) { " << std::endl;

			std::cout << "����������� � �������� ����" << std::endl;

			std::cout << " } " << std::endl;


			std::cout << " } " << std::endl;

			break;

		case 2:

			std::cout << "������ ������� �� +1" << std::endl;

			std::cout << "������� ����� ������" << std::endl;
			std::cout << "������� �������� ������" << std::endl;
			std::cout << "������� ����������� ��������� ������" << std::endl;
			std::cout << "������� ������ ��������� ������ � ������ � ����" << std::endl;

			break;

		default:
			flag = false;
			break;
		}

	}

}
