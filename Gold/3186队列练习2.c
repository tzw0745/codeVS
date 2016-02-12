/*
题目描述 Description
(此题与队列练习1相比改了2处:1加强了数据 2不保证队空时不会出队)
给定一个队列(初始为空)，只有两种操作入队和出队，现给出这些操作请
输出最终的队头元素。 操作解释：1表示入队，2表示出队

输入描述 Input Description
N(操作个数)
N个操作(如果是入队则后面还会有一个入队元素)
具体见样例(输入保证队空时不会出队)

输出描述 Output Description
最终队头元素，若最终队空，或队空时有出队操作，输出”impossible!”(不含引号)

样例输入 Sample Input
3
1 2
2
2

样例输出 Sample Output
impossible!

数据范围及提示 Data Size & Hint
对于100%的数据  N≤100000 元素均为正整数且小于等于10^8
*/
#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 100100

int queue[BUFFSIZE], isEmpty = 0;
int *head = queue, *rear = queue;
int main(int argc, char *argv[])
{
	int ammount, order, number;
	scanf("%d", &ammount);
	while(ammount-- && !isEmpty ){
		scanf("%d", &order);
		switch(order){
			case 1: scanf("%d", &number); *rear++ = number; break;
			case 2:{
				if( head == rear ) isEmpty = 1;
				else ++head;
			}
		}
	}
	if( isEmpty || rear == head) puts("impossible!");
	else printf("%d", *head);
	return 0;
}