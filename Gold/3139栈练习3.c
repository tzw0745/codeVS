/*
题目描述 Description
比起第一题，本题加了另外一个操作，访问栈顶元素(编号3，保证访问栈顶元素时或出栈时栈不为空)，
现在给出这N此操作，输出结果。

输入描述 Input Description
N
N次操作(1入栈 2出栈 3访问栈顶)

输出描述 Output Description
K行(K为输入中询问的个数)每次的结果

样例输入 Sample Input
6
1  7
3
2
1  9
1  7
3

样例输出 Sample Output
7
7
*/
#include <stdio.h>
#include <stdlib.h>

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
		puts("impossible");
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
			case 2:Pop(s);break;
			case 3:printf("%d\n", Top(s));
		}
	}
	return 0;
}