#include <stdio.h>
#define num 1000000000

int main(void){
    int N;
    scanf("%d", &N);
    int dp[N+1][10];

    for(int i = 0; i <= 9; i++){    //한 자리 수일 때 0은 제외
        dp[1][i] = 1;
    }

    for(int i = 2; i <= N; i++){    //두 자리 이상일 때
        for(int j = 0; j < 10; j++){
            if(j == 0){
                dp[i][0] = dp[i-1][1] % num;
            }
            else if(j == 9){
                dp[i][9] = dp[i-1][8] % num;
            }
            else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % num;
            }
        }
    }
    
    int count = 0;
    for(int i = 1; i < 10; i++){
        count = (count + dp[N][i]) % num;
    }
    printf("%d\n", count);

    return 0;
}