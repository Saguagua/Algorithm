#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> adjacent;
vector<int> parent;
vector<bool> discovered;

void CreateGraph()
{
	adjacent = vector<vector<bool>>(7, vector<bool>(7, false));

	adjacent[0][0] = true;
	adjacent[0][1] = true;
	adjacent[0][2] = true;
	adjacent[0][4] = true;

	adjacent[1][0] = true;
	adjacent[1][1] = true;
	adjacent[1][6] = true;

	adjacent[2][0] = true;
	adjacent[2][2] = true;
	adjacent[2][3] = true;
	adjacent[2][5] = true;

	adjacent[3][2] = true;
	adjacent[3][3] = true;

	adjacent[4][0] = true;
	adjacent[4][4] = true;

	adjacent[5][2] = true;
	adjacent[5][5] = true;
	adjacent[5][3] = true;

	adjacent[6][1] = true;
	adjacent[6][6] = true;
}

void BFS(int start)
{
	parent = vector<int>(adjacent.size(), -1);
	discovered = vector<bool>(adjacent.size(), false);

	parent[start] = start;
	discovered[start] = true;


	queue<int> q;
	q.push(start);

	while (true)
	{
		if (q.empty())
			break;
		int node = q.front();
		q.pop();

		for (int other = 0; other < adjacent[node].size(); other++)
		{
			if (other == node)
				continue;
			if (discovered[other])
				continue;
			if (adjacent[node][other])
			{
				q.push(other);
				parent[other] = node;
				discovered[other] = true;
			}
		}
	}
}

void main()
{
	CreateGraph();
	BFS(0);
}