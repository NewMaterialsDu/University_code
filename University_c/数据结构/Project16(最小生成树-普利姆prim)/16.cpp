#include<stdio.h>
#include<stdlib.h>
#include<iostream>

//图生成最小生成树

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100
//int（4个字节）类型的最大值，16进制表示
//表示无穷大，表示两点之间没有路径
#define MAX 0xfffffff

//邻接矩阵表示图
typedef struct {
	//顶点信息
	VertexType vertex[MAXSIZE];
	//边的信息(二维数组中两个顶点相交的地方的值表示边的权值)
	EdgeType arc[MAXSIZE][MAXSIZE];
	//顶点数和边数
	int vertex_num;
	int edge_num;
}Mat_Grph;

void create_graph(Mat_Grph *G) {
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
		for (int j = 0; j < G->vertex_num;j++) {
			G->arc[j][i] = G->arc[i][j];
		}
	}

}

//普利姆算法
void prim(Mat_Grph* G) {

	//作为下标使用
	int i, j, k;
	//min表示候选边中权值最小的边的权值
	int min;
	int weight[MAXSIZE];//侯选边中权值最小的边的权值，weight某点与下标对应点的权重
	int vex_index[MAXSIZE];//值表示出发点，下标表示到达点

	//先从第一个顶点开始
	weight[0] = 0;//vex_index某点与下标对应点的权重
	vex_index[0] = 0;

	for (i = 1; i < G->vertex_num; i++) {
		
		weight[i] = G->arc[0][i];
		vex_index[i] = 0;
	}

	for (int i = 1; i < G->vertex_num; i++) {
		//每次循环都要找到候选边中权值最小的边，所以先把min设置为无穷大
		min = MAX;
		j = 0;
		k = 0;
		//找到候选边中权值最小的边与之相连
		while (j < G->vertex_num) {
			//0为最小，MAX为无穷大，weight[j]不为0且小于min，就找到了权值最小的侯选边，并赋值给min，k记录下标
			if (weight[j] != 0 && weight[j] < min) {
				min = weight[j];
				k = j;
			}
			j++;
		}
		//printf("(%d,%d)\n", vex_index[k], k);
		//这里的输出内容可以变成树的连接
		printf("(%c,%c)\n", G->vertex[vex_index[k]],G->vertex[k]);
		//新连接结点的权值设为0，表示已经加入生成树，不能再被选为侯选边
		weight[k] = 0;

		//找到新连接结点的待选路径
		for (j = 0; j < G->vertex_num;j++) {
			//与新结点可连接的边进行比较，有比weight小的就替换
			if (weight[j]!=0&&G->arc[k][j]<weight[j]) {
				weight[j] = G->arc[k][j];
				vex_index[j] = k;
			}
		}
	}

}

int main() {

	//Mat_Grph* G = (Mat_Grph*)malloc(sizeof(Mat_Grph));
	Mat_Grph G;
	create_graph(&G);
	prim(&G);


	

	system("pause");
	return 0;
}