/*
题目描述 Description
比起第一题，本题加了另外一个操作，访问队头元素(编号3，保证访问队头元素时或出队时队不为空)，现在给出这N此操作，输出结果。

输入描述 Input Description
N
N次操作(1入队 2出队 3访问队头)

输出描述 Output Description
K行(K为输入中询问的个数)每次的结果

样例输入 Sample Input
6
1 7
3
2
1 9
1 7
3

样例输出 Sample Output
7
9

数据范围及提示 Data Size & Hint
对于50%的数据 N≤1000 入队元素≤200
对于100%的数据 N≤100000入队元素均为正整数且小于等于10^4
*/
#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 100100

int queue[BUFFSIZE];
int *head = queue, *rear = queue;
int main(int argc, char *argv[])
{
	int ammount, order, number;
	scanf("%d", &ammount);
	while(ammount--){
		scanf("%d", &order);
		switch(order){
			case 1: scanf("%d", &number); *rear++ = number; break;
			case 2: ++head; break;
			case 3: printf("%d\n", *head); break;
		}
	}
	return 0;
}