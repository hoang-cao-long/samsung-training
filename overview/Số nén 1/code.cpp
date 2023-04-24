#include "stdio.h"

long long sumNumber(long long x){
	long long sum = 0;
	while(x){
		sum += (x % 10);
		x = x/10;
	}
	if(sum == (sum % 10)){
		return sum;
	}
	return sumNumber(sum);
}

int main(){

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n;i++){
		long long a;
		scanf("%d", &a);
		printf("#%d  %d\n", (i+1), sumNumber(a));
	}

	return 0;
}