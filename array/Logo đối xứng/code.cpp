#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	int T; cin >> T;
	for(int i = 0; i < T; i++){
		int arr[33][33];
		bool result_row = true;
		bool result_col = true;

		int N; cin >> N;
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				cin >> arr[j][k];
			}
		}

		for(int j = 0; j < N/2; j++){
			for(int k = 0; k < N; k++){
				if(arr[j][k] != arr[N-1-j][k]){
					result_row = false;
					break;
				}

				if(arr[k][j] != arr[k][N-j-1]){
					result_col = false;
					break;
				}
			}
		}

		cout << "#" << (i+1) << " ";
		if(result_row == true && result_col == true){
			cout << "YES" << endl;
		} else{
			cout << "NO" << endl;
		}

	}

	return 0;
}