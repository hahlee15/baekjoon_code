#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
const int INF = 987654321;

int n, m, k;
int u, v, b;
int s, e;
int dist[251][251];
vector<int> result;
vector<vector<int>> road;
vector<pair<int, int>> question;

void findRoad(){
        for(int k=1; k<n+1; k++){
            for(int i=1; i<n+1; i++){
                for(int j=1; j<n+1; j++){
                    if(dist[i][k] == INF || dist[k][j] == INF)
                        continue;
                    else
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        for(int i = 0; i < k; i++){
            int from = question[i].first;
            int to = question[i].second;
            if(from == to)
                result[i] = 0;
            else
                result[i] = dist[from][to];
        }
        return;
}

int main(void){
    scanf("%d", &n);
    scanf("%d", &m);
    road.assign(n+1, vector<int>(n+1, 2));

    for(int i = 0; i < m; i++){
        scanf("%d", &u);
        scanf("%d", &v);
        scanf("%d", &b);
        road[u][v] = b;
        if(b == 0){
            road[v][u] = -1;
        }
        else{
            road[v][u] = 1;
        }
    }
    
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++){
            if(i == j){
                dist[i][j] = 0;
            }

            if(road[i][j] == -1){
                dist[i][j] = 1;
            }
            else if(road[i][j] == 0){
                dist[i][j] = 0;
            }
            else if(road[i][j] == 1){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = INF;
            }
        }
    }

    scanf("%d", &k);
    question.assign(k, make_pair(0,0));
    result.assign(k, 0);
    for(int i = 0; i < k; i++){
        scanf("%d", &s);
        scanf("%d", &e);
        question[i] = make_pair(s, e);
    }

    findRoad();

    for(int i = 0; i < k; i++)
        printf("%d\n", result[i]);

    return 0;
}