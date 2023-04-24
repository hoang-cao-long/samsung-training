#include <iostream>
#include <string>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	//int T; cin >> T; cin.ignore();
	for(int i = 0; i < 10; i++){
		int T; cin >> T; cin.ignore();
		string S1, S2;
		getline(cin, S1); getline(cin, S2);

		int leng_s1 = S1.length();
		int leng_s2 = S2.length();

		int result = 0;
		for(int j = 0; j <= leng_s2-leng_s1; j++){
			int count = 0;
			int range = 0;
			for(int k = j; k < leng_s1+j; k++){
				if(S1[range] == S2[k]){
					count++;
				}
				range++;
			}
			if(count == leng_s1){
				result++;
			}
		}

		cout << "#" << (i+1) << " " << result << endl;
	}

	return 0;
}