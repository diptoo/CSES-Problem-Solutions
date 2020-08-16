#include<iostream>
using namespace std;
#define ARRAY_SIZE 1000001   
#define MODULO 1000000007
#define INF 99999999
#define ll long long
#define endl '\n'
int price_per_book[1001], no_of_pages[1001];
int dp[1009][100002];

int bookshop_topdown(int i, int n, int sm)
{
    if (sm < 0) return -INF;
    if (i == n) {
        if (sm >= 0) return 0;
        return -INF;
    }
    
    if(dp[i][sm] != -1) return dp[i][sm];
    
    int res1 = no_of_pages[i] + bookshop_topdown(i + 1, n, sm - price_per_book[i]);
    int res2 = bookshop_topdown(i + 1, n, sm);
    int maxy = max(res1, res2);

    return dp[i][sm] = maxy; 
}

int bookshop_bottomup(int n, int sm)
{
    for (int i = n - 1; i >= 0 ; i--)
    {
        for (int s = 1; s <= sm; s++)
        {
            int s1,s2;
            if(s - price_per_book[i] < 0)
            {
                s1 = -INF;
            }
            else
            {
                s1 = no_of_pages[i] + dp[i + 1][s - price_per_book[i]];
            }

            s2 = dp[i + 1][s];
            
            dp[i][s] = max(s1, s2);
        }
    }
    
    return dp[0][sm];
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout) ;
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n, x;
    cin>>n>>x;

    for (int i = 0; i < n; i++)
    {
        cin>>price_per_book[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>no_of_pages[i];
    }
    
    cout<<bookshop_bottomup(n, x)<<endl;
}
