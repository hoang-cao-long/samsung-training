#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	for(int i = 0; i < n;i++){
		int a;
		cin >> a;
		int sum = 0;
		for(int j = 1; j <= a; j++){
			int b = a / j;
			sum = (sum + (b*j)) % 1000007;
		}
		cout << sum % 1000007 << endl;
	}
	return 0;
}