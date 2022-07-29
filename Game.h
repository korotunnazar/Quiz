#include "Parsing.h"
//future
//#include "Tournament.h"
#include <tuple>

tuple<int, string> GetQuestions(Questions	*&Question)
{
	int Category;
	cout << "Enter category\n1 - Music\n2 - Films\n3 - Games\n";
	cin >> Category;
	switch (Category)
	{
		case 1:
			return { Question->GetQuestion(".\\Questions\\music\\Music.txt", ".\\Questions\\music\\MusicAnswers.txt", Question) , ".\\TournamentTable\\Music.txt"};
			break;
		case 2:
			return {Question->GetQuestion(".\\Questions\\films\\Films.txt", ".\\Questions\\films\\FilmsAnswers.txt", Question), ".\\TournamentTable\\Films.txt"};
			break;
		case 3:
			return { Question->GetQuestion(".\\Questions\\games\\Games.txt", ".\\Questions\\games\\GamesAnswers.txt", Question), ".\\TournamentTable\\VideoGames.txt"};
			break;
	}
}


void StartGame()
{
	

	Questions* Question;
	tuple<int, string> Parameters = GetQuestions(Question);
	int Range  = get<0>(Parameters);
	string Category = get<1>(Parameters);

	// future
	// 
	//Table* Tournament;
	//Tournament->ReadTalbeFromFile(Category, Tournament);
	//int SIZE = CountLines(Category);
	/*Tournament->BubbleSort(Tournament, SIZE);*/

	int Score = 0;
	bool Flag = 1;
	int QuestionPos = 0;
	string Answer;
	int RightAnswers = 0;
	while (QuestionPos < Range)
	{

		cin.ignore();
		Question->GetQuestion(Question, QuestionPos);
		Question->GetAnswers(Question, QuestionPos);
		
		getline(cin, Answer); // bug : this line didn't called in code
		if (Answer != "" && Answer == Question->GetRightAnswer(Question, QuestionPos))
		{
			Score+= 1 * Question->GetQuotient(Question, QuestionPos);
			RightAnswers++;
		}
		QuestionPos++;
		Answer = "";
	}
	cout << "You answered " << RightAnswers << " questions right\nYour score is " << Score << "\n";
	// future 
	// 
	//if (RightAnswers > 0)
	//{

	//	//Table* Tournament;
	//	//Tournament->ReadTalbeFromFile(Category, Tournament);
	//	//int SIZE = CountLines(Category);
	//	//Tournament->GetAll(Tournament, SIZE);

	//	//Tournament->BubbleSort(Tournament, SIZE);
	//	//for (int i = 0; i < SIZE; i++)
	//	//{
	//	//	Tournament->PutInFile(Tournament->GetNickname(Tournament, i), Tournament->GetCategory(Tournament, i))
	//	//}
	//}
}

