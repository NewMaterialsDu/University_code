#include<stdio.h>
#include<stdlib.h>
#include<iostream>

//邻接矩阵表视图
typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100

typedef struct {
	//保存顶点
	VertexType vertex[MAXSIZE];
	//两个顶点之间边的关系，有边为一，无边为0
	//边的信息(二维数组中两个顶点相交的地方的值表示边的权值)（这里没有权值）
	EdgeType arc[MAXSIZE][MAXSIZE];
	//顶点数量和边的数量
	int vertex_num;
	int edge_num;
}Mat_Grph;

//用来记录顶点是否被访问过
int visited[MAXSIZE];

//层序遍历使用队列（广度优先也使用）(不完全算是队列，只是用数组模拟)
int front = 0;
int rear = 0;
int queue[MAXSIZE];

//手动添加顶点信息
void create_graph(Mat_Grph* G) {
	G->vertex_num = 9;
	G->edge_num = 15;
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';

	//初始化边的信息，先把所有的边都设置为0（无边）
	for (int i = 0; i < G->vertex_num; i++) {
		for (int j = 0; j < G->vertex_num; j++) {
			G->arc[i][j] = 0;
		}
	}

	//手动添加边的信息
	//A-B A-F 
	G->arc[0][1] = 1;
	G->arc[0][5] = 1;

	//B-C B-G B-I
	G->arc[1][2] = 1;
	G->arc[1][6] = 1;
	G->arc[1][8] = 1;

	//C-D C-I
	G->arc[2][3] = 1;
	G->arc[2][8] = 1;

	//D-E D-G D-H D-I
	G->arc[3][4] = 1;
	G->arc[3][6] = 1;
	G->arc[3][7] = 1;
	G->arc[3][8] = 1;

	//E-F E-H
	G->arc[4][5] = 1;
	G->arc[4][7] = 1;

	//F-G
	G->arc[5][6] = 1;
	G->arc[6][7] = 1;

	//G-H
	G->arc[6][7] = 1;

	//无向图，所以要对称赋值
	for (int i = 0; i < G->vertex_num; i++) {
		for (int j = 0; j < G->vertex_num; j++) {
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

//广度优先
void bfs(Mat_Grph G)
{
	int i = 0;
	visited[i] = 1;
	printf("%c\n", G.vertex[i]);
	queue[rear] = i;
	rear++;
	//数组模拟队列，front指向队头，rear指向队尾，初始时都为0，每次入队时rear加1，每次出队时front加1，当front和rear相等时说明队列为空
	while (front != rear) {
		i = queue[front];
		front++;
		//遍历与i相连的顶点，如果有边且没有被访问过，就访问它并入队
		for (int j = 0; j < G.vertex_num; j++) {
			if (G.arc[i][j] == 1 && visited[j] == 0) {
				visited[j] = 1;
				printf("%c\n", G.vertex[j]);
				queue[rear] = j;
				rear++;
			}
		}
	}
}


//深度优先
void dfs(Mat_Grph G, int i) {
	visited[i] = 1;
	printf("%c\n", G.vertex[i]);
	for (int j = 0; j < G.vertex_num; j++) {
		//A-I依次寻找与他相连的两个顶点而且是不被访问过的（避免重复输出），然后递归调用
		if (G.arc[i][j] == 1 && visited[j] == 0) {
			dfs(G, j);
		}
	}
}

int main() {
	Mat_Grph G;
	create_graph(&G);
	for (int i = 0; i < G.vertex_num; i++) {
		visited[i] = 0;
	}

	//dfs(G, 0);
	bfs(G);

	system("pause");
	return 0;
}