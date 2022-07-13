#include <vector>
#include "UserAuthorize.h"

void MenuAuthorize(string& Login)
{
	bool flag = true;
	int ChoiceUserAuthorize;
	while (flag) {

		cout << "�������� ��������: \n";
		cout << "1 - ����\n" << "2 - �����������\n";
		cin >> ChoiceUserAuthorize;

		switch (ChoiceUserAuthorize)
		{
		default:
			cout << "�������� �� ����������\n";
			break;
		case 1:
		{
			using namespace Login;
			Login = SignIn();
			if (Login == "Not Exists")
			{
				break;
			}
			cout << "���� �������� �� ���� " << Login << "\n";
			flag = 0;
		}
		case 2:
		{
			using namespace Register;
			SignUp();
			break;
		}
		}
	}
}

void main(void) {

	setlocale(LC_ALL, "rus");
	cout << "����� ���������� �� ��������� '� �������'!\n";
	string Login;
	MenuAuthorize(Login);
}