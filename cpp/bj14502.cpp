#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
 
const int MAX = 8;

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int N, M;
int lab[MAX][MAX];
int temp[MAX][MAX];
int result; 

bool isInbound(int x, int y){
    if((x >= 0 && x < M) && (y >= 0 && y < N))
        return true;
    else
        return false;
}

void BFS(void){
    int afterSpread[MAX][MAX];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            afterSpread[i][j] = temp[i][j];
        }
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (afterSpread[i][j] == 2)
                q.push(make_pair(i, j));
        }
    }

    while (!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int nextY = y + dir[i][1];
            int nextX = x + dir[i][0];

            if(isInbound(nextX, nextY)){
                if (afterSpread[nextY][nextX] == 0){
                        afterSpread[nextY][nextX] = 2;
                        q.push(make_pair(nextY, nextX));
                }
            }
        }
    } 

    int empty = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
                if (afterSpread[i][j] == 0)
                        empty++;
        }
    }

    result = max(result, empty);
}

void makeWall(int cnt){
    if (cnt == 3){
        BFS();
        return;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (temp[i][j] == 0){
                temp[i][j] = 1;
                makeWall(cnt + 1);
                temp[i][j] = 0;
            }
        }
    }
}

int main(void){
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf(" %d", &lab[i][j]);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (lab[i][j] == 0){
                for (int k = 0; k < N; k++){
                    for (int l = 0; l < M; l++)
                            temp[k][l] = lab[k][l];
                }
                temp[i][j] = 1;
                makeWall(1);
                temp[i][j] = 0;
            }
        }
    }

    printf("%d\n", result);
    return 0;
}