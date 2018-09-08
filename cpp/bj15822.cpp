#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> wave1;
vector<int> wave2;
vector<vector<int>> dp;

int mini(int a, int b){
    int min = 0;
    if(a > b)
        min = b;

    else
        min = a;

    return min;
}

int main(void){
    int N = 0;
    scanf("%d", &N);

    wave1.assign(2001, 0);
    wave2.assign(2001, 0);
    dp.assign(2001, vector<int>(2001, 0));

    for(int i = 0; i < N; i++)
        cin >> wave1[i];

    for(int j = 0; j < N; j++)
        cin >> wave2[j];

    dp[0][0] = (wave1[0] - wave2[0]) * (wave1[0] - wave2[0]);
    for(int i = 1; i < N; i++)
        dp[i][0] = dp[i-1][0] + (wave1[i] - wave2[0]) * (wave1[i] - wave2[0]);

    for(int i = 1; i < N; i++)
        dp[0][i] = dp[0][i-1] + (wave1[0] - wave2[i]) * (wave1[0] - wave2[i]);

    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){
            dp[i][j] = mini(dp[i - 1][j - 1] + (wave1[i] - wave2[j])*(wave1[i] - wave2[j]), mini(dp[i - 1][j] + (wave1[i] - wave2[j])*(wave1[i] - wave2[j]), dp[i][j - 1] + (wave1[i] - wave2[j])*(wave1[i] - wave2[j])));
        }
    }

    cout << dp[N-1][N-1];
    return 0;
}