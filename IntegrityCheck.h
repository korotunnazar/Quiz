#pragma once
#include <fstream> // read files
#include <iostream> // i/o to terminal
using namespace std;
bool CheckFiles() // just checks if files exist
{
	// all files to check
	string AllFiles[] = { "Users.csv",".\\Questions\\music\\Music.txt" ,".\\Questions\\music\\MusicAnswers.txt", ".\\Questions\\films\\Films.txt", ".\\Questions\\films\\FilmsAnswers.txt",".\\Questions\\games\\Games.txt",".\\Questions\\games\\GamesAnswers.txt" };
	// file counter
	int FilePos = 0;
	// 
	while (true && FilePos < 7)
	{
		// input file stream 
		ofstream File;
		// opens file 
		File.open(AllFiles[FilePos], ios::in | ios::out | ios::app);
		
		if (!File) // if file not exists then file structure is damaged
		{
			File.close();
			return 0;
		}
		// close file
		File.close();
		// increment filenames
		FilePos++;
	}
	// if passed all
	return 1;
}