#include<iostream>
using namespace std;
#define ARRAY_SIZE 1000001   
#define MODULO 1000000007
#define ll long long
#define endl '\n'

int arr[ARRAY_SIZE], dp[ARRAY_SIZE];

ll coin_comb1_topdown(int n, int m)
{
    if(m < 0) return 0;
    if(m == 0) return 1;
    if(dp[m] != -1) return dp[m];
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt = (cnt + coin_comb1_topdown(n, m - arr[i])) % MODULO;
    }
    return dp[m] = cnt;
}

ll coin_comb1_bottomup(int n, int m)
{
    dp[0] = 1;

    for (int i = 1; i <= m; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if(arr[j] > i) continue;
            dp[i]= (dp[i] + dp[i - arr[j]]) % MODULO;
        }
    }
    return dp[m];
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout) ;
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<coin_comb1_bottomup(n, m)<<endl;

    // for (int i = 0; i <= m; i++)
    // {
    //     dp[i] = -1;
    // }
    // cout<<coin_comb1_topdown(n, m)<<endl;
}
