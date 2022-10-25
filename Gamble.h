#pragma once
#include <map>
#include <iostream>

class Gamble {
public:
	Gamble();
	bool MakePrediction(std::string userName, int prediction);
	void FindWinner();
	int GetRandom();
private:
	bool isSimple(int num);
	void ShowWinner(std::string winName, int num);
private:
	std::map<std::string, int> m_userRates;
	int m_randomSimpleNum = 0;
};