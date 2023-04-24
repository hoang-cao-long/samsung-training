#include <iostream>
using namespace std;

int main() {
	int a[100];
	for(int i = 0; i < 100;i++){
		cin >> a[i];
	}
	int j = 0;
	while(a[j] != 42 && j <100){
		cout << a[j] << endl;
		j++;
	}

	return 0;
}