#include <iostream>
#include <windows.h>
#include "Gamble.h"

	Gamble g_prediction;
DWORD __stdcall ThreadMain(LPVOID arg) {
 
	while (true) {
		std::cout << "Enter your name and random number: [2-1000]" << std::endl;
		int userNum = 0;
		std::string userName;
		std::cin >> userName >> userNum;
		bool isRegNum = g_prediction.MakePrediction(userName, userNum);
		if (!isRegNum) {
			std::cout << "Wrong number, try again" << std::endl;
		}
	}
 	return 0;
}
 
 
int main()
{
 
	 
	HANDLE threadHandle = CreateThread(
		0,
		0,
		ThreadMain,
		0,
		0,
		0
	);
	// 2 min in miliseconds
	int timeToEnterPred = 120000;
	WaitForSingleObject(threadHandle, timeToEnterPred);
	g_prediction.FindWinner();
	BOOL succses =  TerminateThread(threadHandle, -1);
	system("pause");
}
	 

 
 