#include <iostream>

using namespace std;

#define KNIGHT 1
#define PAWN 2 
#define DISABLE 3

int T, N, K, M, D;
int arr[1001][1001] = {0};
int arr_k[2][1000001];
int max_knight_eat;
int x_knight;
int y_knight;

int dx_knight[] = {-2,-2,-1,1,2,2,1,-1};
int dy_knight[] = {-1,1,2,2,1,-1,-2,-2};

void input(){
	cin >> N >> K >> M >> D;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			arr[i][j] = 0;
		}
	}

	for(int i = 0; i < K; i++){
		cin >> arr_k[0][i] >> arr_k[1][i];
		arr[arr_k[0][i]][arr_k[1][i]] = KNIGHT;
	}

	int x, y;
	for(int i = 0; i < M; i++){
		cin >> x >> y;
		arr[x][y] = PAWN;
	}

	for(int i = 0; i < D; i++){
		cin >> x >> y;
		arr[x][y] = DISABLE;
	}
}

bool is_on_board(int x, int y){
	if(x < 0 || x >= N || y < 0 || y >= N) return false;
	return true;
}

void handle(){
	max_knight_eat = 0;
	x_knight = arr_k[0][0];
	y_knight = arr_k[0][0];

	for(int i = 0; i < K; i++){
		int count_knight_eat = 0;
		int tmp_x_knight = arr_k[0][i];
		int tmp_y_knight = arr_k[1][i];

		for(int j = 0; j < 8; j++){
			int x = arr_k[0][i] + dx_knight[j];
			int y = arr_k[1][i] + dy_knight[j];

			if(is_on_board(x,y)){
				if(arr[x][y] == PAWN || arr[x][y] == KNIGHT){
					count_knight_eat++;
				}
			}
		}

		if(max_knight_eat < count_knight_eat){
			max_knight_eat = count_knight_eat;
			x_knight = tmp_x_knight;
			y_knight = tmp_y_knight;
		}
	}
}

int main() {
	freopen("input.txt","r",stdin);

	cin >> T;
	for(int i = 0; i < T; i++){
		input();
		handle();

		cout << "#" << (i+1) << " " << x_knight << " " << y_knight << " " << max_knight_eat << endl;
	}

	return 0;
}