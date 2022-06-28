#include <bits/stdc++.h>
using namespace std;
// int minsum(vector<vector<int>>&path,int start,int end)
// {
//     if(start==0 && end==0)
//     {
//         return path[0][0];

//     }
//     if(start<0 || end<0) return 1000000;
//     int up= path[start][end]+minsum(path,start-1,end);
//     int left= path[start][end]+minsum(path,start,end-1);
//     return min(up,left);
// }
// int main()
// {
//     vector<vector<int>>path={{5,9,6},{11,5,2}};
//     int n=2;
//     int m=3;
//     cout<<minsum(path,n-1,m-1);
// }

//                                           MEMOIZATION
// ---------------------------------------------------------------------------------------------------------------

// int minsum(vector<vector<int>>&path,int start,int end, vector<vector<int>>&dp)
// {
//     if(start==0 && end==0)
//     {
//         return path[0][0];

//     }
//     if(start<0 || end<0) return 1000000;
//     if(dp[start][end]!=-1) return dp[start][end];
//     int up= path[start][end]+minsum(path,start-1,end,dp);
//     int left= path[start][end]+minsum(path,start,end-1,dp);
//     return dp[start][end]= min(up,left);
// }

// int main()
// {
//     int n=2;
//     int m=3;
//     vector<vector<int>>path={{5,9,6},{11,5,2}};
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     cout<<minsum(path,n-1,m-1,dp);
// }

//                                           TABULATION
// -----------------------------------------------------------------------------------------------------------

// int main()
// {

//     vector<vector<int>> path = {{5, 9, 6}, {11, 5, 2}};
//     int n = path.size();
//     int m = path[0].size();
//     vector<vector<int>> dp(n, vector<int>(m, 0));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (i == 0 && j == 0)
//             {
//                 dp[i][j] = path[0][0];
//             }

//             else
//             {
//                 int up = path[i][j];
//                 if (i > 0)
//                     up += dp[i - 1][j];
//                 else
//                     up += 1e9;
//                 int left = path[i][j];
//                 if (j > 0)
//                     left += dp[i][j - 1];
//                 else
//                     left += 1e9;
//                 dp[i][j] = min(left, up);
//             }
//         }
//     }
//     cout << dp[n - 1][m - 1];
// }

//                                        Space Optimization
// ------------------------------------------------------------------------------------------------------------

int main()
{

    vector<vector<int>> path = {{5, 9, 6}, {11, 5, 2}};
    int n = path.size();
    int m = path[0].size();
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                temp[j] = path[i][j];
            else
            {

                int up = path[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up += 1e9;

                int left = path[i][j];
                if (j > 0)
                    left += temp[j - 1];
                else
                    left += 1e9;
                temp[j] = min(up, left);
            }
        }
        prev = temp;
    }
    cout << prev[m - 1];
}