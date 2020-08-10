#include<iostream>
using namespace std;
#define ARRAY_SIZE 1000001   
#define MODULO 1000000007
#define ll long long
#define endl '\n'

int arr[ARRAY_SIZE], dp[111][1000001];

ll coin_comb2_bottomup(int n, int w)
{    
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    // for (int j = 1; j <= w; j++)
    // {
    //     for (int i = n - 1; i >= 0 ; i--)
    //     {
    //         cout<<"dp["<<i<<"]["<<j<<"] dp["<<i<<"]["<<j-arr[i]<<"] dp["<<i+1<<"]["<<j<<"]"<<endl;
    //         //if(j > 1) dp[i][j] = 0;
    //         if(j >= arr[i])
    //         {
    //             dp[i][j] = (dp[i][j - arr[i]]) % MODULO;
    //         }
    //         if(i + 1 < n)
    //         {
    //             dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MODULO;
    //         }       
    //     }
    // }

        for (int i = n - 1; i >= 0 ; i--)
        {
            for (int j = 1; j <= w; j++)
            {
                if(j >= arr[i])
                {
                    dp[i][j] = (dp[i][j - arr[i]]) % MODULO;
                }
                if(i + 1 < n)
                {
                    dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MODULO;
                }
            }
        }

    return dp[0][w];
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout) ;
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n, w;
    cin>>n>>w;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<coin_comb2_bottomup(n, w)<<endl;
}
