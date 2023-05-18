#include <vector>

using namespace std;

vector<int> v = { 5,1,23,7,5,9,8,1 };
vector<int> cache = vector<int>(v.size(), 1);

int LIS(int index, vector<int>& v)
{
	//기저사항
	if (index == v.size() - 1)
		return 1;
	//메모이제이션
	int& count = cache[index];
	int maximum = count;
	//구하기
	for (int i = index; i < v.size(); i++)
	{
		if (v[i] > v[index])
		{
			count = max(count, LIS(i, v) + 1);
		}
		
	}

	return count;
}

void main()
{
	int ans = LIS(0, v);


}