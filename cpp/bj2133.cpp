#include <stdio.h>

int dp[91][9];
int N = 0;

int tail(int index, int bit){
    if(index == 3*N && bit == 0){
            return 1;
    }
    else if(index > 3*N) 
        return 0;

    int& ret = dp[index][bit];
    if(ret != -1)
        return ret;

    if(bit % 2 == 1)
        dp[index][bit] = tail(index + 1, (bit >> 1));
    else{
        dp[index][bit] = tail(index + 1, (bit >> 1) + 4);
        
        if((index % 3 != 2) && (bit & (1<<1)) == 0)
            dp[index][bit] += tail(index + 2, (bit >> 2));
    }
    return dp[index][bit];
}

int main(void){
    scanf("%d", &N);
    if(N % 2 != 0){
        printf("0\n");
        return 0;
    }
    else{
        for(int i = 0; i < 91; i++){
            for(int j = 0; j < 9; j++){
                dp[i][j] = -1;
            }
        }
        int result = tail(0, 0);
        printf("%d\n", result);
    }

    return 0;
}