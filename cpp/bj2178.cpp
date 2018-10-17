#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int N = 0, M = 0;
int maze[100][100];
int visit[100][100];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int best = 987654321;
queue<pair<pair<int, int>, int>> q;

bool isInbound(int x, int y){
    if((x >= 0 && x < N) && (y >= 0 && y < M))
        return true;
    else
        return false;
}

void findMin(){
    pair<pair<int, int>, int> current = q.front();
    q.pop();
    int sx = current.first.first;
    int sy = current.first.second;
    int cnt = current.second;
    visit[sx][sy] = true;
    
    while(1){
        for(int i = 0; i < 4; i++){
            if(sx == N-1 && sy == M-1){
                if(cnt < best){
                    best = cnt;
                    return;
                }
            }
            int nx = sx + dir[i][0];
            int ny = sy + dir[i][1];
            pair<pair<int, int>, int> npair = make_pair(make_pair(nx, ny), cnt+1);

            if(isInbound(nx, ny)){
                if(!visit[nx][ny] && maze[nx][ny] == 1){
                    visit[nx][ny] = true;
                    q.push(npair);
                }
            }
        }
        pair<pair<int, int>, int> temp = q.front();
        q.pop();
        sx = temp.first.first;
        sy = temp.first.second;
        cnt = temp.second;
    }
}

int main(void){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &maze[i][j]);
        }
    }

    pair<pair<int, int>, int> start = make_pair(make_pair(0,0), 1);
    q.push(start);
    findMin();
    printf("%d\n", best);

    return 0;
}