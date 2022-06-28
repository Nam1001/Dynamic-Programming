#include <bits/stdc++.h>
using namespace std;
// int minpath(vector<vector<int>>&tri,int start,int end,int n)
// {
//     if(start==n-1) return tri[start][end];
//     if(start>n|| end>n) return 1e9;
//     int down=tri[start][end]+minpath(tri,start+1,end,n);
//     int dia=tri[start][end]+minpath(tri,start+1,end+1,n);
//     return min(down,dia);
// }
// int main()
// {
//     vector<vector<int>> triangle={{1},{2,3},{4,5,6},{7,8,9,10}};
//     int n=4;
//    cout<< minpath(triangle,0,0,n);
// }
//                                              MEMOIZATION
// ----------------------------------------------------------------------------------------------------------------
// int minpath(vector<vector<int>> &tri, int start, int end, int n, vector<vector<int>> &dp)
// {
//     if (start == n - 1)
//         return tri[start][end];
//     if (start > n || end > n)
//         return 1e9;
//     if (dp[start][end] != -1)
//         return dp[start][end];
//     int down = tri[start][end] + minpath(tri, start + 1, end, n, dp);
//     int dia = tri[start][end] + minpath(tri, start + 1, end + 1, n, dp);
//     return min(down, dia);
// }

// int main()
// {
//     vector<vector<int>> triangle = {{1}, {2, 3}, {4, 5, 6}, {7, 8, 9, 10}};
//     int n = 4;
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     cout << minpath(triangle, 0, 0, n, dp);
// }

//                                           TABULATION
// ---------------------------------------------------------------------------------------------------------------

// int main()
// {
//     vector<vector<int>> triangle = {{1}, {2, 3}, {4, 5, 6}, {7, 8, 9, 10}};
//     int n = 4;
//     vector<vector<int>> dp(n, vector<int>(n));
//     for (int i = 0; i < n; i++)
//     {
//         dp[n - 1][i] = triangle[n - 1][i];
//     }
//     for (int i = n - 2; i >= 0; i--)
//     {
//         for (int j = i; j >= 0; j--)
//         {

//             int up = triangle[i][j] + dp[i +1][j];

//             int dia = triangle[i][j] + dp[i + 1][j + 1];
//             dp[i][j]=min(up,dia);
//         }
//     }
//     cout << dp[0][0];
// }
//                                         Space Optimization
// ---------------------------------------------------------------------------------------------------------------
int main()
{
    vector<vector<int>> triangle = {{1}, {2, 3}, {4, 5, 6}, {7, 8, 9, 10}};
    int n = 4;
    
    vector<int> prev(n,0);
    for (int i = 0; i < n; i++)
    {
        prev[i] = triangle[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int>curr(n,0);
        for (int j = i; j >= 0; j--)
        {

            int up = triangle[i][j] + prev[j];

            int dia = triangle[i][j] + prev[j+1];
            curr[j]=min(up,dia);
        }
        prev=curr;
    }
    cout << prev[0];
}

