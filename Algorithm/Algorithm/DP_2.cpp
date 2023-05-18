#include <vector>

using namespace std;

// ENCHANT
// 0강부터 시작

// n강 할 때 강화하는 모든 경우의 수

// 1 , 2 , 3강

// 3강 하고 싶으면
// 1 + 1
// 1 + 2
// 2 + 1
// 3

vector<int> cache;

int Enchant(int target)
{
	//기저 사항
	if (target == 1)
		return 1;
	if (target <= 0)
		return 0;

	//메모이제이션
	if (cache[target] != -1)
		return cache[target];

	//구하기
	return cache[target] = Enchant(target - 1) + Enchant(target - 2) + Enchant(target - 3);
}


void main()
{

}