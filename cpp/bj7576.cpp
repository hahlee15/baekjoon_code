#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int M = 0, N = 0, zero_count = 0;
int box[1000][1000];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pair<pair<int, int>, int>> tomato;

bool isInbound(int x, int y){
    if((x >= 0 && x < N) && (y >= 0 && y < M))
        return true;
    else
        return false;
}

int howDays(){
    int cnt = 0, cx = 0, cy = 0;
    while(!tomato.empty()){    
        pair<pair<int, int>, int> current = tomato.front();
        tomato.pop();
        cx = current.first.first;
        cy = current.first.second;
        cnt = current.second;

        for(int i = 0; i < 4; i++){
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];

            if(isInbound(nx, ny)){
                if(box[nx][ny] == 0){
                    box[nx][ny] = 1;
                    zero_count-=1;
                    tomato.push(make_pair(make_pair(nx, ny), cnt+1));
                }
            }
        }
    }
    return cnt;
}

int main(void){
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf(" %d", &box[i][j]);
            if(box[i][j] == 1){
                pair<pair<int, int>, int> temp = make_pair(make_pair(i,j), 0);
                tomato.push(temp);
            }
            else if(box[i][j] == 0)
                zero_count+=1;
        }
    }

    int result = howDays();

    if(zero_count != 0){
        printf("-1\n");
        return 0;
    }
    else
        printf("%d\n", result);

    return 0;
}