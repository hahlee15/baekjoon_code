#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

vector<int> room;

int main(void){
    int testC = 0;
    int N = 0;
    scanf("%d", &testC);
    while(testC--){
        scanf("%d", &N);
        room.assign(N+1, 1);
        for(int i = 2; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(j % i == 0){
                    if(room[j] == 0)
                        room[j] = 1;
                    else
                        room[j] = 0;
                }
                else
                    continue;
            }
        }
        int count = 0;
        for(int i = 1; i <= N; i++){
            if(room[i] == 1)
                count++;
        }
        printf("%d\n", count);
    }
}