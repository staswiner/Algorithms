#include <iostream>
#include <random>
#include <vector>
#include <functional>

using namespace std;
using Cost = int;
void PrintSpaced(int Number,int Area)
{
	int Digits = (int)log10(Number) + 1;
	string Spaces = " ";
	for (int s = 0; s < Area - Digits; s++)
		Spaces += " ";
	cout << Number << (Spaces.c_str());
}
void main()
{
	int numHouses = 10;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(1, 100);
	vector<Cost> Houses[3];
	vector<Cost> ProcessedHouses[3];
	/*for (int i = 0; i < 3; i++)
	{
		Houses[i].resize(numHouses);
		ProcessedHouses[i].resize(numHouses);
		for (auto& val : Houses[i])
		{
			val = (int)dis(gen);
			PrintSpaced(val, 4);
		}
		cout << endl;
	}*/
	Houses[0] = {1,1  ,1};
	Houses[1] = {2,100,2};
	Houses[2] = {3,100,3};
	auto FindMin = [](vector<int> args) -> auto {
		int minCost = args[0];
		int optimalIndex = 0;
		for(int i = 1; i < args.size(); i++)
		{
			if (minCost > args[i])
			{
				minCost = args[i];
				optimalIndex = i;
			}
		}
		return make_pair(minCost, optimalIndex);
	};
	struct Coloring
	{
		vector<int> House;
		vector<int> Cost;
		int Total;
	};
	function<Coloring(int,int)> Choose = [&](int i,int Restriction) -> Coloring {
		if (i > Houses[0].size() - 1)
		{
			Coloring coloring = {};
			return coloring;
		}
		int iYellow, iBlue, iGreen;
		vector<int> Array;
		Coloring coloring;
		if (Restriction != 0)
		{
			coloring = Choose(i + 1, 0);
			iYellow = coloring.Total + Houses[0][i];
		}
		if (Restriction != 1)
		{
			coloring = Choose(i + 1, 1);
			iBlue = coloring.Total + Houses[1][i];
		}
		if (Restriction != 2)
		{
			coloring = Choose(i + 1, 2);
			iGreen = coloring.Total + Houses[2][i];
		}

		if (Restriction == 0)
			Array = { iBlue, iGreen };
		if (Restriction == 1) 
			Array = { iYellow, iGreen };
		if (Restriction == 2) 
			Array = { iYellow, iBlue };
		if (Restriction == 4)
			Array = { iYellow , iBlue, iGreen};
		pair<int,int> Min = FindMin(Array);
		PrintSpaced(Min.first, 4);
		coloring.House.push_back( Min.second );
		coloring.Cost.push_back(Houses[Min.second][i] );
		coloring.Total = Array[Min.second];
		return coloring;
	};
	Coloring returnValue = Choose(0,4);
	int total = 0;
	for (auto c : returnValue.Cost)
	{
		total += c;
	}
	cout << endl << "Optimal Cost : " << returnValue.Total << endl;
	cin.get();
	cin.get();

}