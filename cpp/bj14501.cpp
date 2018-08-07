#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int t[N];
    int p[N];
    int dp[N];
    
    for(int i = 0; i < N; i++){
        scanf("%d", &t[i]);
        scanf("%d", &p[i]);
        dp[i] = p[i];
    }

    for (int i = 1; i < N; i++){
		for (int j = 0; j < i; j++){
            if(i - j >= t[j])
                dp[i] = std::max(dp[i], p[i] + dp[j]);
		}
	}

    int max = 0;
    for(int i = 0; i < N; i++){
        if(i + t[i] <= N){
            if(max < dp[i])
                max = dp[i];
        }
    }
    printf("%d\n", max);
    return 0;
}