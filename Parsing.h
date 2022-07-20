#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int				CountLines(string fname)
{
	ifstream	file;
	int			_SizeOfDb = 0;
	string		c = "";
	file.open(fname);
	while (getline(file, c))
	{
		_SizeOfDb++;
	}
	return _SizeOfDb;
}

class Questions
{
	private:
		string Question;
		string Answers[4];
		string RightAnswer;
		int Quotient;
	public:
		void GetQuestion(Questions* Question, int Pos)
		{
			cout << Question[Pos].Question << "\n";
		}
		void GetAnswers(Questions* Question, int Pos)
		{
			for (int i = 0; i < 4; i++)
			{
				cout << Question[Pos].Answers[i] << "\n";
			}
		}
		string GetRightAnswer(Questions* Question, int Pos)
		{
			return Question[Pos].RightAnswer;
		}
		int GetQuotient(Questions* Question, int Pos)
		{
			return Question[Pos].Quotient;
		}
		void Debug(Questions* Question, int Pos)
		{
			cout << Question[Pos].Question << "\n";
			cout << Question[Pos].Quotient << "\n";
			for (int i = 0; i < 4; i++)
			{
				cout << Question[Pos].Answers[i] << "\n";
			}
		}
		int GetQuestion(string CategoryQuestionsFile,string CategoryAnswersFile, Questions *&Question)
		{
			
			ifstream	QuestionsFile;
			QuestionsFile.open(CategoryQuestionsFile);
			int Size = CountLines(CategoryQuestionsFile);

			int			LinePos = 0;
			string		LineQuestions = "";
			Question = new Questions[Size];
			ifstream	AnswersFile;
			AnswersFile.open(CategoryAnswersFile);
			string		LineAnswers = "";
			
			while ((getline(QuestionsFile, LineQuestions)) && (getline(AnswersFile, LineAnswers)))
			{
				stringstream QuestionsFile(LineQuestions);
				stringstream AnswersFile(LineAnswers);

				getline(QuestionsFile, Question[LinePos].Question, ';');
				string Buffer;
				getline(QuestionsFile, Buffer, ';');
				Question[LinePos].Quotient = stoi(Buffer);
				cout << Question[LinePos].Quotient;
				for(int i = 0; i < 4; i++)
				{
					getline(QuestionsFile, Question[LinePos].Answers[i], ';');
				}	
				getline(AnswersFile, Question[LinePos].RightAnswer, ';');
				/*Debug(Question, LinePos);*/
				LinePos++;
			}
			QuestionsFile.close();
			return Size;
		}

};


void Parse()
{
	
	


}