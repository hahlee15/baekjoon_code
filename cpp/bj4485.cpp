#include <iostream>
#include <cstdio>
#include <queue>
#include <functional>
 
#define INF 987654321
 
using namespace std;
 
typedef pair<int, int> loc;
 
int map[125][125];
int dist[125][125];
 
int main()
{
    int testCase = 1;
    while (testCase++)
    {
        int n;
        scanf("%d", &n);
 
        if (!n)
            break;
 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = INF;
                scanf("%d", &map[i][j]);
            }
        
        queue<pair<int,loc>> pq;
 
        dist[0][0] = map[0][0];
        pq.push({ dist[0][0], loc(0, 0) });
    
 
        while (!pq.empty())
        {
            int cost = pq.front().first;
            int y = pq.front().second.first;
            int x = pq.front().second.second;
 
            pq.pop();
 
            if (dist[y][x] < cost)
                continue;
        
            if (y + 1 < n &&  dist[y + 1][x] > cost + map[y + 1][x])
            {
                dist[y + 1][x] = cost + map[y + 1][x];
                pq.push({ dist[y + 1][x], loc(y + 1, x) });
            }
 
            if (y - 1 >= 0 && dist[y - 1][x] > cost + map[y - 1][x])
            {
                dist[y - 1][x] = cost + map[y - 1][x];
                pq.push({ dist[y - 1][x], loc(y - 1, x) });
            }
 
            if (x + 1 < n &&dist[y][x + 1] > cost + map[y][x + 1])
            {
                dist[y][x + 1] = cost + map[y][x + 1];
                pq.push({ dist[y][x + 1], loc(y, x + 1) });
            }
 
            if (x - 1 >= 0 && dist[y][x - 1] > cost + map[y][x - 1])
            {
                dist[y][x - 1] = cost + map[y][x - 1];
                pq.push({ dist[y][x - 1], loc(y, x - 1) });
            }
        }
 
        
        printf("Problem %d: %d\n", testCase - 1, dist[n - 1][n - 1]);
    }
    return 0;
}