#include <iostream>
#include <algorithm>

using namespace std;

void sort_array(int arr[], int size){
	for(int i = 0; i < size-1; i++){
		for(int j = i+1; j < size; j++){
			if(arr[i] > arr[j]){
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main() {
	// freopen("input.txt","r",stdin);

	int T;cin >> T;
	for(int i = 0; i < T; i++){
		int N, M1, M2;
		int arr_weight[1001];
		int arr_floor[51] = {0};
		int sum = 0;

		cin >> N >> M1 >> M2;

		for(int j = 0; j < N; j++){
			cin >> arr_weight[j];
		}

		for(int k = 0; k < M1; k++){
			arr_floor[k] = k + 1;
		}

		for(int k = 0; k < M2; k++){
			arr_floor[N-k-1] = k + 1;
		}

		sort_array(arr_weight, N);
		sort_array(arr_floor, N);

		for(int j = 0; j < N; j++){
			sum += arr_floor[j] * arr_weight[N-j-1];
		}

		cout << "#" << (i+1) << " " << sum << endl;
	}

	return 0;
}