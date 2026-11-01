/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int a[10][10], visited[10], n;

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (a[v][i] && !visited[i])
            DFS(i);
}

void BFS(int s) {
    int q[10], front = 0, rear = 0;
    for (int i = 0; i < n; i++) visited[i] = 0;

    q[rear++] = s;
    visited[s] = 1;

    while (front < rear) {
        int v = q[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++)
            if (a[v][i] && !visited[i]) {
                q[rear++] = i;
                visited[i] = 1;
            }
    }
}

int main() {
    int e, u, v, s, key;

    printf("Enter nodes and edges: ");
    scanf("%d%d", &n, &e);

    printf("Enter edges:\n");
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }

    printf("Enter start node and file to search: ");
    scanf("%d%d", &s, &key);

    printf("BFS: ");
    BFS(s);

    printf("\nDFS: ");
    for (int i = 0; i < n; i++) visited[i] = 0;
    DFS(s);

    printf("\n");

    if (key >= 0 && key < n && visited[key])
        printf("File Found\n");
    else
        printf("File Not Found\n");

    return 0;
}
