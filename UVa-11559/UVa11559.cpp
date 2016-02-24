#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define B_INF 9000000000

long long N, B, H, W;
long long price; // per person/week
long long beds; // beds/week

long long minPrice;

int main(int argc, char **argv)
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (scanf("%d%d%d%d\n", &N, &B, &H, &W) != EOF)
	{
		minPrice = B_INF; // reset
        
		for (int h = 0; h < H; h++)
		{
			cin >> price; // Price is same for all weekends
			for (int w = 0; w < W; w++)
			{
				cin >> beds;
				if (beds >= N) // at least hotel can accomodate all person
				{
					long long currentPrice = N * price; // calculate cost
					if (currentPrice < minPrice) // is minimum ?
					{
						minPrice = currentPrice; // update minimum cost
					}

					string strIgnore; getline(cin, strIgnore); break; // No need further processing for the same hotel as price is same for all weekends
				}
			}
		}

		if (minPrice != B_INF && minPrice <= B) // is in budget ?
		{
			cout << minPrice << endl;
		}
		else // Not in budget
		{
			cout << "stay home" << endl;
		}
	}

	return 0;
}