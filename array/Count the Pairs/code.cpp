#include<iostream>
#include<cmath>

using namespace std;

int main(){

	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		int c[10002];
		int count = 0;
		cin >> a >> b;
		for(int i = 0; i < a; i++){
			cin >> c[i];
		}
		for(int i = 0; i < a - 1; i++){
			for(int j = i + 1; j < a; j++){
				float sum = c[i] - c[j];
				if(fabs(sum) == b){
					count++;
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}