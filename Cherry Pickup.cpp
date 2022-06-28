#include <bits/stdc++.h>
using namespace std;
//  int summax(vector<vector<int>> &path, int n, int m, int i, int j1, int j2)
//  {
//      if ( j1 < 0 || j1 >=m  || j2 < 0 || j2 >= m)
//          return -1e8;
//      if (i == n - 1)
//      {
//          if (j1 == j2)
//              return path[n-1][j2];
//          else
//              return path[i][j1] + path[i][j2];
//      }

//      int maxi = -1e8;
//      for (int k = -1; k <= 1; k++)// EXPLORING ALL THE PATHS BY ALICE
//      {
//          for (int j = -1; j <= 1; j++)// BY BOB
//          {

//              if (j1 == j2)
//                  maxi = max( path[i][j1] + summax(path, n, m, i + 1, j1 + k, j2 + j),maxi);
//              else
//                  maxi = max(maxi, path[i][j1] + path[i][j2] + summax(path, n, m, i + 1, j1 + k, j2 + j));

//          }
//      }
//      return maxi;
//  }
//  int main()
//  {
//      vector<vector<int>> path = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
//      int n = 3;
//      int m = 4;
//      cout << summax(path, n, m, 0, 0, m - 1);
//  }
//                                             MEMOIZATION
// ---------------------------------------------------------------------------------------------------------------
// int summax(vector<vector<int>> &path, int n, int m, int i, int j1, int j2,vector<vector<vector<int>>>dp)
//  {
//      if ( j1 < 0 || j1 >=m  || j2 < 0 || j2 >= m)
//          return -1e8;
//      if (i == n - 1)
//      {
//          if (j1 == j2)
//              return path[n-1][j2];
//          else
//              return path[i][j1] + path[i][j2];
//      }
//      if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
//  int maxi = -1e8;
//  for (int k = -1; k <= 1; k++)// EXPLORING ALL THE PATHS BY ALICE
//  {
//      for (int j = -1; j <= 1; j++)// BY BOB
//      {

//          if (j1 == j2)
//              maxi = max( path[i][j1] + summax(path, n, m, i + 1, j1 + k, j2 + j,dp),maxi);
//          else
//              maxi = max(maxi, path[i][j1] + path[i][j2] + summax(path, n, m, i + 1, j1 + k, j2 + j,dp));

//         dp[i][j1][j2]=maxi;
//      }
//  }
//  return dp[i][j1][j2];
//  }

// int main()
//  {
//      vector<vector<int>> path = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
//      int n = 3;
//      int m = 4;
//      vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
//      cout << summax(path, n, m, 0, 0, m - 1,dp);
//  }

//                                         TABULATION
//  --------------------------------------------------------------------------------------------------------------

// int main()
// {
//     vector<vector<int>> path = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
//     int n = 3;
//     int m = 4;
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
//     for (int j1 = 0; j1 < m - 1; j1++)
//     {
//         for (int j2 = 0; j2 <= m - 1; j2++)
//         {
//             if (j1 == j2)
//                 dp[n - 1][j1][j2] = path[n - 1][j1];
//             else
//                 dp[n - 1][j1][j2] = path[n - 1][j1] + path[n - 1][j2];
//         }
//     }
//     for (int i = n - 2; i >= 0; i--)
//     {
//         for (int j1 = 0; j1 < m; j1++)
//         {
//             for (int j2 = 0; j2 < m; j2++)
//             {
//                 int maxi = -1e8;
//                 for (int k = -1; k <= 1; k++) // EXPLORING ALL THE PATHS BY ALICE
//                 {
//                     for (int j = -1; j <= 1; j++) // BY BOB
//                     {
//                         int value=0;
//                         if (j1 == j2)
//                             value = path[i][j1];
//                         else value=path[i][j1]+path[i][j2];    
//                         if (j1 + k >= 0 && j1 + k < m && j2 + j >= 0 && j2 + j < m)
//                             value += dp[i + 1][j1 + k][j2 + j];
//                         else{
//                             value+=-1e9;
//                         }  
//                         maxi=max(maxi,value); 
//                     }
//                 }
//                 dp[i][j1][j2]=maxi;
//             }
//         }
//     }
//     cout<< dp[0][0][m-1];
// }
//                                                Space Optimization
// ----------------------------------------------------------------------------------------------------------------

int main()
{
    vector<vector<int>> path = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    int n = 3;
    int m = 4;
    vector<vector<int>>front(m,vector<int>(m));
    vector<vector<int>>curr(m,vector<int>(m));
    for (int j1 = 0; j1 < m - 1; j1++)
    {
        for (int j2 = 0; j2 <= m - 1; j2++)
        {
            if (j1 == j2)
                curr[j1][j2] = path[n - 1][j1];
            else
                curr[j1][j2] = path[n - 1][j1] + path[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;
                for (int k = -1; k <= 1; k++) // EXPLORING ALL THE PATHS BY ALICE
                {
                    for (int j = -1; j <= 1; j++) // BY BOB
                    {
                        int value=0;
                        if (j1 == j2)
                            value = path[i][j1];
                        else value=path[i][j1]+path[i][j2];    
                        if (j1 + k >= 0 && j1 + k < m && j2 + j >= 0 && j2 + j < m)
                            value += front[j1 + k][j2 + j];
                        else{
                            value+=-1e9;
                        }  
                        maxi=max(maxi,value); 
                    }
                }
                curr[j1][j2]=maxi;
            }
            front =curr;
        }
    }
    cout<< front[0][m-1];
}