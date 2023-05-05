#include <iostream>
#include <vector>
using namespace std;

int T, n, m;
int a_beauty_number[10];
vector<int> a;
int x, y;
int result;

void input(){
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		cin >> a_beauty_number[i];
	}

	cin >> x >> y;
}

void handle(){
	result = 0;

	for(int i = x; i <= y; i++){
		int save_number = i;
		int count_beauty_number = 0;

		while(save_number != 0){
			int single_number = save_number%10;

			for(int i = 0; i < n; i++){
				if(single_number == a_beauty_number[i]){
					count_beauty_number++;
				}
			}

			save_number = save_number/10;
		}

		if(count_beauty_number >= m){
			result++;
			a.push_back(i);
		}
	}
}

int main() {
	freopen("input.txt","r",stdin);

	cin >> T;
	for(int i = 0; i < T; i++){
		input();
		handle();

		cout << "#" << (i+1) << " " << result << endl;
	}

	return 0;
}