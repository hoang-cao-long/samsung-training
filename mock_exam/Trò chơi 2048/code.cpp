#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MEMORY 1001

int T, N, arr[MEMORY];

int max_in_array(int *arr){
	int max = arr[0];
	for(int i = 1; i < sizeof(arr); i++){
		if(max < arr[i]){
			max = arr[i];
		}
	}

	return max;
}

void merge_array(){
	int new_arr[MEMORY];

	int count_same = 0;
	int count = 0;
	for(int i = N-1; i >= 0; i--){
		if(i != 0 && arr[i] == arr[i-1]){
			int sum = arr[i] + arr[i-1];
			new_arr[count] = sum;
			i--;
			count_same++;
		}else{
			new_arr[count] = arr[i];
		}
		count++;
	}

	N = count;
	for(int i = 0; i < N; i++){
		arr[i] = new_arr[i];
	}

	if(count_same != 0){
		merge_array();
	}
}

int main() {
	freopen("input.txt","r",stdin);

	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> N;

		for(int j = 0; j < N; j++){
			cin >> arr[j];
		}

		merge_array();
		int max = max_in_array(arr);

		cout << "#" << (i+1) << " " << max << endl;
	}

	return 0;
}