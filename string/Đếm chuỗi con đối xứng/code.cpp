#include <iostream>
#include <string>

using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);

	int T; cin >> T; cin.ignore();
	for(int i = 0; i < T; i++){
		string s;
		getline(cin, s);

		int result = 0;
		int length_string = s.length();

		while(length_string > 0){
			for(int k = 0; k <= s.length() - length_string; k++){
				int count = 0;
				int range = 0;
				
				for(int l = k; l < length_string/2 + k; l++){
					if(s[l] == s[length_string+k-range-1]){
						count++;
					}
					range++;
				}
				if(count == length_string/2){
					result++;
				}
			}
			length_string--;
		}
		cout << "#" << (i+1) << " " << result << endl;
	}

	return 0;
}