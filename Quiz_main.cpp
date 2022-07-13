#include <vector>
#include "UserAuthorize.h"

void MenuAuthorize(string& Login)
{
	bool flag = true;
	int ChoiceUserAuthorize;
	while (flag) {

		cout << "Enter choice: \n";
		cout << "1 - Login\n" << "2 - Register\n";
		cin >> ChoiceUserAuthorize;

		switch (ChoiceUserAuthorize)
		{
		default:
			cout << "Choice not exists\n";
			break;
		case 1:
		{
			using namespace Login;
			Login = SignIn();
			if (Login == "Not Exists")
			{
				break;
			}
			cout << "Login ass " << Login << "\n";
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
	cout << "Welc4m to the c4m zone\n";
	string Login;
	MenuAuthorize(Login);
}