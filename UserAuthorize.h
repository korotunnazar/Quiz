#include <iostream> // cin && cout								| input output
#include <string> // string										| storing text
#include <unordered_map> // hash<string>hasher;					| hashing Password
#include <fstream> //ifstream && ofstream && open() && close()  | file operations
#include <sstream> //stringstream								| used for file operations too

using namespace std;


//inprogram db
struct			LocDb
{
	string		Login;
	string		Password;
};

namespace ForFile
{
	//"CountLines()" Function called for getting size for structure LocDb returns(Size)
	int				CountLines(string fname)
	{
		ifstream	file;
		int			_SizeOfDb = 0;
		string		c = "";
		file.open("Users.csv");
		while (getline(file, c))
		{
			_SizeOfDb++;
		}
		return _SizeOfDb;
	}

	//"GetFromFile()" called for filling structure "LocDb"
	void			GetFromFile(LocDb*& DB, int& _SizeOfDb)
	{
		ifstream	database;
		database.open("Users.csv");
		_SizeOfDb = CountLines("Users.csv");
		//cout << "Size of Struct : " << _SizeOfDb << "\n"; // debug

		int			LinePos = 0;
		string		Line = "";
		DB = new LocDb[_SizeOfDb];
		while (getline(database, Line))
		{
			stringstream database(Line);


			getline(database, DB[LinePos].Login, ';');

			getline(database, DB[LinePos].Password, ';');

			/*cout << "Login : " << DB[LinePos].Login << "\nPassoword : " << DB[LinePos].Password << "\n";*/ //debug

			LinePos++;
		}
		database.close();

	}

	//"PutInFile()" called for saving user credentials into local file
	void			PutInFile(string Login, size_t Password)
	{
		ofstream database;
		database.open("Users.csv", ios::in | ios::out | ios::app);
		database << Login << ";" << Password << "\n";
		database.close();
	}

}


namespace Check
{
	//"LoginCheck()" called for checking if user used allowed symbols for his nickname returns(True | False)
	bool			LoginCheck(string Login)
	{
		string		AllowedSymbols = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789_-";
		int			LoginPos = 0;

		while (LoginPos < Login.length())
		{
			bool		ok = 0;
			int			SymbolPos = 0;

			while (SymbolPos < AllowedSymbols.length())
			{
				if (Login[LoginPos] == AllowedSymbols[SymbolPos++])
				{
					ok = 1;
					break;
				}
			}
			if (!ok)
			{
				return 0;
			}
			LoginPos++;
		}
		return 1;

	}

	//"LoginCheck()" called for checking if user used allowed symbols for his Password returns(True | False)
	bool			PasswordCheck(string Password)
	{
		string		AllowedSymbols = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789!@#$%^&*()_-+={}[]|/<>,.?";
		int			PasswordPos = 0;

		while (PasswordPos < Password.length())
		{
			bool		ok = 0;
			int			SymbolPos = 0;

			while (SymbolPos < AllowedSymbols.length())
			{
				if (Password[PasswordPos] == AllowedSymbols[SymbolPos++])
				{
					ok = 1;
					break;
				}
			}
			if (!ok)
			{
				return 0;
			}
			PasswordPos++;
		}
		return 1;
	}

	//"CheckIfExists()" called for checking if user trying to Login in existing account returns(True | False)
	bool			CheckIfExists(LocDb* DB, int _SizeOfDb, string Login)
	{
		for (int i = 0; i < _SizeOfDb; i++)
		{
			if (Login == DB[i].Login)
			{
				return 1;
			}
		}
		return 0;
	}
}


void Input(string& INP, string UI)
{
	
	cout << UI;
	/*cin.ignore();*/
	getline(cin, INP);
}

namespace Register
{
	//SignUp()" called for adding user to local database
	void			SignUp()
	{
		using namespace Check;
		cin.ignore();
		cout << "Register Account\n"; // just for clarification

		string		Login;
		Input(Login, "Input Login (A-Z, a-z, 0-9, _- ): ");

		LocDb* DB = nullptr;
		int			_SizeOfDb = 0;

		ForFile::GetFromFile(DB, _SizeOfDb);
		while (LoginCheck(Login) != 1 || CheckIfExists(DB, _SizeOfDb, Login) == 1)
		{
			cout << "\nUnallowed Symbol\tOr User Already exists\n";
			Input(Login, "Input Login (A-Z, a-z, 0-9, _- ): ");
		}

		cin.ignore();
		string		Password;
		Input(Password, "Input Password (A-Z, a-z, 0-9, all symbols) : ");

		while (PasswordCheck(Password) != 1)
		{
			cout << "Incorrect Symbol In Passoword\n";
			Input(Password, "Input Password (A-Z, a-z, 0-9, all symbols) : ");
		}

		hash<string>hasher;

		if (Login != "" && Password != "")
		{ 
			size_t		PasswordHash = hasher(Password);
			ForFile::PutInFile(Login, PasswordHash);
		}



		/*cout << "Password hash : " << PasswordHash;*/ //debug

	}
}


namespace Login
{
	//"HashCheck()" called for checking if user have inputed right Password for account returns(True | False)
	bool			HashCheck(string Login, string Password, LocDb* DB, int _SizeOfDb)
	{
		for (int i = 0; i < _SizeOfDb; i++)
		{
			if (DB[i].Login == Login)
			{
				hash<string>hasher;
				size_t			hash1 = hasher(Password);
				size_t			hash2;
				stringstream	hash(DB[i].Password);

				hash >> hash2;

				/*cout << "1 : " << hash1 << "\n2 : " << hash2 << "\n";*/ //debug
				if (hash1 == hash2)
				{
					return 1;
				}
			}
		}
		return 0;
	}


	//"SignIn()" called for logging in users account returns(True | False)
	string			SignIn()
	{
		using namespace Check;
		cin.ignore();
		cout << "Sign Into Account\n";  // just for clarification

		string		Login;
		Input(Login, "Input Login (A-Z, a-z, 0-9, _- ): ");

		while (LoginCheck(Login) != 1)
		{
			cout << "\nIncorrect Symbol In Login (A-Z, a-z, 0-9, _-) : ";
			Input(Login, "Input Login (A-Z, a-z, 0-9, _- ): ");
		}

		LocDb* DB = nullptr;
		int			_SizeOfDb = 0;
	
		ForFile::GetFromFile(DB, _SizeOfDb);
		cin.ignore();
		if (CheckIfExists(DB, _SizeOfDb, Login))
		{
			string Password;
			Input(Password, "Input Password (A-Z, a-z, 0-9, all symbols) : ");
			while (PasswordCheck(Password) != 1)
			{
				cout << "Incorrect Symbol In Passoword : ";
				Input(Password, "Input Password (A-Z, a-z, 0-9, all symbols) : ");
			}

			hash<string>hasher;
			size_t		PasswordHash = hasher(Password);
			if (HashCheck(Login, Password, DB, _SizeOfDb))
			{
				return Login;
			}
		}


		return "Not Exists";
	}
}
