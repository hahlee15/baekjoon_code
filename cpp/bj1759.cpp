#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<char> stk;
char arr[15];
int L = 0, C = 0;

bool isRight(){
    int mCnt = 0, jCnt = 0;
    for(int i = 0; i < L; i++){
        if(stk[i] == 'a' || stk[i] == 'e' || stk[i] == 'i' || stk[i] == 'o' || stk[i] == 'u')
            mCnt++;
        else
            jCnt++;
    }

    if(mCnt >= 1 && jCnt >= 2)
        return true;
    else
        return false;
}

void password(int count, int cnt){
    if(cnt == L){
        if(isRight()){
            for(int i = 0; i < L; i++)
                printf("%c", stk[i]);

            printf("\n");
            return;
        }
    }

    for(int j = count; j < C; j++){
        stk.push_back(arr[j]);
        password(j+1, cnt+1);
        stk.pop_back();
    }
}

int main(){
    cin >> L >> C;

    for(int i = 0; i < C; i++){
        scanf(" %c", &arr[i]);
    }

    sort(arr, arr+C);
    password(0, 0);

    return 0;
}