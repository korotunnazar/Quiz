#include <string>
#include "Parsing.h"
#include <iostream>
#include <vector>
using namespace std;





int GetQuestions(Questions	*&Question)
{
	int Category;
	cout << "Enter category\n1 - Music\n2 - Films\n3 - Games\n";
	cin >> Category;
	switch (Category)
	{
		case 1:
			return Question->GetQuestion(".\\Questions\\music\\Music.txt", ".\\Questions\\music\\MusicAnswers.txt", Question);
			break;
		case 2:
			return Question->GetQuestion(".\\Questions\\films\\Films.txt", ".\\Questions\\films\\FilmsAnswers.txt", Question);
			break;
		case 3:
			return Question->GetQuestion(".\\Questions\\games\\Games.txt", ".\\Questions\\games\\GamesAnswers.txt", Question);
			break;
	}
}


void StartGame()
{

	Questions* Question;
	int Range = GetQuestions(Question);
	int Score = 0;
	bool Flag = 1;
	int QuestionPos = 0;
	string Answer;
	while (QuestionPos < Range)
	{
		Question->GetQuestion(Question, QuestionPos);
		Question->GetAnswers(Question, QuestionPos);
		getline(cin, Answer); // bug : this line didn't called in code
		if (Answer != "" && Answer == Question->GetRightAnswer(Question, QuestionPos))
		{
			Score+= 1 * Question->GetQuotient(Question, QuestionPos);
		}
		QuestionPos++;
	}
	cout << Score;
}

