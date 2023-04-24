#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int x){
	if(x == 1){
		return false;
	}

	for(int i = 2; i <= sqrt(x); i++){
		if(x % i == 0){
			return false;
		}
	}

	return true;
}

int main(){
	// freopen("input.txt","r",stdin);
	
	int T;
	cin >> T;
	for(int i = 0;i<T;i++){
		int x,y;
		cin >> x >> y;
		for(int i = x; i<=y;i++){
			if(isPrime(i)){
				cout << i <<endl;
			}
		}
		cout << endl;
	}
	
	return 0;
}