#include<iostream>
#include<queue>
using namespace std;
#define ARRAY_SIZE 500
#define INFINITY 1e9 + 5

bool mark[ARRAY_SIZE];
int dist[ARRAY_SIZE];
vector<pair<int, int> >adj[ARRAY_SIZE]; // first vertex, second weight

int main()
{
//     #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout) ;
//    #endif

   int a,b;
   cin>>a>>b;
   cout<<a+b;
}