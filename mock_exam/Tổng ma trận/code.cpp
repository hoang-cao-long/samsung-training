#include <iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int arr[101][101];
		int sum_main_diagonal = 0;
		int sum_sub_diagonal = 0;
		int result = 0;

		int N;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				cin >> arr[j][k];
			}
		}

		for (int j = 0; j < N; j++)
		{
			int sum_row = 0;
			int sum_col = 0;
			for (int k = 0; k < N; k++)
			{
				sum_row += arr[j][k];
				sum_col += arr[k][j];

				if (j == k)
				{
					sum_main_diagonal += arr[j][k];
				}

				if ((j + k) == (N - 1))
				{
					sum_sub_diagonal += arr[j][k];
				}
			}
			if (sum_row > result)
				result = sum_row;
			if (sum_col > result)
				result = sum_col;
		}

		if (sum_main_diagonal > result)
			result = sum_main_diagonal;
		if (sum_sub_diagonal > result)
			result = sum_sub_diagonal;

		cout << "#" << (i + 1) << " " << result << endl;
	}

	return 0;
}