#include <iostream>
#include <random>
#include <vector>
#include <functional>

using namespace std;

void main()
{
	int numHouses;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 1);
}