#include <iostream>
#include <algorithm>

using namespace std;

int N;
int map[25][25];
int danji[315];

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //상, 하, 좌, 우

int dnum = 1;
int i = 0, j = 0;

int nx = 0, ny = 0;
void Numbering(int x, int y){
    danji[dnum]++;
    for(int i = 0; i < 4; i++){
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        if((nx >= 0 && nx < N) && (ny >= 0 && ny < N)){
            if(map[nx][ny] == 1){
                map[nx][ny] = dnum;
                Numbering(nx, ny);
            }
        }
    }
}

int main(void){
    scanf("%d", &N);

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(map[i][j] == 1){
                dnum++;
                map[i][j] = dnum;
                Numbering(i, j);
            }
        }
    }

    printf("%d\n", dnum-1);
    sort(danji, danji + (dnum + 1));
    for(i = 2; i <= dnum; i++){
        printf("%d\n", danji[i]);
    }

    return 0;
}