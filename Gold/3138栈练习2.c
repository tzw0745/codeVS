/*
题目描述 Description
(此题与栈练习1相比改了2处:1加强了数据 2不保证栈空时不会出栈)
给定一个栈(初始为空,元素类型为整数,且小于等于100),只有两个操作:入栈和出栈。
先给出这些操作，请输出最终栈的栈顶元素。
操作解释：1表示入栈，2表示出栈

输入描述 Input Description
N(操作个数)
N个操作(如果是入栈则后面还会有一个入栈元素)
具体见样例(输入不保证栈空时不会出栈)

输出描述 Output Description
最终栈顶元素，若最终栈空，或栈空时有出栈操作，输出”impossible!”(不含引号)

样例输入 Sample Input
3
1 2
2
2

样例输出 Sample Output
impossible!
*/
#include <stdio.h>
#include <stdlib.h>

int flag = 0;

typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

struct Node
{
	ElementType Element;
	PtrToNode Next;
};

Stack CreateStack( void )
{
	Stack s = malloc( sizeof( struct Node ) );
	if( s == NULL){
		puts( "Heap Over Flow!" );
		exit(1);
	}
	s->Next = NULL;
	return s;
}	/* CreateStack */

void Push( ElementType X, Stack S )
{
	PtrToNode newNode = malloc( sizeof( struct Node ) );
	if(newNode == NULL){
		puts( "Heap Over Flow!" );
		exit(1);
	}
	else{
		newNode->Element = X;
		newNode->Next = S->Next;
		S->Next = newNode;
	}
}	/* Push */

void Pop( Stack S )
{
	if( S->Next == NULL )
		flag = 1;
	else{
		PtrToNode firstNode = S->Next;
		S->Next = firstNode->Next;
		free( firstNode );
	}
}	/* Pop */

/* Return the top element in stack */
/* Return 0 if the stack is empty */
ElementType Top( Stack S )
{
	if( !( S->Next == NULL ) )
		return S->Next->Element;
	return 0;
}	/* Top */

int main(int argc, char *argv[])
{
	Stack s = CreateStack();
	int loop, order, number;
	scanf("%d", &loop);
	while(loop--){
		scanf("%d", &order);
		switch(order){
			case 1:scanf("%d", &number);Push(number, s);break;
			case 2:Pop(s);
		}
	}
	if( s->Next == NULL || flag)
		puts("impossible!");
	else
		printf("%d", Top(s));
	return 0;
}