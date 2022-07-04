#include <bits/stdc++.h>
using namespace std;
// int maxsum(vector<vector<int>> matrix, int start, int end, int n,int m)
// {
//     if (end >= n or end < 0)
//         return -1e9;

//     if (start == 0)
//         return matrix[start][end];

//     int up = matrix[start][end] + maxsum(matrix, start - 1, end, n,m);  //we are starting from n-1 index thats why
//                                                                             // our direction are opposite;
//     int leftdia = matrix[start][end] + maxsum(matrix, start - 1, end - 1, n,m);
//     int rightdia = matrix[start][end] + maxsum(matrix, start - 1, end + 1, n,m);
//     return max(up, max(rightdia, leftdia));
// }
// int main()
// {
//     vector<vector<int>> matrix = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
//     int m = matrix[0].size();
//     int n=matrix.size();
//     int maxi = -1e9;
//     for (int i = 0; i < m; i++)
//     {
//         maxi = max(maxi, maxsum(matrix, n - 1, i, n,m));
//     }
//     cout << maxi;
// }
//                                                 MEMOIZATION
// ----------------------------------------------------------------------------------------------------------------

// int maxsum(vector<vector<int>> matrix, int start, int end, int n,int m,vector<vector<int>>&dp)
// {
//     if (end >= n or end < 0)
//         return -1e9;

//     if (start == 0)
//         return matrix[start][end];
//     if(dp[start][end]!=-1) return dp[start][end];
//     int up = matrix[start][end] + maxsum(matrix, start - 1, end, n,m,dp);  //we are starting from n-1 index thats why
//                                                                             // our direction are opposite;
//     int leftdia = matrix[start][end] + maxsum(matrix, start - 1, end - 1, n,m,dp);
//     int rightdia = matrix[start][end] + maxsum(matrix, start - 1, end + 1, n,m,dp);
//     return dp[start][end]= max(up, max(rightdia, leftdia));
// }

// int main()
// {
//     vector<vector<int>> matrix = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
//     int m = matrix[0].size();
//     int n=matrix.size();
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     int maxi = -1e9;
//     for (int i = 0; i < m; i++)
//     {
//         maxi = max(maxi, maxsum(matrix, n - 1, i, n,m,dp));
//     }
//     cout << maxi;
// }
//                                         TABULATION
// -------------------------------------------------------------------------------------------------------------

// int main()
// {
//     vector<vector<int>> matrix = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
//     int m = matrix[0].size();
//     int n = matrix.size();
//     vector<vector<int>> dp(n, vector<int>(m));
//     for (int j = 0; j < m; j++)
//     {
//         dp[0][j] = matrix[0][j];
//     }
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             int up = matrix[i][j] + dp[i-1][j]; // we are starting from n-1 index thats why
//                                               //  our direction are opposite;
//             int leftdia = matrix[i][j];
//             if(j-1>=0) leftdia+= dp[i - 1][j - 1];
//             else{
//                 leftdia+=-1e9;
//             }
//             int rightdia = matrix[i][j] ;
//             if(j+1<m)rightdia+= dp[i - 1][j + 1];
//             else{
//                 rightdia+=-1e9;
//             }
//             dp[i][j] = max(up, max(rightdia, leftdia));
//         }
//     }
//     int maxi = -1e9;
//     for (int i = 0; i < m; i++)
//     {
//         maxi = max(maxi, dp[ n - 1][ i]);
//     }
//     cout << maxi;
// }

//                                           Space optimization
// ------------------------------------------------------------------------------------------------------------

int main()
{
    vector<vector<int>> matrix = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    int m = matrix[0].size();
    int n = matrix.size();
    vector<int>front(m);
    vector<int>curr(m);
    for (int j = 0; j < m; j++)
    {
        front[j] = matrix[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + front[j]; // we are starting from n-1 index thats why
                                              //  our direction are opposite;
            int leftdia = matrix[i][j];
            if(j-1>=0) leftdia+= front[j - 1];
            else{
                leftdia+=-1e9;
            }
            int rightdia = matrix[i][j] ;
            if(j+1<m)rightdia+= front[j + 1];
            else{
                rightdia+=-1e9;
            }
            curr[j] = max(up, max(rightdia, leftdia));
        }
        front=curr;
    }
    int maxi = -1e9;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, front[i]);
    }
    cout << maxi;
}