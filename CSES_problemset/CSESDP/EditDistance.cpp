#include<iostream>
#include <cstdlib>
using namespace std;
#define ARRAY_SIZE 5001   
#define INF 1000000007
#define ll long long
#define endl '\n'

int dp[ARRAY_SIZE][ARRAY_SIZE];
int distance(string s1, string s2, int m, int n)
{
    //cout<<s1<<" "<<s2<<" "<<m<<" "<<n<<endl;
    if(m == 0 && n == 0) return 0;
    else if(m == 0 || n == 0) return abs(m - n);

    if(dp[m][n] != -1) return dp[m][n];

    int ans = 0;
    if(s1[m - 1] == s2[n - 1])
    {
        ans = distance(s1, s2, m - 1, n - 1);
    }
    else
    {
        int res1 = distance(s1, s2, m - 1, n - 1) + 1;
        int res2 = distance(s1, s2, m , n - 1) + 1;
        int res3 = distance(s1, s2, m - 1, n) + 1;
        ans = min(res1, min(res2, res3));
    }
    
    return dp[m][n] = ans;
}

int distance_bottomup(string s1, string s2, int m, int n)
{
    dp[0][0] = 0;
    for (int c = 1; c <= n; c++)
    {
        dp[0][c] = c;
    }
    for (int r = 1; r <= m; r++)
    {
        dp[r][0] = r;
    }
    
    for (int r = 1; r <= m; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            if(s1[r - 1] == s2[c - 1])
            {
                dp[r][c] = dp[r - 1][c - 1];
            }   
            else
            {
                dp[r][c] = min(dp[r - 1][c - 1], min (dp[r - 1][c], dp[r][c - 1])) + 1;
            }
        }
    }
    
    return dp[m][n];
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout) ;
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s1, s2;
    cin>>s1>>s2;

    // for (int i = 0; i <= s1.length(); i++)
    // {
    //     for (int j = 0; j <= s2.length(); j++)
    //     {
    //         dp[i][j] = -1;
    //     }
    // }
    cout<<distance_bottomup(s1, s2, s1.length(), s2.length())<<endl;
}
