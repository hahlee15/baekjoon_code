#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int N = 0, M = 0, H = 0, zero_count = 0;
int box[100][100][100];
int dir[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, 1}, {0, 0, -1}};
queue<pair<pair<int, int>, int>> tomato;
queue<int> tomatoH;

bool isInbound(int x, int y, int h){
    if((x >= 0 && x < N) && (y >= 0 && y < M) && (h >= 0 && h < H))
        return true;
    else
        return false;
}

int howDays(){
    int cx = 0, cy = 0, ch = 0, cnt = 0;
    while(!tomato.empty()){
        pair<pair<int, int>, int> temp = tomato.front();
        tomato.pop();
        cx = temp.first.first;
        cy = temp.first.second;
        ch = tomatoH.front();
        tomatoH.pop();
        cnt = temp.second;

        for(int i = 0; i < 6; i++){    
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];
            int nh = ch + dir[i][2];

            if(isInbound(nx, ny, nh)){
                if(box[nx][ny][nh] == 0){
                    box[nx][ny][nh] = 1;
                    zero_count--;
                    tomato.push(make_pair(make_pair(nx,ny),cnt+1));
                    tomatoH.push(nh);
                }
            }
        }
    }
    return cnt;
}


int main(void){
    cin >> M >> N >> H;
    for(int k = 0; k < H; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                scanf(" %d", &box[i][j][k]);
                if(box[i][j][k] == 1){
                    tomato.push(make_pair(make_pair(i,j),0));
                    tomatoH.push(k);
                }
                else if(box[i][j][k] == 0)
                    zero_count++;
            }
        }
    }

    int result = howDays();
    if(zero_count != 0){
        printf("-1\n");
        return 0;
    }

    printf("%d\n", result);
    return 0;
}