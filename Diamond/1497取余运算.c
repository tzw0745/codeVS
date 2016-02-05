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
	llint a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	printf("%lld^%lld mod %lld=%lld",a, b, c, fastPow(a, b, c));
	return 0;
}