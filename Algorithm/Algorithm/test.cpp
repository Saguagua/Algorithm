#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> visited;

#include <string>
#include <vector>

using namespace std;

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> used;

vector<string> DFS(vector<vector<string>>& v, string start)
{
    vector<string> answer;

    for (int i = 0; i < v.size(); i++)
    {
        if (used[i])
            continue;
        if (v[i][0] != start)
            continue;
        used[i] = true;
        vector<string> tmp = DFS(v, v[i][1]);

        if (tmp.size() > answer.size())
            answer = tmp;
        else if (tmp.size() == answer.size())
        {
            for (int i = tmp.size()-1; i >= 0; i--)
            {
                if (tmp[i] < answer[i])
                {
                    answer = tmp;
                    break;
                }
                else if (tmp[i] > answer[i])
                    break;
            }
        }
        used[i] = false;
    }
    answer.push_back(start);
    return answer;
}

vector<string> solution(vector<vector<string>> tickets) {
    used.resize(tickets.size(), false);
    vector<string> answer = DFS(tickets, "ICN");
    std::reverse(answer.begin(), answer.end());
    return answer;
}
void main()
{
    vector<vector<string>> c = { {"ICN", "SFO"} ,{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"} };
    vector<vector<string>> d = { {"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"}};
    solution(c);
}