#include<iostream>

using namespace std;

int T, N, check, res;
int arr[100005];

void xuly() {
	int b[100005];
	for (int i = 0; i < 100005; i++)
	{
		b[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		b[arr[i]]++;
		if (b[arr[i]] == 2) {
			check = 1;
			res = arr[i];
			break;
		}
	}
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		check = 0;
		res = 0;
		xuly();
		if(check ==0)res = -1;
		cout << "#" << t << " " << res << endl;
	}
}