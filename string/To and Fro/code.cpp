#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);

	while(true){
		int col; cin >> col; cin.ignore();

		if(col < 2 || col > 20){
			break;
		}

		string s; getline(cin, s);
		int row = s.length() / col;
		char arr[201][201];
		string result;

		int count = 0;
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(i % 2 != 0){
					arr[i][col-1-j] = s[count];
				}else{
					arr[i][j] = s[count];
				}
				count++;
			}
		}

		for(int i = 0; i < col; i++){
			for(int j = 0; j < row; j++){
				result.push_back(arr[j][i]);
			}
		}

		cout << result << endl;
	}
	return 0;
}