#include "Includes.h"

class Questions
{
	private:
		string Question; 
		string Answers[4];
		string RightAnswer;
		int Quotient;
	public:
		// getter for question
		void GetQuestion(Questions* Question, int Pos) 
		{
		/*	stringstream linestream(Question[Pos].Question);
			string Question;
			linestream << Question;*/
			cout << Question[Pos].Question << "\n";
		}
		// getter for answers
		void GetAnswers(Questions* Question, int Pos)
		{
			for (int i = 0; i < 4; i++)
			{
				cout << Question[Pos].Answers[i] << "\n";
			}
		}
		// getter for right answer
		string GetRightAnswer(Questions* Question, int Pos)
		{
			return Question[Pos].RightAnswer;
		}
		// getter for quotient
		int GetQuotient(Questions* Question, int Pos)
		{
			return Question[Pos].Quotient;
		}
		// getter for all class fields
		void Debug(Questions* Question, int Pos)
		{
			cout << Question[Pos].Question << "\n";
			cout << Question[Pos].Quotient << "\n";
			for (int i = 0; i < 4; i++)
			{
				cout << Question[Pos].Answers[i] << "\n";
			}
		}
		// read file
		int GetQuestion(string CategoryQuestionsFile,string CategoryAnswersFile, Questions *&Question)
		{
			// file read stream
			ifstream	QuestionsFile;
			// open file in read mode
			QuestionsFile.open(CategoryQuestionsFile);
			// count how many questions
			int Size = CountLines(CategoryQuestionsFile);

			// question counter
			int			LinePos = 0;
			// to get question
			string		LineQuestions = "";
			// allocate class array
			Question = new Questions[Size];
			// file read stream
			ifstream	AnswersFile;
			// open file in read mode
			AnswersFile.open(CategoryAnswersFile);
			// to get answer
			string		LineAnswers = "";
			
			while ((getline(QuestionsFile, LineQuestions)) && (getline(AnswersFile, LineAnswers)))
			{
				stringstream QuestionsFile(LineQuestions);
				stringstream AnswersFile(LineAnswers);

				getline(QuestionsFile, Question[LinePos].Question, ';');
				string Buffer;
				getline(QuestionsFile, Buffer, ';');
				Question[LinePos].Quotient = stoi(Buffer);
				/*cout << Question[LinePos].Quotient;*/
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

