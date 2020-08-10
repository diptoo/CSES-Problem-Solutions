#include<iostream>
using namespace std;
#define ARRAY_SIZE 1001   
#define MODULO 1000000007
#define ll long long
#define endl '\n'
char grid[ARRAY_SIZE][ARRAY_SIZE];
int dp[ARRAY_SIZE][ARRAY_SIZE], row, col;
// int dx[] = {1, 0};
// int dy[] = {0, 1};

int dx[]={-1, 0}; 
int dy[]={0, -1};

 
bool isValid(int x, int y)
{
    if(x < 0 || x >=row || y < 0 || y >= col) return false;
    if(grid[x][y] == '*') return false;
    return true;
}

// int grid_path(int x, int y, int dstX, int dstY)
// {
//     if(x == dstX && y == dstY) 
//     {
//         //cout<<"asd"<<endl;
//         return 1;
//     }
//     if(dp[x][y] != -1) return dp[x][y];
//     int cnt = 0;
//     for (int i = 0; i < 2; i++)
//     {
//         int u = x + dx[i];
//         int v = y + dy[i];
//         if(isValid(u, v))
//         {
//             cnt = (cnt + grid_path(u, v, dstX, dstY)) % MODULO;
//         }
//     }
//     return dp[x][y] = cnt;
// }

int grid_path_bottom_up(int x, int y, int dstX, int dstY)
{
    dp[0][0] = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(i == 0 && j == 0) continue;
            int up = 0;
            int left = 0;
            if(isValid(i, j - 1)) left = dp[i][j - 1];
            if(isValid(i - 1, j)) up = dp[i - 1][j];
            dp[i][j] = (up + left) % MODULO; 
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }

    return dp[dstX][dstY];
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout) ;
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>row;
    col = row;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>grid[i][j];
        }
    }

    if(!isValid(0, 0) || !isValid(row - 1, col - 1)) cout<<0<<endl;
    else cout<<grid_path_bottom_up(0, 0, row - 1, col - 1)<<endl;
}
