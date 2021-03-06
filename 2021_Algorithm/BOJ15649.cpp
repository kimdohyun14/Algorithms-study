#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool check[10];
int ans[10];

void go(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			ans[cnt] = i;
			go(cnt + 1);
			check[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	go(0);
	return 0;
}
