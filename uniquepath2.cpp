#include <bits/stdc++.h>
using namespace std;
// int unique(int i, int j, vector<vector<int>> &path)
// {
//     if (i == 0 && j == 0)
//     {
//         return 1;
//     }
//     if (i < 0 || j < 0)
//         return 0;
//     if (path[i][j] == -1)
//         return 0;

//     int up = unique(i - 1, j, path);
//     int left = unique(i, j - 1, path);
//     return left + up;
// }
// int main()
// {
//     int n = 3;
//     int m = 3;
//     vector<vector<int>> path = {
//         {0, 0, 0},
//         {0, -1, 0},
//         {0, 0, 0},
//     };
//     if (path[n - 1][m - 1] == 0)
//     {
//         cout << unique(n - 1, m - 1, path);
//     }
// }

//                                         MEMOIZATION
// ----------------------------------------------------------------------------------------------------------------
int unique(int i, int j, vector<vector<int>> &path , vector<vector<int>>&dp)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
        return 0;
    if (path[i][j] == -1)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = unique(i - 1, j, path,dp);
    int left = unique(i, j - 1, path,dp);
    return dp[i][j]= (left + up)%1000000007;
}


int main()
{
    int n = 3;
    int m = 3;
    vector<vector<int>> path = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0},
    };
    vector<vector<int>>dp(n,vector<int>(m,-1));
    if (path[n - 1][m - 1] == 0)
    {
        cout << unique(n - 1, m - 1, path,dp);
    }
}