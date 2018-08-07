#include <iostream>
#include <stdio.h>

using namespace std;
int dp[101][100][2];

int main(void){
    int testC = 0;
    int n = 0, k = 0;
    scanf("%d", &testC);

    dp[1][0][0] = 1;
    dp[1][0][1] = 1;

    for(int k = 0; k < 100; k++){
        for(int n = 2; n <= 100; n++){
            if (k == 0) {
                dp[n][k][1] += dp[n - 1][k][0];
            } else {
                dp[n][k][1] += dp[n - 1][k][0] + dp[n - 1][k - 1][1];
            }
            dp[n][k][0] += dp[n - 1][k][0] + dp[n - 1][k][1];
        }
    }

    while(testC--){
        scanf("%d", &n);
        scanf("%d", &k);
        printf("%d\n",dp[n][k][0] + dp[n][k][1]);
    }
    return 0;
}