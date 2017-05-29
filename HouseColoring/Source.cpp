#include <iostream>
#include <random>
#include <vector>
#include <functional>
#include <set>
using namespace std;
using Cost = int;
using Color = int;
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
	Houses[0] = {1,1  ,1,1};
	Houses[1] = {2,100,2,100};
	Houses[2] = {3,100,3,8};
	for (int i = 0; i < 3; i++)
	{
		for (auto& val : Houses[i])
		{
			PrintSpaced(val, 4);
		}
		cout << endl;
	}
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
		vector<int> Color;
		int Total;
	};
	enum eColors {
		Yellow, 
		Blue, 
		Green
	};
	function<Coloring(int,int)> Choose = [&](int i,int Restriction) -> Coloring {
		if (i > Houses[0].size() - 1)
		{
			Coloring coloring = {};
			return coloring;
		}
		int iYellow, iBlue, iGreen;
		vector<int> Array;
		vector<Coloring> coloring;
		set<Color> ColorsAvailable = { Yellow,Blue,Green };
		if (ColorsAvailable.find(Restriction) != ColorsAvailable.end())
			ColorsAvailable.erase(ColorsAvailable.find(Restriction));
		
		for(auto c : ColorsAvailable)
		{
			coloring.push_back(Choose(i + 1, c));
			coloring.back().Total += Houses[c][i];
			coloring.back().Cost.push_back(Houses[c][i]);
			coloring.back().House.push_back(i);
			coloring.back().Color.push_back(c);
			Array.push_back(coloring.back().Total);
		}

		pair<int,int> Min = FindMin(Array);
		return coloring[Min.second];
	};
	Coloring returnValue = Choose(0,4);
	int total = 0;
	cout << endl;
	for (int i = 0; i < returnValue.House.size(); i++)
	{
		cout << "House number " << returnValue.House[i] << " With color " << returnValue.Color[i] <<
			" With Cost of " << returnValue.Cost[i] << endl;
	}
	cout << endl << "Optimal Cost : " << returnValue.Total << endl;
	cin.get();
	cin.get();

}