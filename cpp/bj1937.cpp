#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<vector<int>> forest;
vector<vector<int>> visit;
int dirX[4] = { 0, 1, 0, -1 };
int dirY[4] = { 1, 0, -1, 0 };

int n = 0;
int day = 0;

void findRoad(int x, int y){
    int nextX, nextY;
    int count = 0;
    for(int i = 0; i < 4; i++){
        nextX = x + dirX[i];
        nextY = y + dirY[i];

        if(nextX>=n || nextX<0 || nextY>=n || nextY<0)
            continue;
        else{
            if(forest[nextX][nextY] > forest[x][y]){    
                if(visit[nextX][nextY] == 0)
                    findRoad(nextX, nextY);

                if(count < visit[nextX][nextY])
                    count = visit[nextX][nextY];
            }
        }
    }
    visit[x][y] = count + 1;
    if(day < visit[x][y])
        day = visit[x][y];
}

int main(void){
    scanf("%d", &n);
    forest.assign(n, vector<int> (n, 0));
    visit.assign(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &forest[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j ++){
            if(visit[i][j] == 0)
                findRoad(i, j);
        }
    }
    printf("%d\n", day);
    return 0;
}