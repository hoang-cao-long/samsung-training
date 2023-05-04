#include <iostream>
#include <cmath>

using namespace std;

int T, N, M, K;
int a[101][101];
int a_sum[101][101] = {0};
int current_row;
int current_col;

void input(){
	cin >> N >> M >> K;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> a[i][j];
		}
	}
}

void handle(){
	for(int i = 0; i <= N-M; i++){
		for(int j = 0; j <= N-M; j++){
			a_sum[i][j] = 0;

			for(int k = i; k < M+i; k++){
				for(int l = j; l < M+j; l++){
					a_sum[i][j] += a[k][l];
				}
			}
		}
	}

	int min_abs = abs(K-a_sum[0][0]);
	int min_sum = a_sum[0][0];
	current_row = 0;
	current_col = 0;

	for(int i = 0; i <= N-M; i++){
		for(int j = 0; j <= N-M; j++){
			if(min_abs > abs(K-a_sum[i][j])){
				min_abs = abs(K-a_sum[i][j]);
				current_row = i;
				current_col = j;
				min_sum = a_sum[i][j];
			} else if(min_abs == abs(K-a_sum[i][j])){
				if(min_sum > a_sum[i][j]){
					min_sum = a_sum[i][j];
					current_row = i;
					current_col = j;
				} else if(min_sum == a_sum[i][j]){
					if(current_row > i){
						current_row = i;
						current_col = j;
					} else if(current_row == i){
						if(current_col > j){
							current_col = j;
						}
					}
				}
			}
		}
	}
}

int main() {
	freopen("input.txt","r",stdin);

	cin >> T;
	for(int i = 0; i < T; i++){
		input();
		handle();

		cout << "#" << (i+1) << " " << current_row << " " << current_col << endl;
	}

	return 0;
}