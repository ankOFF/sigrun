// Workshops.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

void vectorSymphony()
{
	//declaracja
	std::vector<int> vector1(5, 1); //5-elementowy wektor jedynek; 

	for (size_t i = 0; i < vector1.size(); ++i)
		vector1[i] = vector1[i] + i; //przypisanie wartości do i-tego elementu

	std::vector<int>::iterator it; //wskażnik na element w wektorze 

	it = vector1.begin(); // wskaźnik na pierwszy element w wektorze
	it = vector1.end(); //wskaźnik na miejsce za ostatnim elemencie w wektorze
	std::vector<int>::reverse_iterator itR = vector1.rbegin(); // wskaźnik na ostatni element w wektorze
	auto itR2 = vector1.rbegin();// tylko C++ 11 
	
	int XList[5] = { 1,1,1,1,1 };
	vector<vector<int>> vectorvector(2);
	vectorvector[0].insert(vectorvector[0].end(), XList, XList + 5); //
	vectorvector[1].insert(vectorvector[1].end(), { 1,1,1,1,1,1 }); // tylko C++11
	
	vectorvector.push_back(vector<int>(5, 0));//zaalokowanie pamięci + dodanie elementu na koncu wektora;
	
	for (std::vector<vector<int>>::iterator it = vectorvector.begin(); it != vectorvector.end(); ++it)
		it->resize(vector1.size()); //resize alokuje pamięć 

	auto itDeleted = vectorvector.erase(vectorvector.begin()); //erase usuwa element z wektora i zwraca wskaźnik na nasteony element; 

	for (int it : vector1) // tylko C++ 11
		cout << it << endl;
}
#include <ctime>
#include "inc/PolynomialRegression.h"
#include "inc/GBM.h"
#include "inc/Random.h"
#include "inc/AmericanOption.h"
#include "inc/LSM.h"

int main()
{
	//sprawdzenie regresji
	double XList[5] = { 1.08,1.07, 0.97,0.77,0.84 };
	std::vector<double> X;
	X.insert(X.end(), XList, XList + 5);

	double YList[5] = { 0.0,0.0659232,0.1695168,0.188352,0.0847584 };
	std::vector<double> Y;
	Y.insert(Y.end(), YList, YList + 5);

	PolynomialRegression polReg;
	std::vector<double> coefficients(2);
	polReg.fitIt(X, Y, 2, coefficients);

	//sprawdzenie generatora
	double S0 = 1.0;
	double r = 0.06;
	double sigma = 0.2;
	double T = 3.0;
	int N = 4;
	Gaussian *gaussian = new GaussianBoxMuller();
	gaussian->setSeed((int)time(NULL));
	GBM pathGenerator(S0, sigma, r, *gaussian);
	std::vector<double> samplePath = pathGenerator.generateStockPath(T, N);

	//American Option
	double K = 1.1;
	AmericanOption AM(K, T, r);
	vector<double> samplePayoff = AM.payOff(samplePath);

	//sprawdzenie LSM
	vector< vector<double>> prices(8);
	prices[0] = { 1.0,1.09,1.08,1.34 };
	prices[1] = { 1.0,1.16,1.26,1.54 };
	prices[2] = { 1.0,1.22,1.07,1.03 };
	prices[3] = { 1.0,0.93,0.97,0.92 };
	prices[4] = { 1.0,1.11,1.56,1.52 };
	prices[5] = { 1.0,0.76,0.77,0.90 };
	prices[6] = { 1.0,0.92,0.84,1.01 };
	prices[7] = { 1.0,0.88,1.22,1.34 };
	LSM mc(AM, prices);
	cout << "LSM price: " << mc.price() << endl;


    std::cout << "Hello World!\n"; 
}