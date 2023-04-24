#include<iostream>

using namespace std;

int getReverse(int a){
	int leng = 0;
	int p[10];

	while(a){
		int tmp = a%10;
		p[leng++] = tmp;
		a = a/10;
	}

	int result = 0;
	for(int i = 0;i<leng;i++){
		result = result*10 + p[i];
	}
	return result;
}

int main(){
	// freopen("input.txt","r",stdin);
	
	int t;
	cin >> t;
	for(int i = 0;i<t;i++){
		int x,y;
		cin >> x >> y;
		
		int a = getReverse(x) + getReverse(y);
		cout << getReverse(a) << endl;
	}
	
	return 0;
}