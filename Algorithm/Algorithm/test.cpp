#include <string>
#include <vector>
#include <queue>

using namespace std;
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
struct Compare
{
    bool operator()(const pair<int, int> p1, const pair<int, int> p2)
    {
        return p1.second > p2.second;
    }
};


int solution(vector<int> array) {
    if (array.size() == 1)
        return array[0];

    priority_queue < pair<int, int>, vector<pair<int, int>>, Compare> pq;
    vector<int> v = vector<int>(array.size(), 0);

    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] - 1 << endl;
        v[array[i] - 1]++;
    }

    for (int i = 0; i < v.size(); i++)
    {
        pair<int, int> pair = { i + 1, v[i] };
        pq.push(pair);
    }
    auto pair1 = pq.top();
    pq.pop();
    auto pair2 = pq.top();

    cout << pair1.second << endl;
    cout << pair2.second << endl;

    return pair1.second > pair2.second ? pair1.first : -1;
}

void main()
{
    
}