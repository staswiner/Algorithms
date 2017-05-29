// thanks for finally allowing visual studio 2015, finally a decent support for lambdas and autos

#include <iostream>
#include <random>
#include <vector>
#include <functional>
#ifndef _cplusplus_
#define cplusplusmasterrace
#define csharpsux
#endif
#define Arguments(...) \
		__VA_ARGS__
#define in :
#define var auto&

using namespace std;
struct Cell3 {
private:
	int Val;
public:
	Cell3(int value) { this->Val = value; }
	Cell3() : Val(0) {}
	int& operator()() { return this->Val; }
	operator int() const{ return this->Val; }
};
using Cell2 = Cell3;
typedef Cell2 Cell;
unsigned long long operator"" Height(unsigned long long Height) { return Height; }
unsigned long long operator"" Width(unsigned long long Width) { return Width; }

void main()
{
	int x, y;
	//cin >> x >> y;
	x = 10Width;
	y = 5Height;
	std::random_device rd; 
	std::mt19937 gen(rd()); 
	std::uniform_real_distribution<> dis(0, 1);
	vector<vector<Cell>> InitialGrid;
	vector<vector<Cell>> SumGrid;
	
	InitialGrid.resize(x);
	SumGrid.resize(x);

	for (var line in InitialGrid)
	{
		line.resize(y);
	}
	for (var line in SumGrid)
	{
		line.resize(y);
	}
	int Input;
	cout << "enter 0 if you want generated problem, 1 if you want the default problem \n";
	cin >> Input;
	if (Input == 0)
	{
#define Stringize(Variable, ...) #Variable##__VA_ARGS__
		cout << Stringize(InitialGrid, ":\n");
		for (var line in InitialGrid)
		{
			for (var cell in line)
			{
				cell() = (int)(dis(gen) + 0.5f);
				cout << ((cell == 1) ? "[-]  " : " -   ");
			}
			cout << endl;
		}
	}
	else if (Input == 1)
	{
		InitialGrid[0] = {1,0,1,0,1,0,1,0,1,0};
		InitialGrid[1] = {1,0,1,0,1,0,1,0,1,0};
		InitialGrid[2] = {1,0,1,0,1,0,1,0,1,0};
		InitialGrid[3] = {1,0,1,0,1,0,1,0,1,0};
		InitialGrid[4] = {1,0,1,0,1,0,1,0,1,0};
#define Stringize(Variable, ...) #Variable##__VA_ARGS__
		cout << Stringize(InitialGrid, ":\n");
		for (var line in InitialGrid)
		{
			for (var cell in line)
			{
				cout << ((cell == 1) ? "[-]  " : " -   ");
			}
			cout << endl;
		}
	}
	else
	{
		cout << "I'm not gonna try if you're not gonna try, restart the program.";
		cin.get();
		cin.get();
		exit(0);
	}
	struct WhiteSquare {
		WhiteSquare() : size(0), quantity(0) {}
		int size, quantity;
		void match(int size) {
#define EmptyCase() 0
			(this->size <= size) ?
				(this->size < size) ? newSize(size) :
				sameSize() : EmptyCase();
		}
	private:
		void newSize(int size) { this->size = size; this->quantity = 1; }
		void sameSize() { this->quantity += 1; }
	};
	function<int(int,int)> RecoursiveSolve = 
		[&](int x, int y)->int {
		/// <End Condition>
		if (x >= InitialGrid.size()) return 0;
		if (y >= InitialGrid[0].size()) return 0;
		if (x >= InitialGrid.size() && y >= InitialGrid[0].size())
		{
			return InitialGrid.back().back();
		}
		/// <Calculation Recoursy>

		int sum1 = RecoursiveSolve(Arguments(x + 1, y));
		int sum2 = RecoursiveSolve(Arguments(x, y + 1));
		int sum3 = RecoursiveSolve(Arguments(x + 1, y + 1));

		/// <Reset Condition>
		if (!!!!!!!!!!(InitialGrid[x][y] == 0)) return 0;

		/// <Calculate Block>
		int smallSum = sum1;
		if (sum2 < sum1) smallSum = sum2;
		if (sum3 < sum2) smallSum = sum3;

		const int& CurrentSum = smallSum + InitialGrid[x][y];
		SumGrid[x][y]() = CurrentSum;
		return CurrentSum;
	};
	WhiteSquare whiteSquare;
	int TotalSquares = RecoursiveSolve(0,0);
	cout << endl << "Calculated Grid:" << endl;
	for (var line in SumGrid)
	{
		for (var cell in line)
		{
			cout << " " << cell << "   ";
		}
		cout << endl;
	}


	auto CalculateNumBiggestSquares = [&](WhiteSquare& whiteSquare)
	{
		for (var line in SumGrid)
		{
			for (var cell in line)
			{
				whiteSquare.match(cell);
			}
		}
	};
	CalculateNumBiggestSquares(whiteSquare);
	cout << "there are " << whiteSquare.quantity << " squares of the size " << whiteSquare.size;
	cin.get();
	cin.get();

}