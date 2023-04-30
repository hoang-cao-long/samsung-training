#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Node{
	char name;
	int row;
	int col;
	bool is_check;
};

int main() {
	freopen("input.txt", "r", stdin);

	int T; cin >> T;
	for(int i = 0; i < T; i++){
		int M, N; cin >> M >> N;
		char arr[101][101];
		vector<Node> arr_tram_phu_song;
		vector<Node> arr_ho_dan;

		for(int j = 0; j < M; j++){
			cin >> arr[j];
		}

		for(int j = 0; j < M; j++){
			for(int k = 0; k < N; k++){
				if(arr[j][k] == 'A' || arr[j][k] == 'B' || arr[j][k] == 'C'){
					Node new_node;
					new_node.name = arr[j][k];
					new_node.row = j;
					new_node.col = k;
					arr_tram_phu_song.push_back(new_node);
				}
				if(arr[j][k] == 'H'){
					Node new_node;
					new_node.name = arr[j][k];
					new_node.row = j;
					new_node.col = k;
					arr_ho_dan.push_back(new_node);
				}
			}
		}

		for(auto tram_phu_song : arr_tram_phu_song){
			if(tram_phu_song.name == 'A'){
				for(int j = 0; j < arr_ho_dan.size(); j++){
					if(tram_phu_song.row == arr_ho_dan[j].row && abs(tram_phu_song.col - arr_ho_dan[j].col) <= 1){
						arr_ho_dan.erase(arr_ho_dan.begin() + j);
						j--;
					} else if(tram_phu_song.col == arr_ho_dan[j].col && abs(tram_phu_song.row - arr_ho_dan[j].row) <= 1){
						arr_ho_dan.erase(arr_ho_dan.begin() + j);
						j--;
					}
				}
			}
			if(tram_phu_song.name == 'B'){
				for(int j = 0; j < arr_ho_dan.size(); j++){
					if(tram_phu_song.row == arr_ho_dan[j].row && abs(tram_phu_song.col - arr_ho_dan[j].col) <= 2){
						arr_ho_dan.erase(arr_ho_dan.begin() + j);
						j--;
					} else if(tram_phu_song.col == arr_ho_dan[j].col && abs(tram_phu_song.row - arr_ho_dan[j].row) <= 2){
						arr_ho_dan.erase(arr_ho_dan.begin() + j);
						j--;
					}
				}
			}
			if(tram_phu_song.name == 'C'){
				for(int j = 0; j < arr_ho_dan.size(); j++){
					if(tram_phu_song.row == arr_ho_dan[j].row && abs(tram_phu_song.col - arr_ho_dan[j].col) <= 3){
						arr_ho_dan.erase(arr_ho_dan.begin() + j);
						j--;
					} else if(tram_phu_song.col == arr_ho_dan[j].col && abs(tram_phu_song.row - arr_ho_dan[j].row) <= 3){
						arr_ho_dan.erase(arr_ho_dan.begin() + j);
						j--;
					}
				}
			}
		}


		cout << "#" << (i+1) << " " << arr_ho_dan.size() << endl;
	}

	return 0;
}