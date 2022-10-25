#include "Gamble.h"

  Gamble::Gamble() :
	  m_randomSimpleNum (GetRandom())
{	 
}
  int Gamble::GetRandom() {
	  time_t t;
	  srand((unsigned)time(&t));
	  unsigned maxNum = 1000;
	  int generatedRandPrime = 0;
	  bool primeCheck = false;

	  for (size_t i = 0; !primeCheck; ++i) {
		  generatedRandPrime = (rand() % maxNum) + 1;
		  primeCheck = isSimple(generatedRandPrime);
	  }
	  return generatedRandPrime;
  }

 bool Gamble::MakePrediction(std::string userName, int prediction) {	
	 if (prediction >= 2 && prediction <= 1000) {
	  m_userRates.insert(std::make_pair(userName, prediction));
	  return true;
	 }
	 else {
		 return false;
	 }
  }

 void Gamble::FindWinner() {

	 int  closestNumber = 0;
	 unsigned int difference = -1;
	 std::string nameWinner = {};

	 std::map<std::string, int> ::iterator it = m_userRates.begin();
	 for (; it != m_userRates.end(); ++it) {
		 if (abs(it->second - m_randomSimpleNum) < difference)
		 {
			 difference = abs(it->second - m_randomSimpleNum);
			 nameWinner = it->first;
			 closestNumber = it->second;
		 }
	 }
	 ShowWinner(nameWinner, closestNumber);
 }

 bool Gamble::isSimple(int num) {
	 bool isNumPrime = true;
	 for (int i = 2; i < num / 2; ++i) {
		 if (num % i == 0) {
			 isNumPrime = false;
			 break;
		 }
	 }
	 return isNumPrime;
 };
 

 void Gamble::ShowWinner(std::string winName, int num) {
	 std::cout << std::endl;
	 std::cout << "Winner is: " << winName << " - " << num << std::endl;
	 std::cout << "Simple random number is: " << m_randomSimpleNum << std::endl;
 }
