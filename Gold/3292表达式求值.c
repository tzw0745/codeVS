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
#include <string.h>

/* 设置常数 */
#define BUFFSIZE 1001000
#define MOD 10000

long long number, block = 1, ans;
char buffer[ BUFFSIZE ];
int main()
{
	char *p = buffer;
	gets(p);
	while( *p ){
		/* 转换成数字 */
		number = 0;
		while( isdigit( *p ) ) number = number * 10 + *p++ - '0';
		/* 计算块大小 */
		block = ( block * number ) % MOD;
		/* 判断符号位 */
		switch( *p ){
			case 0: continue;/* 如果是结束符 */
			case '+':{
				/* 如果是加号 累加块，块值清空 */
				ans = ( ans + block ) % MOD;
				block = 1;
			}
			default:++p;
		}
	}
	/* 加上最后一个块 */
	ans = ( ans + block ) % MOD;
	printf( "%lld", ans );
	return 0;
}
