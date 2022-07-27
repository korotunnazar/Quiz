#include <vector>
#include "UserAuthorize.h"
#include "Game.h"
#include "IntegrityCheck.h"
void MenuAuthorize(string& Login, bool &Logged)
{
	bool Flag = true;
	int ChoiceUserAuthorize;
	while (Flag) {

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
					cout << "User not exist\n";
					break;
				}
				cout << "Login as " << Login << "\n";
				Logged = 1;
				Flag = 0;
				break;
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

void main(void) 
{
	if (CheckFiles())
	{
		cout << "Welc4m to the c4m zone\n";
		string Login;
		bool Logged;
		MenuAuthorize(Login, Logged);
		if (Logged)
		{
			StartGame();
		}
	}
}