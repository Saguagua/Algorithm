#include <vector>

using namespace std;

// ENCHANT
// 0������ ����

// n�� �� �� ��ȭ�ϴ� ��� ����� ��

// 1 , 2 , 3��

// 3�� �ϰ� ������
// 1 + 1
// 1 + 2
// 2 + 1
// 3

vector<int> cache;

int Enchant(int target)
{
	//���� ����
	if (target == 1)
		return 1;
	if (target <= 0)
		return 0;

	//�޸������̼�
	if (cache[target] != -1)
		return cache[target];

	//���ϱ�
	return cache[target] = Enchant(target - 1) + Enchant(target - 2) + Enchant(target - 3);
}


void main()
{

}