#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int N = 0, M = 0;
vector<pair<int, int>> house;
vector<pair<int, int>> store;

int best = 987654321;
int housenum = 0;
int list[14];

void get_sum(){
    int dist_min;

    int sum = 0;
    for(int i = 0; i < housenum; i++){
        dist_min = 987654321;
        for(int j = 0; j < store.size(); j++){
            if(list[j] == 1){
                dist_min = min((abs(house[i].first-store[j].first)+abs(house[i].second-store[j].second)), dist_min);
            }
        }
        sum += dist_min;
    }
    
    best = min(best, sum);

    return;
}

void chicken(int cnt, int idx){
    if(idx > store.size())
        return;

    if(cnt == M){
        get_sum();
        return;
    }

    list[idx] = 1;
    chicken(cnt+1, idx+1);
    list[idx] = 0;
    chicken(cnt, idx+1);
}

int main(void){
    cin >> N >> M;

    int temp = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf(" %d", &temp);
            if(temp == 1)
                house.push_back(make_pair(i,j));
            else if(temp == 2)
                store.push_back(make_pair(i,j));
        }
    }
    
    housenum = house.size();

    chicken(0, 0);
    printf("%d\n", best);

    return 0;
}