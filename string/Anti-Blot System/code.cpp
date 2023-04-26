#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);

	int T; cin >> T; cin.ignore();
	for(int i = 0; i < T; i++){
		string blank_line; getline(cin, blank_line);
		string s; getline(cin, s);
		string s_error = "machula";
		stringstream ss(s);

		string number1;
		string add;
		string number2;
		string equal;
		string result;

		ss >> number1 >> add >> number2 >> equal >> result;

		if(number1.find(s_error) != string::npos){
			int number2_int = stoi(number2), result_int = stoi(result);
			int number1_int = result_int - number2_int;
			number1 = to_string(number1_int);
		} else if(number2.find(s_error) != string::npos){
			int number1_int = stoi(number1), result_int = stoi(result);
			int number2_int = result_int - number1_int;
			number2 = to_string(number2_int);
		} else if(result.find(s_error) != string::npos){
			int number1_int = stoi(number1), number2_int = stoi(number2);
			int result_int = number1_int + number2_int;
			result = to_string(result_int);
		}

		cout << number1 << " " << add << " " << number2 << " " << equal << " " << result << endl;
	}

	return 0;
}