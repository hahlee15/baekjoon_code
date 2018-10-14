#include <iostream>
#include <vector>

using namespace std;

int k = 1;
vector<int> stk;
int arr[13];

void lotto(int count, int cnt){
    if(cnt == 6){
        for(int i = 0; i < 6; i ++){
            printf("%d ", stk[i]);
        }

        printf("\n");
        return;
    }

    for(int j = count; j < k; j++){
        stk.push_back(arr[j]);
        lotto(j+1, cnt+1);
        stk.pop_back();
    }
}

int main(void){
    int i = 0, j = 1;
    while(1){
        scanf("%d", &k);
        if(k == 0)
            return 0;

        for(i = 0; i < k; i++){
            scanf("%d", &arr[i]);
        }

        lotto(0, 0);
        std::fill_n(arr, 13, 0);
        printf("\n");
    }
}