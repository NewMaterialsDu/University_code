#include <stdio.h>

#define ROWS 10
#define COLS 10
#define MAX_QUEUE 100

// 点结构体
typedef struct {
    int x, y;
} Point;

// 队列结构体（循环队列）
typedef struct {
    Point data[MAX_QUEUE];
    int front, rear;
} Queue;

// 初始化队列
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

// 判断队列是否为空
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// 入队
void enqueue(Queue* q, Point p) {
    // 队列满则忽略
    if ((q->rear + 1) % MAX_QUEUE == q->front) { 
        return;
    } 
    q->data[q->rear] = p;
    q->rear = (q->rear + 1) % MAX_QUEUE;
}

// 出队
Point dequeue(Queue* q) {
    Point p;
    p.x = -1;
    p.y = -1;
    if (isEmpty(q)) {
        return p;
    }
    p = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE;
    return p;
}

// 四个方向：上、下、左、右
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

//bfs  广度优先
int bfs(int maze[ROWS][COLS], Point start, Point end, Point parent[ROWS][COLS]) {
    //走过的位置填1
    int visited[ROWS][COLS];
    int i, j;
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
        {
            visited[i][j] = 0;
        }
    Queue q;
    initQueue(&q);
    enqueue(&q, start);
    visited[start.x][start.y] = 1;

    while (!isEmpty(&q)) {
        //出队一个点，查看四周，如是终点直接返回1，代表找到终点
        Point cur = dequeue(&q);
        if (cur.x == end.x && cur.y == end.y) {
            return 1;
        }
        for (i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            //在迷宫内，并且未走过，而且迷宫中的这个位置是路
            if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS &&
                !visited[nx][ny] && maze[nx][ny] == 0) {
                visited[nx][ny] = 1;
                //将上一步路存进去
                parent[nx][ny] = cur;
                //把当前可以走的点入队
                Point next;
                next.x = nx;
                next.y = ny;
                enqueue(&q, next);
            }
        }
    }
    return 0;
}

//DFS
int dfs_visited[ROWS][COLS];
//同bfs，存放上一个节点
Point dfs_parent[ROWS][COLS];

int dfs(int maze[ROWS][COLS], Point cur, Point end) {
    if (cur.x == end.x && cur.y == end.y) return 1;
    //走过的填1
    dfs_visited[cur.x][cur.y] = 1;
    for (int i = 0; i < 4; i++) {
        //查看四周
        int nx = cur.x + dx[i];
        int ny = cur.y + dy[i];
        //同bfs
        if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS &&
            !dfs_visited[nx][ny] && maze[nx][ny] == 0) {
            dfs_parent[nx][ny] = cur;
            Point next;
            next.x = nx;
            next.y = ny;
            //使用递归，一直走一条路，直到碰壁或者找到终点
            if (dfs(maze, next, end))
                return 1;
        }
    }
    return 0;
}

//从parent数组还原路径
void getPath(Point parent[ROWS][COLS], Point start, Point end, Point path[], int* len) {
    Point cur = end;
    *len = 0;
    while (!(cur.x == start.x && cur.y == start.y)) {
        //把一个个点放进path，到起点前结束
        path[*len] = cur;
        (*len)++;
        cur = parent[cur.x][cur.y];
    }
    path[*len] = start;
    (*len)++;
    // 把path路径弄正
    for (int i = 0; i < *len / 2; i++) {
        Point temp = path[i];
        path[i] = path[*len - 1 - i];
        path[*len - 1 - i] = temp;
    }
}

//打印迷宫并用'*'标记路径 
void printMazeWithPath(int maze[ROWS][COLS], Point path[], int len) {
    int mark[ROWS][COLS];
    int i, j;
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++) {
            mark[i][j] = 0;
        }
    //传入路径
    for (i = 0; i < len; i++) {
        mark[path[i].x][path[i].y] = 1;
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (mark[i][j])
                printf("* ");
            else if (maze[i][j])
                printf("# ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

//打印原始迷宫
void printMaze(int maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

//打印坐标序列
void printPathCoords(Point path[], int len) {
    for (int i = 0; i < len; i++) {
        printf("(%d,%d) ", path[i].x, path[i].y);
        if (i < len - 1) printf("-> ");
    }
    printf("\n");
}


int main() {
    int maze[ROWS][COLS] = {
        {1,1,1,1,1,1,1,1,1,1},
        {0,0,0,1,0,0,0,1,0,1},
        {1,1,0,1,0,1,0,1,0,1},
        {1,0,0,1,0,1,0,1,0,1},
        {1,0,1,1,0,1,0,1,0,1},
        {1,0,0,0,0,1,0,0,0,1},
        {1,1,1,1,0,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,1,0,0},
        {1,1,1,1,1,1,1,1,1,1}
    };

    //出入口
    Point start, end;
    start.x = 1; start.y = 0;
    end.x = 8;   end.y = 9;

    printf("原始迷宫（#代表墙）：\n");
    printMaze(maze);
    printf("\n");

    // BFS 
    //这是点数组，里面存的点表示当前显示点的上一步
    Point bfs_parent[ROWS][COLS];
    int i, j;
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++) {
            bfs_parent[i][j].x = 0;
            bfs_parent[i][j].y = 0;
        }

    if (bfs(maze, start, end, bfs_parent)) {
        Point bfs_path[MAX_QUEUE];
        int bfs_len;
        getPath(bfs_parent, start, end, bfs_path, &bfs_len);
        printf("BFS 广度路径（*标记路径）：\n");
        printMazeWithPath(maze, bfs_path, bfs_len);
        printf("步数（包含起终点）: %d\n", bfs_len);
        printf("坐标: ");
        printPathCoords(bfs_path, bfs_len);
    }
    else {
        printf("BFS 未找到路径！\n");
    }

    // DFS
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++) {
            dfs_visited[i][j] = 0;
            dfs_parent[i][j].x = 0;
            dfs_parent[i][j].y = 0;
        }

    if (dfs(maze, start, end)) {
        Point dfs_path[MAX_QUEUE];
        int dfs_len;
        getPath(dfs_parent, start, end, dfs_path, &dfs_len);
        printf("\nDFS路径（*标记路径）：\n");
        printMazeWithPath(maze, dfs_path, dfs_len);
        printf("步数（包含起终点）: %d\n", dfs_len);
        printf("坐标: ");
        printPathCoords(dfs_path, dfs_len);
    }
    else {
        printf("DFS 未找到路径！\n");
    }

    return 0;
}