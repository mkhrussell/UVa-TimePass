#include <iostream>

// #include <cstdio>

using namespace std;

int nCase;

int N, B, H, W;
int price; // per person/week
int a; // beds/week

int minPrice;

int main(int argc, char **argv)
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof())
	{
		minPrice = 0; // reset

		cin >> N >> B >> H >> W;
		for (int h = 0; h < H; h++)
		{
			cin >> price;
			for (int w = 0; w < W; w++)
			{
				cin >> a;
				if (a >= N) // at least hotel can accomodate all person
				{
					int currentPrice = N * price; // calculate cost
					if (minPrice) // already have at least one minimum cost
					{
						if (currentPrice < minPrice) // is minimum ?
						{
							minPrice = currentPrice; // update minimum cost
						}
					}
					else // first time setting minimum
					{
						minPrice = currentPrice;
					}
				}
			}
		}
		
		if (minPrice) // Hotel can accomodate all person
		{
			if (minPrice <= B) // is in budget ?
			{
				cout << minPrice << endl;
			}
			else // Not in budget
			{
				cout << "stay home" << endl;
			}
		}
		else // Hotel cannot accomodate all person
		{
			cout << "stay home" << endl;
		}
	}

	return 0;
}