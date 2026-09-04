#include<stdio.h>
#include<stdlib.h>
#include<iostream>

//最短路径

typedef int VertexType;
typedef int EdgeType;
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000

typedef struct {
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;

void createGraph(Mat_Graph* G) {
	G->vertex_num = 9;
	G->edge_num = 16;
	
	//这里保存的是0-8，没有字母（为了方便）
	for (int i = 0; i < G->vertex_num; i++) {
		G->vertex[i] = i;
	}

	//把自己和自己的距离设置为0，其他的距离设置为MAX
	for (int i = 0; i < G->vertex_num; i++) {
		for (int j = 0; j < G->vertex_num; j++) {
			if (i == j) {
				G->arc[i][j] = 0;
			}
			else {
				G->arc[i][j] = MAX;
			}
		}
	}

	//一个个手动添加边和权重
	G->arc[0][1] = 1;
	G->arc[0][2] = 5;

	G->arc[1][2] = 3;
	G->arc[1][3] = 7;
	G->arc[1][4] = 5;

	G->arc[2][4] = 1;
	G->arc[2][5] = 7;

	G->arc[3][4] = 2;
	G->arc[3][6] = 3;

	G->arc[4][5] = 3;
	G->arc[4][6] = 6;
	G->arc[4][7] = 9;

	G->arc[5][7] = 5;

	G->arc[6][7] = 2;
	G->arc[6][8] = 7;

	G->arc[7][8] = 4;

	//无向图，所以对称位置也要设置
	for (int i = 0; i < G->vertex_num; i++) {
		for (int j = i; j < G->vertex_num;j++) {
			G->arc[j][i] = G->arc[i][j];
		}
	}

}

//返回下一次要观察哪个顶点
int choose(int distance[], int found[], int vertex_num) {
	int min = MAX;
	int minPos = -1;
	for (int i = 0; i < vertex_num; i++) {
		if (distance[i] < min && found[i] == 0) {
			min = distance[i];
			minPos = i;
		}
	}
	return minPos;
}

//迪杰斯特拉（Dijkstra）
void dijkstra(Mat_Graph G,int begin) {
	int found[MAXSIZE];//顶点是否已经走过对应0，1
	int path[MAXSIZE];//路径
	int distance[MAXSIZE];//begin到每个顶点的最短距离
	for (int i = 0; i < G.vertex_num; i++) {
		//初始化
		found[i] = 0;
		path[i] = -1;
		//begin到每个顶点的距离，初始为邻接矩阵中的值
		distance[i] = G.arc[begin][i];
	}

	found[begin] = 1;
	distance[begin] = 0;

	int next;//下一次要观察哪个顶点
	for (int i = 1;i<G.vertex_num;i++) {
		//1
		next = choose(distance, found, G.vertex_num);
		//printf("%d ", next);
		//代表这个顶点已经访问过了
		found[next] = 1;
		for (int j = 0; j < G.vertex_num; j++) {
			if (found[j] == 0) {
				//更新distance数组，这个数组指的是begin到其他所有顶点的最短距离
				if (distance[next] + G.arc[next][j]<distance[j]) {
					distance[j] = distance[next] + G.arc[next][j];
					//找到离V2最近的顶点了，是V1，所以下标为2的path赋值为1.代表离V2最近的顶点为V1
					path[j] = next;
				}
			}
		}

	}

	//一个循环打印
	for (int i = 1; i < G.vertex_num;i++) {
		printf("V0 -> V%d\n", i, distance[i]);
		int j = i;
		printf("V%d <- ", i);
		while (path[j] != -1) {
			printf("V%d <- ", path[j]);
			j = path[j];
		}
		printf("V0\n");
	}




}

int main() {
	Mat_Graph G;
	createGraph(&G);
	int begin = 0;
	dijkstra(G, begin);


	system("pause");
	return 0;
}