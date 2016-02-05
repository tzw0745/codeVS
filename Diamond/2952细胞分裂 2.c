#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long int llint;

llint fastPow(llint X, llint N, llint C)
{
	llint result = 1;
	while(N){
		if(N & 1){
			result = (result * X) % C;
			--N;
		}
		X = (X * X) % C;
		N = N>>1;
	}
	return result;
}

int main(int argc, char *argv[])
{
	llint b, c;
	scanf("%lld%lld", &b, &c);
	printf("%lld", fastPow(2, b, c));
	getch();
	return 0;
}