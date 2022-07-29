//this file was created just because this lines of code appeared in code to many times
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


int				CountLines(string fname) // to count all lines of questions
{
	ifstream	file; // read stream
	int			_SizeOfDb = 0; // counter of questions
	string		c = ""; // addition to count lines
	file.open(fname); // open file in read mode
	while (getline(file, c)) // count questions
	{
		_SizeOfDb++; // increment
	}
	return _SizeOfDb; // return how many questions
}