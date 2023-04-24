#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double max_in_array(double *arr, int size){
	double max = arr[0];
	for(int i = 1; i < size; i++){
		if(max < arr[i]){
			max = arr[i];
		}
	}

	return max;
}

int main() {
	freopen("input.txt","r",stdin);

	int T;cin >> T;
	for(int i = 0; i < T; i++){
		double arr[101][101];
		double arr_row[101] = {0};
		double arr_col[101] = {0};
		double sum_main_diagonal = 0;
		double sum_sub_diagonal = 0;

		int N; cin >> N;
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				cin >> arr[j][k];
			}
		}
		
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				arr_row[j] += arr[j][k];
				arr_col[j] += arr[k][j];

				if(j == k){
					sum_main_diagonal += arr[j][k];
				}

				if((j+k) == (N-1)){
					sum_sub_diagonal += arr[j][k];
				}
			}
		} 

		double max_row = max_in_array(arr_row, N);
		double max_col = max_in_array(arr_col, N);
		double arr_sum[4] = {max_row, max_col, sum_main_diagonal, sum_sub_diagonal};
		double max = max_in_array(arr_sum, 4);

		cout << "#" << (i+1) << " " << max << endl;
	}

	return 0;
}