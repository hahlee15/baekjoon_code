#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool map[102][102];

int endx = 0;
int endy = 0;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

vector<int> gen;

void rotation(vector<int> &gen){
    int size = (int)gen.size();
    
    for(int i = size - 1; i >= 0; i--){
        int dir = (gen[i] + 1) % 4;
        
        endx = endx + dx[dir];
        endy = endy + dy[dir];
        
        map[endx][endy] = true;
        gen.push_back(dir);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        int y, x, d, g;
        cin >> y >> x >> d >> g;
        
        gen.clear();
        
        endx = x;
        endy = y;
        
        map[endx][endy] = true;
        
        endx = x + dx[d];
        endy = y + dy[d];
        
        map[endx][endy] = true;
        gen.push_back(d);
        
        for(int i=0; i<g; i++)
            rotation(gen);
    }

    int result = 0;
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            if(map[i][j] == true && map[i][j+1] == true && map[i+1][j] == true && map[i+1][j+1] == true){
                result++;
            }
        }
    }
    printf("%d\n", result);
}