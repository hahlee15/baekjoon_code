#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int n, m, start;
int mat[1001][10001];
bool visit[1001];
queue<int> q;

void dfs(int s){
    printf("%d ", s);
    visit[s] = true;
    for(int i = 1; i <= n; i++){
        if(mat[s][i] == 1 && !visit[i]){
            dfs(i);
        }
    }
}

void bfs(int s){
    q.push(s);

    while(!q.empty()){
        s = q.front();
        q.pop();
        visit[s] = true;
        printf("%d ", s);
        for(int i = 1; i <= n; i++){
            if(mat[s][i] == 1 && !visit[i]){
                q.push(i);
                visit[i] = true;
            }
        }
    }
}

int main(){
    cin >> n >> m >> start;

    int row = 0, col = 0;
    for(int i = 0; i < m; i++){
        row = 0, col = 0;
        cin >> row >> col;

        mat[row][col] = 1;
        mat[col][row] = 1;
    }

    dfs(start);
    printf("\n");
    for(int i = 1; i <= n; i++)
        visit[i] = false;
    bfs(start);

    return 0;
}