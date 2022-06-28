#include <bits/stdc++.h>

using namespace std;
// int uniquepath(int m,int n,int i,int j)
// {
//     if(i==m-1 && j==n-1)
//     {
//         return 1;
//     }
//     if(i>=n or j>=m)
//     {
//         return 0;
//     }
//     int down=uniquepath(m,n,i+1,j);
//     int right=uniquepath(m,n,i,j+1);
//     return down+right;
// }
// int main()
// {
//     int m,n;
//     cin >>m >>n;
//    cout<< uniquepath(m,n,0,0);
// }

//                                        MEMOIZATION
// ----------------------------------------------------------------------------------------------------------------

// int uniquepath(int m,int n,int i,int j, vector<vector<int>>&dp)
// {
//     if(i==m-1 && j==n-1)
//     {
//         return 1;
//     }
//     if(i>=n or j>=m)
//     {
//         return 0;
//     }
//     if(dp[i][j]!=-1) return dp[i][j];
//     int down=uniquepath(m,n,i+1,j,dp);
//     int right=uniquepath(m,n,i,j+1,dp);
//     return dp[i][j]= down+right;
// }

// int main()
// {
//     int m,n;
//     cin >>m >>n;
//     vector<vector<int>>dp(m ,vector<int>(n,-1));
//    cout<< uniquepath(m,n,0,0,dp);
// }
//                                            TABULATION(buttom to up approch)
// ---------------------------------------------------------------------------------------------------------------

// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     vector<vector<int>> dp(m, vector<int>(n, 0));
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i == 0 && j == 0)
//                 dp[0][0] = 1;
//             else
//             {
//                 int down = 0;
//                 int right = 0;
//                 if (i > 0)
//                 {
//                     down = dp[i - 1][j];
//                 }

//                 if (j > 0)
//                 {
//                     right = dp[i][j - 1];
//                 }

//                 dp[i][j] = down + right;
//             }
//         }
//     }
//     cout<< dp[m - 1][n - 1];
// }

//                                               space optimization
// ---------------------------------------------------------------------------------------------------------------
int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> prev(n,0);
     for (int i = 0; i < m; i++)
    {
        vector<int>temp(n,0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                temp[0] = 1;
            else
            {
                int down = 0;
                int right = 0;
                if (i > 0)
                {
                    down = prev[j];
                }

                if (j > 0)
                {
                    right = temp[j - 1];
                }

                temp[j] = down + right;
            }
        }
        prev=temp;
    }
    
 
    cout<<prev[n-1];
  
}