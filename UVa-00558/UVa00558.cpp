/**
http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=499
http://uva.onlinejudge.org/external/5/558.pdf
https://www.udebug.com/UVa/558
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int INFT = 999999999;
int T;

class Universe {

public:
	Universe(int nStartSys, int mWormWhole) : N(nStartSys), E(mWormWhole), s(0)
	{
		dist.assign(nStartSys, INFT);
	}

	void addEdge(int u, int v, int w)
	{
		edgeList.push_back(Edge{ u, v, w });
	}

	void printEdges()
	{
		for (auto&& edge : edgeList)
		{
			cout << edge.U << " " << edge.V << " " << edge.W << endl;
		}		
	}

	void printPosibility()
	{
		if (runBellmanFord())
			cout << "possible" << endl;
		else
			cout << "not possible" << endl;
	}

private:
	class Edge {
		int U;
		int V;
		int W;		
		friend class Universe;
	public:
		Edge(int u, int v, int w) : U(u), V(v), W(w) { /* blank */ }
	};

	int N, E, s;
	vector<Edge> edgeList;
	vector<int> dist;

	bool runBellmanFord(/*int s*/)
	{
		for (int i = 0; i < N - 1; i++)
		{
			for (auto&& edge : edgeList)
			{
				//Relax
				if (dist[edge.V] > dist[edge.U] + edge.W)
				{
					dist[edge.V] = dist[edge.U] + edge.W;
				}
			}
		}

		for (int i = 0; i < N - 1; i++)
		{
			for (auto&& edge : edgeList)
			{
				//Relax
				if (dist[edge.V] > dist[edge.U] + edge.W)
				{
					return true; // Negetive cycle exist
				}
			}
		}
		
		return false;
	}
};


int main()
{
	scanf("%d", &T);
	while(T--)
	{
		int nStartSys, mWormWhole;
		scanf("%d %d", &nStartSys, &mWormWhole);

		Universe myUniverse(nStartSys, mWormWhole);
		for (int i = 0; i < mWormWhole; i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			myUniverse.addEdge(u, v, w);
		}

		//cout << T << ": " << endl;
		//myUniverse.printEdges();
		//cout << "//" << endl;

		myUniverse.printPosibility();
	}

	return 0;
}
