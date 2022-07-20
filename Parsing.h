#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "winsock.h"
#include <fstream>

using namespace std;

struct Questions
{
	string Question;
	vector<string>Answers;
	string RightAnswer;
	double quotient;
};

int sock;
struct sockaddr_in client;
int PORT = 80;


void Parse()
{
	
	


}