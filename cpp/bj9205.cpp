#include <stdio.h>
#include <math.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<bool> check;
vector<pair<int, int>> songdo;

bool dist(int x1, int y1, int x2, int y2){
    if((abs(x1 - x2) + abs(y1 - y2) <= 1000))
        return true;
    else
        return false;
}

int main(void){
    int testCase, n;
    scanf("%d", &testCase);
    for(int t = 0; t < testCase; t++){
        scanf("%d", &n);
        check = vector<bool>(n + 2, false);
        songdo = vector<pair<int, int>>(n + 2, make_pair(0, 0));
        for (int i = 0; i < n + 2; i++){
            scanf("%d", &songdo[i].first);
            scanf("%d", &songdo[i].second);
        }
        queue<int> q;
        q.push(0);
        check[0] = true;
 
        bool find = false;
        while (!q.empty()){
            int now = q.front();
            q.pop();
 
            if (songdo[now].first == songdo[n + 1].first && songdo[now].second == songdo[n + 1].second){
                find = true;
                break;
            }
 
            for (int i = 1; i < n + 2; i++){
                if (!check[i] && dist(songdo[now].first, songdo[now].second, songdo[i].first, songdo[i].second)){
                    q.push(i);
                    check[i] = true;
                }
            }
        }
        if(find == true)
            printf("happy\n");
        else
            printf("sad\n");
        
    }
    return 0;
}