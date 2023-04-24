#include<iostream>

using namespace std;

int m, n, h, w;

int arr[102][102];

int nhap()
{
	cin >> h >> w >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{

		nhap();
		int res = 0;

		for (int i = 0; i <= m - h; i++)
		{
			for (int j = 0; j <= n - w; j++)
			{
				int sum = 0;
				for (int k = j; k < j + w; k++)
				{
					if (arr[i][k] % 2 == 0) {
						sum += arr[i][k];
					}
					if (arr[i + h - 1][k] % 2 == 0 && h > 1)
					{
						sum += arr[i + h - 1][k];
					}

				}

				for (int k = i + 1; k < i + h - 1; k++)
				{
					if (arr[k][j] % 2 == 0) {
						sum += arr[k][j];
					}
					if (arr[k][j + w - 1] % 2 == 0 && w > 1)
					{
						sum += arr[k][j + w - 1];
					}
				}

				if (sum >= res) {
					res = sum;
				}
			}
		}
		cout << "#" << t << " " << res << endl;
	}
}