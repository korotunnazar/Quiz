#pragma once
#include <fstream>
#include <iostream>
using namespace std;
bool CheckFiles()
{
	string AllFiles[] = { "Users.csv",".\\Questions\\music\\Music.txt" ,".\\Questions\\music\\MusicAnswers.txt", ".\\Questions\\films\\Films.txt", ".\\Questions\\films\\FilmsAnswers.txt",".\\Questions\\games\\Games.txt",".\\Questions\\games\\GamesAnswers.txt" };
	int FilePos = 0;
	while (true && FilePos < 7)
	{
		ofstream File;
		File.open(AllFiles[FilePos], ios::in | ios::out | ios::app);
		if (!File)
		{
			File.close();
			return 0;
		}
		File.close();
		FilePos++;
	}
	return 1;
}