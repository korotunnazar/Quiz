#include <vector>
#include "UserAuthorize.h"

void MenuAuthorize(string& Login)
{
	bool flag = true;
	int ChoiceUserAuthorize;
	while (flag) {

		cout << "Выберите действие: \n";
		cout << "1 - Вход\n" << "2 - Регистрация\n";
		cin >> ChoiceUserAuthorize;

		switch (ChoiceUserAuthorize)
		{
		default:
			cout << "Действие не существует\n";
			break;
		case 1:
		{
			using namespace Login;
			Login = SignIn();
			if (Login == "Not Exists")
			{
				break;
			}
			cout << "Вход выполнен от лица " << Login << "\n";
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
	cout << "Добро пожаловать на викторину 'У Богдана'!\n";
	string Login;
	MenuAuthorize(Login);
}