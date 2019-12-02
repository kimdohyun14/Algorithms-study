#include <iostream>
using namespace std;

// 19개의 블럭 시작은 (0,0)을 기준
int block[19][3][2] = {
	{{0,1},{0,2},{0,3}},
	{{1,0},{2,0},{3,0}},

	{{0,1},{1,0},{1,1}},

	{{1,0},{2,0},{2,1}},
	{{0,1},{0,2},{1,0}},
	{{0,1},{1,1},{2,1}},
	{{0,1},{0,2},{-1,2}},
	{{0,1},{1,0},{2,0}},
	{{1,0},{1,1},{1,2}},
	{{0,1},{-1,1},{-2,1}},
	{{0,1},{0,2},{1,2}},

	{{1,0},{1,1},{2,1}},
	{{0,1},{-1,1},{-1,2}},
	{{1,0},{1,-1},{2,-1}},
	{{0,1},{1,1},{1,2}},

	{{0,1},{0,2},{1,1}},
	{{1,0},{2,0},{1,1}},
	{{0,1},{0,2},{-1,1}},
	{{1,0},{2,0},{1,-1}},
};

int a[501][501];
int n, m;
int ans;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 19개의 블럭을 사용해서 가장 합이 많이 나오는 것을 찾는다.
			for (int k = 0; k < 19; k++)
			{
				int sum = a[i][j]; // 시작위치를 더해주고
				bool isPossible = true; // 보드 판 위에 블럭을 사용할 수 있는지 체크
				for (int l = 0; l < 3; l++)
				{
					int x = i + block[k][l][0];
					int y = j + block[k][l][1];

					// 경계 체크
					if (x >= 0 && x < n && y >= 0 && y < m)
					{
						sum += a[x][y];
					}
					else 
					{
						isPossible = false;
						break;
					}
				}

				// 최댓값 갱신
				if (isPossible && ans < sum)
					ans = sum;
			}
		}
	}

	cout << ans;
	return 0;
}