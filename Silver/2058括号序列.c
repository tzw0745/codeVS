/*
题目描述 Description
定义满足以下规则字符串为规则序列，否则不是规则序列：
1．空序列是规则序列；
2．如果S是规则序列，那么(S),[S],{S}和<S>也是规则序列；
3．如果A和B都是规则序列，那么AB也是规则序列。
例如，下面的字符串都是规则序列：
()，[]，(())，([])，()[]，()[()]，{{}}<>，([]<>{{}})，<<{}>>
而以下几个则不是：
(，[，]，)(，())，([()，<<，{(})，<{}>)
现在，给你一些由"("、")"、"["、"]"、"{"、"}"、"<"、">"构成的字符串，请判断该字符串是否为规则序列。

输入描述 Input Description
第一行：一个正整数N，表示测试数据组数；
接下来N行：每行一个括号序列(长度不超过L)。

输出描述 Output Description
共N行：对于每一个括号序列，判断其是否规则。
规则输出TRUE，否则输出FALSE。

样例输入 Sample Input
2
{()}<<>>
{{{{{}}}}

样例输出 Sample Output
TRUE
FALSE

数据范围及提示 Data Size & Hint
对于40%数据，有N=1，0<L<=20;
对于80%数据，有0<N<=5，0<L<=10^3;
对于100%数据，有0<N<=10，0<L<=2*10^6。
*/
#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 2001000

int matchBrackets( char *str )
{
	static char stack[BUFFSIZE];
	char *ptr = stack - 1;
	while( *str ){
		switch( *str ){
			case '(': case '[': case '{': case '<': *++ptr = *str; break;
			case ')': if( ptr < stack || *ptr-- != '(' ) return 0; break;
			case ']': if( ptr < stack || *ptr-- != '[' ) return 0; break;
			case '}': if( ptr < stack || *ptr-- != '{' ) return 0; break;
			case '>': if( ptr < stack || *ptr-- != '<' ) return 0; break;
		}
		++str;
	}
	return ptr < stack;
}

char buffer[BUFFSIZE];
int main(int argc, char *argv[])
{
	int ammount;
	scanf("%d", &ammount);
	while( ammount-- ){
		scanf("%s", buffer);
		if( matchBrackets( buffer ) ) puts("TRUE");
		else puts("FALSE");
	}
	getch();
	return 0;
}