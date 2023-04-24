#include <iostream>
#include <cmath>
using namespace std;

bool checkInteger(float x){
	if(ceil(x) == floor(x)){
		return true;
	}
	return false;
}

int main() {
	
	// your code here
	int n;
	cin >> n;
	for(int i = 0; i < n;i++){
		int a,b;
		cin >> a >> b;
		cout << "#" << (i+1) << " ";
		int count = 0;
		for(int j = a; j<=b;j++){
			float result = sqrt(j);
			if(checkInteger(result)){
				count ++;
				cout << j << " ";
			}
		}
		if(count == 0){ cout << "NO NUMBER"; }
		cout << endl;
	}
	return 0;
}