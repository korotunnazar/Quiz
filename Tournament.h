#include "Includes.h"



class Table
{
private:
	string Nickname;
	string Category;
	string Score;
public:
	
	int ReadTalbeFromFile(string Category, Table*& Tournament)
	{
		// file read stream
		ifstream	TournamentTable;
		// open file in read mode
		TournamentTable.open(Category);
		// count how many questions
		int Size = CountLines(Category);

		// question counter
		int			LinePos = 0;
		// to get question
		string		LineTournament = "";
		// allocate class array
		Tournament = new Table[Size];

		while (getline(TournamentTable, LineTournament))
		{
			stringstream TournamentFile(LineTournament);

			getline(TournamentFile, Tournament[LinePos].Nickname, ';');
			getline(TournamentFile, Tournament[LinePos].Category, ';');
			string Buffer;
			getline(TournamentFile, Buffer, ';');
			Tournament[LinePos].Score = stoi(Buffer);
			LinePos++;
		}
		TournamentTable.close();
		return Size;

	}

	void			PutInFile(string Login,string Category,int Score)
	{
		ofstream TournamentTalbe;
		TournamentTalbe.open(Category, ios::in | ios::out | ios::app);
		if(Category == ".\\TournamentTable\\Music.txt")
			TournamentTalbe << Login << ";" << "music" << Score << "\n";
		else if(Category == ".\\TournamentTable\\Films.txt")
			TournamentTalbe << Login << ";" << "films" << Score << "\n";
		else if (Category == ".\\TournamentTable\\VideoGames.txt")
			TournamentTalbe << Login << ";" << "games" << Score << "\n";

		TournamentTalbe.close();
	}


	void GetNickname(Table* Tournament, int Pos)
	{
		cout << Tournament[Pos].Nickname << "\n";
	}
	void GetCategory(Table* Tournament, int Pos)
	{
		cout << Tournament[Pos].Category << "\n";
	}
	string GetScore(Table* Tournament, int Pos)
	{
		return Tournament[Pos].Score;
	}
	void GetAll(Table* Tournament, int Size)
	{
		GetCategory(Tournament, 0);
		for (int i = 0; i < Size; i++)
		{
			GetNickname(Tournament, i);
			cout << GetScore(Tournament, i) << "\n";
		}
	}
	void BubbleSort(Table* Tournament, int Size)
	{
		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < Size - i - 1; j++)
			{
				if (Tournament[j].GetScore(Tournament, j) < Tournament[j+1].GetScore(Tournament, j + 1))
				{
					swap(Tournament[j], Tournament[j + 1]);
				}
				
			}
		}
	}

};