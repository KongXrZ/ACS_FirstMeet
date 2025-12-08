#include <stdio.h>
#include <limits.h>
#define MAX 1000
#define INF 1000000000

int N, M;
int G[MAX][MAX];   

//BFS SPANNING TREE
void bfs_spanning(int start) {
    int visited[MAX] = {0};
    int parent[MAX];
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < N; i++) parent[i] = -1;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nSpanning Tree (BFS) starting from %d:\n", start);

    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < N; v++) {
            if (G[u][v] != 0 && !visited[v]) {
                visited[v] = 1;
                parent[v] = u;
                queue[rear++] = v;
                printf("%d - %d (weight %d)\n", u, v, G[u][v]);
            }
        }
    }
}

//DFS SPANNING TREE 
void dfs_rec(int u, int visited[], int parent[]) {
    visited[u] = 1;
    for (int v = 0; v < N; v++) {
        if (G[u][v] != 0 && !visited[v]) {
            parent[v] = u;
            printf("%d - %d (weight %d)\n", u, v, G[u][v]);
            dfs_rec(v, visited, parent);
        }
    }
}

void dfs_spanning(int start) {
    int visited[MAX] = {0};
    int parent[MAX];
    for (int i = 0; i < N; i++) parent[i] = -1;

    printf("\nSpanning Tree (DFS) starting from %d:\n", start);
    dfs_rec(start, visited, parent);
}

//DIJKSTRA
void dijkstra(int start, int target) {
    int dist[MAX], visited[MAX], parent[MAX];

    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < N; i++) {
        int u = -1;

        // เลือก node ที่ dist น้อยที่สุดที่ยังไม่ visited
        for (int j = 0; j < N; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if (dist[u] == INF) break;

        visited[u] = 1;

        for (int v = 0; v < N; v++) {
            if (G[u][v] > 0 && dist[u] + G[u][v] < dist[v]) {
                dist[v] = dist[u] + G[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nDijkstra shortest path %d -> %d:\n", start, target);

    if (dist[target] == INF) {
        printf("No path.\n");
        return;
    }

    printf("Distance = %d\nPath: ", dist[target]);

    // reconstruct path
    int path[MAX], len = 0, cur = target;
    while (cur != -1) {
        path[len++] = cur;
        cur = parent[cur];
    }
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) printf(" -> ");
    }
    printf("\n");
}

/************************** PRIM MST ****************************/

void prim(int start) {
    int key[MAX], parent[MAX], in_mst[MAX];

    for (int i = 0; i < N; i++) {
        key[i] = INF;
        parent[i] = -1;
        in_mst[i] = 0;
    }

    key[start] = 0;

    for (int i = 0; i < N; i++) {
        int u = -1;

        for (int j = 0; j < N; j++)
            if (!in_mst[j] && (u == -1 || key[j] < key[u]))
                u = j;

        in_mst[u] = 1;

        for (int v = 0; v < N; v++) {
            if (G[u][v] != 0 && !in_mst[v] && G[u][v] < key[v]) {
                key[v] = G[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nPrim MST:\n");
    int total = 0;

    for (int i = 0; i < N; i++) {
        if (parent[i] != -1) {
            printf("%d - %d (weight %d)\n", parent[i], i, G[parent[i]][i]);
            total += G[parent[i]][i];
        }
    }
    printf("Total weight = %d\n", total);
}

//Kruskal MST

// struct ของ edge
typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX * MAX];
int edgeCount = 0;

int parentUF[MAX];

int find(int x) {
    if (parentUF[x] == x) return x;
    return parentUF[x] = find(parentUF[x]);
}

int unionSet(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    parentUF[b] = a;
    return 1;
}

void kruskal() {
    // เก็บ edges
    edgeCount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (G[i][j] != 0) {
                edges[edgeCount++] = (Edge){i, j, G[i][j]};
            }
        }
    }

    // sort edges แบบง่าย (bubble sort)
    for (int i = 0; i < edgeCount; i++) {
        for (int j = i+1; j < edgeCount; j++) {
            if (edges[j].w < edges[i].w) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    // init union-find
    for (int i = 0; i < N; i++) parentUF[i] = i;

    printf("\nKruskal MST:\n");
    int total = 0;

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (unionSet(u, v)) {
            printf("%d - %d (weight %d)\n", u, v, w);
            total += w;
        }
    }

    printf("Total weight = %d\n", total);
}


int main() {
    printf("Enter N M: ");
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            G[i][j] = 0;

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u][v] = G[v][u] = w;
    }

    int s, t;
    printf("Enter source and target: ");
    scanf("%d %d", &s, &t);

    int mode;
    printf("Choose spanning tree (1=DFS, 2=BFS): ");
    scanf("%d", &mode);

    if (mode == 1) dfs_spanning(s);
    else           bfs_spanning(s);

    dijkstra(s, t);
    prim(s);
    kruskal();

    return 0;
}
