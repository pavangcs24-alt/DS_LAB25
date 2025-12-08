#include <stdio.h>
#define MAX 20
int stack[MAX];
int top = -1;
int visited[MAX];

void push(int v){
    if(top == MAX - 1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = v;
}

int pop(){
    if(top == -1)
        return -1;
    return stack[top--];
}

void DFS(int adj[MAX][MAX], int n, int start){
    int i, current;

    for(i = 0; i < n; i++)
        visited[i] = 0;

    push(start);
    visited[start] = 1;

    printf("DFS Traversal: ");

    while(top != -1){
        current = pop();
        printf("%d ", current);

        for(i = n - 1; i >= 0; i--){
            if(adj[current][i] == 1 && visited[i] == 0){
                push(i);
                visited[i] = 1;
            }
        }
    }
}

int main(){
    int adj[MAX][MAX];
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    DFS(adj, n, start);

    return 0;
}
