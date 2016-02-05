#include <stdio.h>
#include <stdlib.h>

int binaryTree[16][2];

void PreOrderTraverse(int i)
{
	if(i != 0){
		printf("%d ", i);
		PreOrderTraverse(binaryTree[i - 1][0]);
		PreOrderTraverse(binaryTree[i - 1][1]);
	}
}

void InOrderTraverse(int i)
{
	if(i != 0){
		InOrderTraverse(binaryTree[i - 1][0]);
		printf("%d ", i);
		InOrderTraverse(binaryTree[i - 1][1]);
	}
}

void PostOrderTraverse(int i)
{
	if(i != 0){
		PostOrderTraverse(binaryTree[i - 1][0]);
		PostOrderTraverse(binaryTree[i - 1][1]);
		printf("%d ", i);
	}
}

int main(int argc, char *argv[])
{
	int len;
	scanf("%d", &len);
	int index;
	for(index = 0;index < len;++index){
		scanf("%d %d", binaryTree[index], binaryTree[index] + 1);
	}
	
	PreOrderTraverse(1);
	putchar('\n');
	InOrderTraverse(1);
	putchar('\n');
	PostOrderTraverse(1);

	return 0;
}