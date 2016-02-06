/*
题目描述 Description
给出一棵二叉树的中序与后序排列。求出它的先序排列。（约定树结点用不同的大写字母表示，长度<=8）。

输入描述 Input Description
两个字符串，分别是中序和后序（每行一个）

输出描述 Output Description
一个字符串，先序

样例输入 Sample Input
BADC
BDCA

样例输出 Sample Output
ABCD
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 512

void printHead(char *inPtr, char *postPtr, int len)
{
	if(len <= 1){
		if(len == 1) putchar(inPtr[0]);
		return;
	}
	char head = postPtr[len - 1];
	if(head != '\r') putchar(head);
	int leftLen = 0, rightLen = 0;
	leftLen = strchr(inPtr, head) - inPtr;
	rightLen = len - leftLen - 1;
	printHead(inPtr, postPtr, leftLen);//left sub tree
	printHead(inPtr + leftLen + 1, postPtr + leftLen, rightLen);//right sub tree
}

int main(int argc, char *argv[])
{
	char inSeq[BUFFSIZE], postSeq[BUFFSIZE];
	gets(inSeq);
	gets(postSeq);
	printHead(inSeq, postSeq, strlen(postSeq));
	return 0;
}