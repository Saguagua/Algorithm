#include <vector>

using namespace std;
// n개의 공을 갖고있다.
// 순서 상관없이 m개의 공을 꺼낼 때 나올 수 있는 경우의 수를 모두 구하시오.
// n >= 1
// m >= 0

//nCr => n은 뽑을 수 있는 경우의 수, r은 뽑을 수 있는 개수

//nCr => n-1Cr-1 + n-1Cr
vector<vector<int>> v = vector<vector<int>>(100, vector<int>(100, -1));

int Combine(int n, int m)
{
	//기저사항
	if (m == 0 || n == m)
		return 1;
	
	if (n < m || m == 0)
		return 0;
	//메모이제이션
	if (v[n][m] != -1)
		return v[n][m];

	//구하기
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