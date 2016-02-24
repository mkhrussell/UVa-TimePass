#include <iostream>

//#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T, nCase;
	cin >> T;
	for (nCase = 1; nCase <= T; nCase++)
	{
		int N;
		cin >> N;
		int max = 0;
		for (int i = 0; i < N; i++)
		{
			int current;
			cin >> current;

			if (current > max)
				max = current;
		}

		cout << "Case " << nCase << ": " << max << endl;
	}

	return 0;
}