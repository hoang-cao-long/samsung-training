#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	if(n <= 20){
		for(int i = 0; i < n;i++){
			int a,b;
			cin >> a >> b;
			long long c = pow(a,b);
			cout << "#" << (i+1) << " " << c << endl;
		}
	}
	return 0;
}