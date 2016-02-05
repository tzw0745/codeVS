#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binaryTree[16][2], len;

int treeDeep(int i)
{
	if(0 == i)
		return 0;
	else{
		int leftDeep = treeDeep(binaryTree[i - 1][0]);
		int rightDeep = treeDeep(binaryTree[i - 1][1]);
		return leftDeep > rightDeep ? leftDeep + 1 : rightDeep + 1;
	}
}

int treeWidth()
{
	int levelNode[20][20] = {{1}}, levelLen[20] = {1}, level = 0;
	while(1){
		int i, n = 0;
		for(i = 0;i < levelLen[level];++i){
			if(binaryTree[levelNode[level][i] - 1][0] != 0) levelNode[level + 1][n++] = binaryTree[levelNode[level][i] - 1][0];
			if(binaryTree[levelNode[level][i] - 1][1] != 0) levelNode[level + 1][n++] = binaryTree[levelNode[level][i] - 1][1];
		}
		level += 1;
		levelLen[level] = n;
		if(n == 0) break;
	}
	int maxLen = levelLen[0];
	int i;
	for(i = 1; i < level; ++i){
		if(levelLen[i] > maxLen) maxLen = levelLen[i];
	}
	return maxLen;
}

int main(int argc, char *argv[])
{
	scanf("%d", &len);
	int index;
	for(index = 0;index < len;++index){
		scanf("%d %d", binaryTree[index], binaryTree[index] + 1);
	}
	
	int deep = treeDeep(1);
	printf("%d %d", treeWidth(), deep);
	getch();
	return 0;
}