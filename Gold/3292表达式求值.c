/*
题目描述 Description
给定一个只包含加法和乘法的算术表达式，请你编程计算表达式的值。

输入描述 Input Description
输入仅有一行，为需要你计算的表达式，
表达式中只包含数字、加法运算符“+”和乘法运算符“*”，且没有括号，
所有参与运算的数字均为0到2^31-1之间的整数。
输入数据保证这一行只有0~9、+、*这12种字符。

输出描述 Output Description
输出只有一行，包含一个整数，表示这个表达式的值。
注意：当答案长度多于4位时，请只输出最后4位，前导0不输出。

样例输入 Sample Input
[Sample 1]
1+1*3+4
[Sample 2]
1+1234567890*1
[Sample 3]
1+1000000003*1

样例输出 Sample Output
[Sample 1]
8
[Sample 2]
7891
[Sample 3]
4
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long number, s = 1, ans;
char buffer[ 1001000 ];
int main()
{
	int index;
	scanf( "%s", buffer );
	int len = strlen( buffer );
	for( index = 0; index < len; index++ )
	{
		while( isdigit( buffer[ index ] ) ){
			number = number * 10 + buffer[ index++ ] - '0';
		}
		s = ( s * number ) % 10000;
		if( buffer[ index ] == '+' )
		{
			ans = ( ans + s )%10000;
			s = 1;
			number = 0;
		}
		if( buffer[ index ] == '*' )
			number = 0;
	}
	ans = ( ans + s ) % 10000;
	printf( "%lld", ans );
	return 0;
}
