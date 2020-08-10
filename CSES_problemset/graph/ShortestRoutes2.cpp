#include<iostream>
#include<queue>
using namespace std;
#define ARRAY_SIZE 500
#define INFINITY 1e18
#define ll long long

ll int dist[ARRAY_SIZE][ARRAY_SIZE];
void floyd_warshall(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout) ;
//    #endif

    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                dist[i][j] = 0;
            }
            else dist[i][j] = INFINITY;  
        }
    }
    
    while (m--)
    {
        int u, v;
        ll int w;
        scanf("%d %d %lld", &u, &v, &w);
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    floyd_warshall(n);
   
    while (q--)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        if(dist[src][dest] == INFINITY)
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n", dist[src][dest]);
        }
    }
}