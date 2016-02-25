/*
UVa 10141 - Request for Proposal
https://uva.onlinejudge.org/external/101/10141.pdf
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int N, P;
	double bestPricing = 1000000000000.0;
	double bestCompliance = 0.0;
	string bestProposer = "";
	
	int nCase = 0;
	while ((cin >> N >> P) && (N > 0 && P > 0))
	{
		cin.ignore(100, '\n'); // Ignore rest of the cahrs of the line

		// Reset case specific vars
		nCase++;
		bestPricing = 1000000000000.0;
		bestCompliance = 0.0;
		bestProposer = "";		

		for (int n = 0; n < N; n++)
		{
			cin.ignore(100, '\n'); // Ignore rest of the cahrs of the line
		}

		for (int p = 0; p < P; p++)
		{
			string strProposer;
			getline(cin, strProposer); // Proposer name

			double thisPricing; int R;
			cin >> thisPricing >> R;
			cin.ignore(100, '\n'); // Ignore rest of the cahrs of the line

			double thisCompliance = (double) ((double)R / (double)N);
			if (thisCompliance >= bestCompliance)
			{
				if (thisCompliance == bestCompliance)
				{
					if (thisPricing < bestPricing)
					{
						bestCompliance = thisCompliance;
						bestPricing = thisPricing;
						bestProposer = strProposer;
					}
				}
				else
				{
					bestCompliance = thisCompliance;
					bestPricing = thisPricing;
					bestProposer = strProposer;
				}
			}

			for (int r = 0; r < R; r++)
			{
				cin.ignore(100, '\n'); // Ignore rest of the cahrs of the line
			}
		}

		if (nCase > 1) cout << endl; // Extra line before each result except for 1st result
		cout << "RFP #" << nCase << endl;
		cout << bestProposer << endl;
	}

	return 0;
}