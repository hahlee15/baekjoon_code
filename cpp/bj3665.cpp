#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <stdio.h>

using namespace std;

int main(void){
    int tc = 0, n = 0, m = 0;
    int i = 0, j = 0;
    pair<int, int> ab;
    vector<int> t;
    vector<int> ind;

    scanf("%d", &tc);
    while(tc-- != 0){
        scanf("%d", &n);
        int rank[n+1][n+1];
        for(i = 0; i < n + 1; i++){
            for(j = 0; j < n + 1; j++){
                if(i == j)
                    rank[i][j] = -1;
                else
                    rank[i][j] = 0;
            }
        }
        t.assign(n, 0);
        ind.assign(n+1, 0);

        for(i = 0; i < n; i++){
            cin >> t[i];
        }

        for(i = 0; i < n; i++){
            for(j = i + 1; j < n; j++){
                rank[t[i]][t[j]] = 1;
                ind[t[j]]++;
            }
        }

        int a = 0, b = 0;
        scanf("%d", &m);
        for(i = 0; i < m; i++){
            scanf("%d", &a);
            scanf("%d", &b);
            if(rank[a][b] == 1){
                rank[a][b] = 0;
                rank[b][a] = 1;
                ind[b]--;
                ind[a]++;
            } else{
                rank[a][b] = 1;
                rank[b][a] = 0; 
                ind[b]++;
                ind[a]--;
            }
        }
        
        queue<int> q;
        for(i = 1; i < n + 1; i++){
            if(!ind[i])
                q.push(i);
        }

        bool what = true;
        vector<int> result;
        while(!q.empty()){
            if(q.size() > 1){
                what = false;
                break;
            }
            int current = q.front();
            q.pop();
            result.push_back(current);

            for(int next = 1; next < n + 1; next++){
                if(rank[current][next]){
                    ind[next]--;
                    if(!ind[next])
                        q.push(next);
                }
            }
        }
        
        if(!what)
            printf("?\n");
        else if(result.size() == n){
            for(i = 0; i < n; i++){
                printf("%d ", result[i]);
            }
            printf("\n");
        }
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}