#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N = 0;
int hwadan[10][10];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool flower[10][10] = {{false, false}};

int best = 987654321;

void makeFlower(int cnt, int sum){
    if(cnt == 3){
        if(best > sum)
            best = sum;
        return;
    }

    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < N-1; j++){
            int leaf = 0;
            if(flower[i][j] == false){
                for(int k = 0; k < 4; k++){
                    int nx = i + dir[k][0];
                    int ny = j + dir[k][1];
                    if(flower[nx][ny] == false){
                        leaf+=1;
                        if(leaf == 4)
                            break;
                    }
                }

                if(leaf == 4){
                    flower[i][j] = true;
                    sum += hwadan[i][j];
                    for(int a = 0; a < 4; a++){
                        int fx = i + dir[a][0];
                        int fy = j + dir[a][1];

                        flower[fx][fy] = true;
                        sum += hwadan[fx][fy];
                    }

                    makeFlower(cnt+1, sum);

                    flower[i][j] = false;
                    sum -= hwadan[i][j];
                    for(int l = 0; l < 4; l++){
                        int nx = i + dir[l][0];
                        int ny = j + dir[l][1];

                        flower[nx][ny] = false;
                        sum -= hwadan[nx][ny];
                    }
                    leaf = 0;
                }
            }
        }
    }
}

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf(" %d", &hwadan[i][j]);
        }
    }

    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < N-1; j++){
            int firstsum = 0;
            flower[i][j] = true;
            firstsum += hwadan[i][j];
            for(int k = 0; k < 4; k++){
                int nx = i + dir[k][0];
                int ny = j + dir[k][1];
                
                flower[nx][ny] = true;
                firstsum += hwadan[nx][ny];
            }

            makeFlower(1, firstsum);

            flower[i][j] = false;
            for(int l = 0; l < 4; l++){
                int nx = i + dir[l][0];
                int ny = j + dir[l][1];

                flower[nx][ny] = false;
            }
        }
    }

    printf("%d\n", best);
    
    return 0;
}