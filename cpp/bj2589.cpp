#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

int main(void){
    int row, col;
    scanf("%d", &row);
    scanf("%d", &col);
    char map[row][col];
    int dist[row][col];
    int i,j,m,n;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            cin >> map[i][j];
            dist[i][j] = 0;
        }
    }

    pair<int, int> temp;
    queue<pair<int, int>> tmpq;
    int max = 0;
    int countMax = 0;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(map[i][j] == 'L'){
                tmpq.push(make_pair(i, j));
                while(!tmpq.empty()){
                    temp = tmpq.front();
                    tmpq.pop();

                    if(temp.first - 1 >= 0 && dist[temp.first - 1][temp.second] == 0 && map[temp.first - 1][temp.second] == 'L'){
                        tmpq.push(make_pair(temp.first - 1, temp.second));
                        dist[temp.first - 1][temp.second] = dist[temp.first][temp.second] + 1;
                    }
                    if(temp.first + 1 < row && dist[temp.first + 1][temp.second] == 0 && map[temp.first + 1][temp.second] == 'L'){
                        tmpq.push(make_pair(temp.first + 1, temp.second));
                        dist[temp.first + 1][temp.second] = dist[temp.first][temp.second] + 1;
                    }
                    if(temp.second - 1 >= 0 && dist[temp.first][temp.second - 1] == 0 && map[temp.first][temp.second - 1] == 'L'){
                        tmpq.push(make_pair(temp.first, temp.second - 1));
                        dist[temp.first][temp.second - 1] = dist[temp.first][temp.second] + 1;
                    }
                    if(temp.second + 1 < col && dist[temp.first][temp.second + 1] == 0 && map[temp.first][temp.second + 1] == 'L'){
                        tmpq.push(make_pair(temp.first, temp.second + 1));
                        dist[temp.first][temp.second + 1] = dist[temp.first][temp.second] + 1;
                    }
                }
                max = 0;
                for(m = 0; m < row; m++){
                    for(n = 0; n < col; n++){
                        if(max < dist[m][n]){
                            max = dist[m][n];
                        }
                    }
                }
                for(m = 0; m < row; m++){
                    for(n = 0; n < col; n++){
                        dist[m][n] = 0;
                    }
                }
                if(countMax < max){
                    countMax = max;
                }
            }
            else{
                continue;
            }
        }
    }
    printf("%d\n", countMax);
    return 0;
}