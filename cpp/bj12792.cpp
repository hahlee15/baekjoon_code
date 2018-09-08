#include <iostream>

using namespace std;

int main(){
    int N = 0, temp = 0;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &temp);
        if(temp == i){
            printf("-1\n");
            return 0;
        }
    }
    printf("1000000007\n");
    return 0;
}