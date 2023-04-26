#include <iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int a;
	cin >> a;

	while (a != 42)
	{
		cout << a << endl;
		cin >> a;
	}

	return 0;
}