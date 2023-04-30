#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int T; 
char arr[9][9];

bool check_same(char arr[]){
	for(int l = 0; l < 9; l++){
		if(arr[l] == '.'){
			continue;
		} else{
			int count = 0;
			for(int m = 0; m < 9; m++){
				if(arr[l] == arr[m]){
					count++;
				}
				if(count > 1){
					return true;
				}
			}
		}
	}

	return false;
};

int main() {
	freopen("input.txt","r",stdin);

	cin >> T; cin.ignore();
	for(int i = 0; i < T; i++){
		bool check_3_3 = false;
		bool check_row = false;
		bool check_col = false;
		int result = 1;

		for(int j = 0; j < 9; j++){
			cin >> arr[j];
		}

		bool is_break = false;
		for(int j = 0; j < 9; j+=3){
			if(is_break == true){
				break;
			}

			for(int k = 0; k < 9; k+=3){
				char arr_3_3[9];
				int count = 0;

				for(int l = j; l < j+3; l++){
					for(int m = k; m < k+3; m++){
						arr_3_3[count] = arr[l][m];
						count++;
					}
				}

				check_3_3 = check_same(arr_3_3);

				if(check_3_3 == true){
					is_break = true;
					break;
				}
			}	
		}


		for(int j = 0; j < 9; j++){
			char arr_row[9];
			char arr_col[9];

			for(int k = 0; k < 9; k++){
				arr_row[k] = arr[j][k];
				arr_col[k] = arr[k][j];
			}

			check_row = check_same(arr_row);
			check_col = check_same(arr_col);

			if(check_row == true || check_col == true){
				break;
			}
		}


		if(check_col == true || check_row == true || check_3_3 == true){
			result = 0;
		}
		cout << "#" << (i+1) << " " << result << endl;
	}

	return 0;
}