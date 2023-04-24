#include<iostream>
#include<cmath>

using namespace std;

int main(){

	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		int M, N;
		cin >> M >> N;
		int status[5] = {0};
		char arr[501][501];
		for(int i = 0; i < 5*M+1; i++){
			cin >> arr[i];
		}

		for(int i = 1; i < 5*M+1; i+=5){
			for(int j = 1; j < 5*N+1; j+=5){
				int count = 0;
				for(int k = 0; k < 4; k++){
					if(arr[i+k][j] == '*'){
						count++;
					}
				}
				status[count]++;
			}
		}

		cout << "#" << (i+1) << " ";
		for(int i = 0; i < 5; i++){
			cout << status[i] << " ";
		}
		cout << endl;
	}

	return 0;
}