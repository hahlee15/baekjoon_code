#include <iostream>
#include <stdio.h>

using namespace std;

int dp[3003][8][1001];
int chess[3003];
int N = 0, K = 0;

int maximum(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int domino(int index, int bit, int dom){
    if(dom == K)
        return 0;

    else if(index >= 3*N)
        return -987654321;

    int &ret = dp[index][bit][dom];
    if(ret != -987654321)
        return ret;
    
    if(bit % 2 == 1){ //자기 자신 칠해져있을 때
        dp[index][bit][dom] = domino(index + 1, (bit >> 1), dom);
    }
    else{
        dp[index][bit][dom] = domino(index + 1, (bit >> 1), dom);

        //세로
        if(index < (N - 1)*3){
            dp[index][bit][dom] = maximum(dp[index][bit][dom], chess[index] + chess[index+3] + domino(index + 1, (bit >> 1) | 4, dom + 1));
        }

        //가로
        if((index % 3 != 2) && (bit & (1<<1)) == 0){
            dp[index][bit][dom] = maximum(dp[index][bit][dom], chess[index] + chess[index+1] + domino(index + 2, (bit >> 2), dom + 1));
        }

    }
    return dp[index][bit][dom];
}

int main(void){
    cin >> N >> K;

    for(int i = 0; i < 3*N; i++)
        scanf("%d", &chess[i]);

    for(int i = 0; i < 3003; i++){
        for(int j = 0; j < 8; j++){
            for(int k = 0; k < 1001; k++)
                dp[i][j][k] = -987654321;
        }
    }

    int result = domino(0, 0, 0);
    printf("%d\n", result);
    
    return 0;
}