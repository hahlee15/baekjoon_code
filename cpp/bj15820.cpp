#include <stdio.h>
#include <vector>

using namespace std;

vector<int> sample;
vector<int> sampleMY;
vector<int> sys;
vector<int> sysMY;

bool isSampleRight(int num){
    for(int i = 0 ; i < num; i++){
        if(sample[i] == sampleMY[i])
            continue;
        else
            return false;
    }
    return true;
}

bool isSystemRight(int num){
    for(int i = 0 ; i < num; i++){
        if(sys[i] == sysMY[i])
            continue;
        else
            return false;
    }
    return true;
}

int main(void){
    int s1 = 0, s2 = 0;
    scanf("%d", &s1);
    scanf("%d", &s2);
    sample.assign(s1, 0);
    sampleMY.assign(s1, 0);
    sys.assign(s2, 0);
    sysMY.assign(s1, 0);

    for(int i = 0; i < s1; i++){
        scanf("%d", &sample[i]);
        scanf("%d", &sampleMY[i]);
    }

    for(int i = 0; i < s2; i++){
        scanf("%d", &sys[i]);
        scanf("%d", &sysMY[i]);
    }

    bool sampletest = isSampleRight(s1);
    bool systemtest = isSystemRight(s2);

    if(sampletest && systemtest)
        printf("Accepted\n");
    else if(!sampletest)
        printf("Wrong Answer\n");
    else if(sampletest && !systemtest)
        printf("Why Wrong!!!\n");
    
    return 0;
}