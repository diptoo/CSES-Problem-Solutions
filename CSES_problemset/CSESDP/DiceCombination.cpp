#include<iostream>
using namespace std;
#define ARRAY_SIZE 1000001   
#define MODULO 1000000007
#define ll long long
#define endl '\n'
long long dp[ARRAY_SIZE];
long long dice_combination(int n)
{
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    long long cnt = 0;
    for (int i = 1; i <= 6; i++)
    {
        cnt += dice_combination(n - i);
    }
    return dp[n] = cnt % MODULO;
}

ll dice_comb_bottom_up(int n)
{
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= 6; j++)
        {
            if(j > i) break;
            dp[i] = (dp[i] + dp[i - j]) % MODULO; 
        }
    }
    
    return dp[n];
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout) ;
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;

    cout<<dice_comb_bottom_up(n)<<endl;



    // for (int i = 0; i <= n; i++)
    // {
    //     dp[i] = -1;
    // }
    // cout<<dice_combination(n) % MODULO<<endl;
}