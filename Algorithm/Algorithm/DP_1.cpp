#include <vector>

using namespace std;
// n���� ���� �����ִ�.
// ���� ������� m���� ���� ���� �� ���� �� �ִ� ����� ���� ��� ���Ͻÿ�.
// n >= 1
// m >= 0

//nCr => n�� ���� �� �ִ� ����� ��, r�� ���� �� �ִ� ����

//nCr => n-1Cr-1 + n-1Cr
vector<vector<int>> v = vector<vector<int>>(100, vector<int>(100, -1));

int Combine(int n, int m)
{
	//��������
	if (m == 0 || n == m)
		return 1;
	
	if (n < m || m == 0)
		return 0;
	//�޸������̼�
	if (v[n][m] != -1)
		return v[n][m];

	//���ϱ�
	return v[n][m] = Combine(n - 1, m - 1) + Combine(n - 1, m);
}

void main()
{
	int ans = Combine(10, 1);
	int ans2 = Combine(3, 1);
	int ans3 = Combine(4, 1);
	int ans4 = Combine(5, 1);
	int ans5 = Combine(7, 5);

}