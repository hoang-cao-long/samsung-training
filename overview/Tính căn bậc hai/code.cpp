#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	// your code here
	int n;
	cin >> n;
	for(int i = 0; i < n;i++){
		int a;
		cin >> a;
		int b = sqrt(a);
		cout << "#" << (i+1) << " " << b << endl;
	}
	return 0;
}