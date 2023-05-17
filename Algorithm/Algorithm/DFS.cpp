#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<vector<bool>> adjacent;
vector<bool> discovered;
vector<int> path_recursion;
vector<int> path_while;

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
void DFS_recursion(int start)
{
	discovered[start] = true;
	path_recursion.push_back(start);

	for (int other = 0; other < adjacent[start].size(); other++)
	{
		if (other == start)
			continue;
		if (discovered[other])
			continue;
		if (adjacent[start][other])
		{
			
			DFS_recursion(other);
		}
	}
}

void DFS_while(int start)
{
	discovered = vector<bool>(adjacent.size(), false);

	discovered[start] = true;

	stack<int> s;
	s.push(start);

	while (true)
	{
		if (s.empty())
			break;
		int node = s.top();
		s.pop();
		path_while.push_back(node);

		for (int other = 0; other < adjacent[node].size(); other++)
		{
			if (other == node)
				continue;
			if (discovered[other])
				continue;
			if (adjacent[node][other])
			{
				s.push(other);
				discovered[other] = true;
			}
		}
	}

}

void main()
{

	CreateGraph();
	discovered = vector<bool>(adjacent.size(), false);
	DFS_recursion(0);
	DFS_while(0);
	cout << "recursion path" << endl;
	for (int i = 0; i < path_recursion.size(); i++)
	{
		cout << path_recursion[i] << " ";
	}
	cout << endl;
	cout << "while path" << endl;
	for (int i = 0; i < path_while.size(); i++)
	{
		cout << path_while[i] << " ";
	}
}