#include <iostream>
#include <random>
#include <vector>
#include <functional>

using namespace std;
void main()
{
	int x, y;
	//cin >> x >> y;
	x = 10; y = 5;
	std::random_device rd; 
	std::mt19937 gen(rd()); 
	std::uniform_real_distribution<> dis(0, 1);
	vector<vector<int>> Grid;
	Grid.resize(x);
	for (auto& line : Grid)
	{
		line.resize(y);
	}
	for (auto& line : Grid)
	{
		for (auto& col : line)
		{
			col = (int)(dis(gen)+0.5f);
			cout << col << "    ";
		}
		cout << endl;
	}
	struct WhiteSquare {
		WhiteSquare() : size(0), quantity(0) {}
		int size, quantity;
		void reset(int size) { this->size = size; this->quantity = 1; }
		void match() { this->quantity += 1; }
	};
	function<int(int,int, WhiteSquare& whiteSquare)> RecoursiveSolve = 
		[&](int x, int y, WhiteSquare& whiteSquare)->int {
		/// <End Condition>
		if (x >= Grid.size() && y >= Grid[0].size())
		{
			return Grid.back().back();
		}
	
		/// <Calculation Recoursy>
		int sum1 = 0;
		int sum2 = 0;
		int sum3 = 0;
		if (x < Grid.size() - 1 )
			sum1 = RecoursiveSolve(x + 1, y, whiteSquare);
		if (y < Grid[0].size() - 1 )
			sum2 = RecoursiveSolve(x, y + 1, whiteSquare);
		if (y < Grid[0].size() - 1 && x < Grid.size() - 1)
			sum3 = RecoursiveSolve(x + 1, y + 1, whiteSquare);

		/// <Reset Condition>
		if (Grid[x][y] == 0) return 0;

		/// <Calculate Block>
		int smallSum = sum1;
		if (sum2 < sum1) smallSum = sum2;
		if (sum3 < sum2) smallSum = sum3;
		if (smallSum == 1)
		{
			int a = 0;
		}
		const int& CurrentSum = smallSum + Grid[x][y];
#define EmptyCase()
		if (whiteSquare.size > CurrentSum) { EmptyCase(); }
		else if (whiteSquare.size == CurrentSum) { whiteSquare.match();}
		else { whiteSquare.reset(CurrentSum); }
		return CurrentSum;
	};
	WhiteSquare whiteSquare;
	int TotalSquares = RecoursiveSolve(0,0, whiteSquare);

	cout << "there are " << whiteSquare.quantity << " squares of the size " << whiteSquare.size;
	cin.get();
	cin.get();
}