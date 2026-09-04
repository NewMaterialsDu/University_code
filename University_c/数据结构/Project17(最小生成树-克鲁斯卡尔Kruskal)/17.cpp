#include<stdio.h>
#include<stdlib.h>
#include<iostream>

//图生成最小生成树

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x7fffffff

typedef struct {
	VertexType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Grph;

typedef struct {
	int beigin;
	int end;
	int weight;
}Edge;

void create_graph(Mat_Grph* G) {
	G->vertex_num = 9;
	G->edge_num = 15;

	//手动输入顶点信息
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';

	//初始化邻接矩阵
	for (int i = 0; i < G->vertex_num; i++) {
		for (int j = 0; j < G->vertex_num; j++) {
			if (i == j) {
				//自己到自己的距离为0
				G->arc[i][j] = 0;
			}
			else {
				//其他点之间路径初始距离为无穷大
				G->arc[i][j] = MAX;
			}
		}
	}

	//手动输入边的信息
	//A-B A-F
	G->arc[0][1] = 10;
	G->arc[0][5] = 11;

	//B-C B-G B-I
	G->arc[1][2] = 18;
	G->arc[1][6] = 16;
	G->arc[1][8] = 12;

	//C-D C-I
	G->arc[2][3] = 22;
	G->arc[2][8] = 8;

	//D-E D-G D-H D-I
	G->arc[3][4] = 20;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][8] = 21;

	//E-F E-H
	G->arc[4][5] = 26;
	G->arc[4][7] = 7;

	//F-G
	G->arc[5][6] = 17;

	//G-H
	G->arc[6][7] = 19;

	//无向图，邻接矩阵是对称的
	for (int i = 0; i < G->vertex_num; i++) {
		for (int j = 0; j < G->vertex_num; j++) {
			G->arc[j][i] = G->arc[i][j];
		}
	}

}

void swap(Edge* edges, int i, int j) {
	//分别交换结构体中的三个值
	int temp;
	temp = edges[i].beigin;
	edges[i].beigin = edges[j].beigin;
	edges[j].beigin = temp;

	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;

	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;

}

void sortEdges(Edge edges[], int edge_num)
{
	//比较大小然后交换位置，以此达到以权值升降序的排列（此处是升序）
	for (int i = 0; i < edge_num; i++) {
		for (int j = i + 1; j < edge_num; j++) {
			if (edges[i].weight > edges[j].weight) {
				//这里不能直接调换位置，是一个结构体，有三个值
				swap(edges, i, j);
			}
		}
	}
}

int find(int* prent, int index) {
	//初始化后为0，不可能大于0，所以不会进去
	//直到第二次读取到prent数组里的才会进入
	//第二次读取进去之后，写入的值再返回所表达的也是两个顶点连接（但是中间隔了一个顶点，第一次写入的值就是隔着的那个顶点）
	while (prent[index] > 0) {
		index = prent[index];
	}
	//返回写入的值代表一个顶点，下标也代表一个顶点，以此表达两个顶点连接在一起
	return index;
}

//克鲁斯卡尔（Kruskal）算法
void kruskal(Mat_Grph G) {
	//创建一个数组存放边
	Edge edges[MAXEDGE];
	int  k = 0;

	for (int i = 0; i < G.vertex_num; i++) {
		for (int j = i + 1; j < G.vertex_num; j++) {
			if (G.arc[i][j] < MAX) {
				edges[k].beigin = i;
				edges[k].end = j;
				edges[k].weight = G.arc[i][j];
				k++;
			}
		}
	}

	//边的权值大小排序
	sortEdges(edges, G.edge_num);
	//用来记录顶点之间的关系
	int parent[MAXSIZE];
	//初始化
	for (int i = 0; i < G.edge_num;i++) {
		parent[i] = 0;
	}

	int n, m;
	for (int i = 0; i < G.edge_num; i++) {
		n = find(parent, edges[i].beigin);//第一次进去是4
		m = find(parent, edges[i].end);//第一次进去是7
		//n=m时，说明这两个顶点是相连的，不能再连接
		if (n != m) {
			//4代表E，7代表H，刚好是权值最小的边E-H
			parent[n] = m;
			//printf("(%d,%d)%d\n",edges[i].beigin,edges[i].end,edges[i].weigin);//输出代表顶点的数字
			printf("(%c,%c)%d\n", G.vertex[edges[i].beigin],G.vertex[edges[i].end],edges[i].weight);//输出代表顶点的字母
		}
	}
}

int main() {

	Mat_Grph G;
	create_graph(&G);
	kruskal(G);




	system("pause");
	return 0;
}