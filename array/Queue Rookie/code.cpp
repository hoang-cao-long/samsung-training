#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	// freopen("input.txt","r",stdin);

	int T; cin >> T;
	for(int i = 0; i < T; i++){
		int N; cin >> N;
		int heights_and_orders[2][1001];
		int height_afters[1001] = {0};

		for(int j = 0; j < 2; j++)
			for(int k = 0; k < N; k++)
				cin >> heights_and_orders[j][k];

		for(int j = 0; j < N-1; j++){
			for(int k = j+1; k < N; k++){
				if(heights_and_orders[0][j] > heights_and_orders[0][k]){
					int tmp_height = heights_and_orders[0][j];
					heights_and_orders[0][j] = heights_and_orders[0][k];
					heights_and_orders[0][k] = tmp_height;

					int tmp_order = heights_and_orders[1][j];
					heights_and_orders[1][j] = heights_and_orders[1][k];
					heights_and_orders[1][k] = tmp_order;
				}
			}
		}

		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				if(height_afters[k] == 0){
					if(heights_and_orders[1][j] == 0){
						height_afters[k] = heights_and_orders[0][j];
						break;
					}else{
						heights_and_orders[1][j]--;
					}
				}
			}
		}

		for(int j = 0; j < N; j++){
			cout << height_afters[j] << " ";
		}
	}

	return 0;
}