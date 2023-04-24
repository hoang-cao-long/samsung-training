#include<iostream>

using namespace std;


int a[1004][1004], dem;

int n, m;
int hau, ma;

int tot, totx, toty;

// luu vi tri toa do huong quan hau co the di duoc
int dxhau[] = { -1,-1,0,1,1,1,0,-1 }; // 8
int dyhau[] = { 0,1,1,1,0,-1,-1,-1 }; // 8

// luu vi tri toa do huong quan ma co the di duoc
int dxma[] = { -2,-2,-1,1,2,2,1,-1 }; // 8
int dyma[] = { -1,1,2,2,1,-1,-2,-2 }; // 8

int n_hau[2][100]; // gia tri n_hau[0][] la toa do x, n_hau[1][] la toa do y
int n_ma[2][100];

void nhap() {
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			a[i][j] = 0;
		}
	}
	// nhap hau
	cin >> hau;
	if (hau > 0) {
		for (int i = 0; i < hau; i++) {

			cin >> n_hau[0][i] >> n_hau[1][i];

			a[n_hau[0][i] - 1][n_hau[1][i] - 1] = 1;
		}
	}
	// nhap ma
	cin >> ma;
	if (ma > 0) {
		for (int i = 0; i < ma; i++)
		{
			cin >> n_ma[0][i] >> n_ma[1][i];

			a[n_ma[0][i] - 1][n_ma[1][i] - 1] = 2;
		}
	}
	// nhap tot
	cin >> tot;
	if (tot > 0) {
		for (int i = 0; i < tot; i++)
		{
			cin >> totx >> toty;
			a[totx - 1][toty - 1] = 3;
		}
	}

}

bool check(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)return false;
	return true;
}

void kiemtra() {

	dem = 0;
	// Quan hau
	for (int i = 0; i < hau; i++)
	{
		for (int j = 0; j < 8; j++) {
			int x = n_hau[0][i] - 1 + dxhau[j];
			int y = n_hau[1][i] - 1 + dyhau[j];
			while (check(x,y) && (a[x][y] == 0 || a[x][y] == -1))
			{
				a[x][y] = -1;
				x = x + dxhau[j];
				y = y + dyhau[j];
			}
		}
	}

	// Quan ma

	for (int i = 0; i < ma; i++)
	{
		for (int j = 0; j < 8; j++) {
			int x = n_ma[0][i] - 1 + dxma[j];
			int y = n_ma[1][i] - 1 + dyma[j];

			if (check(x, y) && (a[x][y] == 0 || a[x][y] == -1)) {
				a[x][y] = -1;
				x = x + dxma[j];
				y = y + dyma[j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0)dem++;
		}
	}
}

int main() {

	for (int t = 1;; t++) {
		cin >> n >> m;
		if (n == 0 || m == 0)break;

		nhap();
		kiemtra();
		cout << "Board " << t << " has " << dem << " safe squares. " << endl;
	}
	return 0;
}