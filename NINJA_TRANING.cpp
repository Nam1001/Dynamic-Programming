#include <bits/stdc++.h>
using namespace std;
// int maximumcredit(int days,int task[3][3],int last)
// {
//     if(days==0)
//     {
//         int maxi=0;
//         for(int i=0;i<3;i++)
//         {
//             if(i!=last)
//             {
//                 maxi=max(maxi,task[0][i]);
//             }
//         }
//         return maxi;
//     }
//     int maxii=0;
//     for(int i=0;i<3;i++)
//     {
//         if(i!=last)
//         {
//             int points=task[days][i]+maximumcredit(days-1,task,i);
//             maxii=max(maxii,points);
//         }

//     }
//     return maxii;
// }
// int main()
// {
//     int days=3;
//     int task [3][3]={{18,11,19},{4,13,7},{1,8,13}};
//     int ans=maximumcredit(days-1,task,3); //3 denotes that none task was performed
//     cout<<ans;
// }
//                                           MEMOIZATION
// ------------------------------------------------------------------------------------------------------------
// int f(int days,int last,vector<vector<int>>&points,vector<vector<int>>&dp)
// {
//     if(days==0)
//     {
//         int maxi=0;
//         for(int i=0;i<3;i++)
//         {
//             if(i!=last)
//             {
//                 maxi=max(maxi,points[0][i]);
//             }
//         }
//          return maxi;
//     }
//     if(dp[days][last]!=-1) return dp[days][last];

//         int maxii=0;
//         for(int i=0;i<3;i++)
//         {
//             if(i!=last)
//             {
//                 int point=points[days][i]+f(days-1,i,points,dp);
//                 maxii=max(maxii,point);
//             }
//         }
//         return dp[days][last]= maxii;

// }
// int main()
// {
//     int days=3;
//     vector<vector<int>>points={{18,11,19},{4,13,7},{1,8,13}};

//     vector<vector<int>>dp(days,vector<int>(5,-1));
//     int ans= f(days-1,3,points,dp);
//     cout<<ans;
// }
//                                         TABULATION
// --------------------------------------------------------------------------------------------------------------
// int main()
// {
//     int days = 3;
//     vector<vector<int>> points = {{18, 11, 19}, {4, 13, 7}, {1, 8, 13}};

//     vector<vector<int>> dp(days, vector<int>(4, 0));

//     dp[0][0] = max(points[0][1], points[0][2]);
//     dp[0][1] = max(points[0][2], points[0][0]);
//     dp[0][2] = max(points[0][0], points[0][1]);
//     dp[0][3] = max(points[0][1], max( points[0][2], points[0][0]));

//     for (int i = 1; i < days; i++)
//     {
//         for (int last = 0; last <= 3; last++)
//         {
//             dp[i][last]=0;
//             for (int k = 0; k < 3; k++)
//             {
//                 if (k != last)
//                 {
//                     int point = points[i][k] + dp[i-1][k];
//                     dp[i][last] = max(dp[i][last], point);
//                 }
//             }
//         }
//     }
//     cout<< dp[days-1][3];
// }
//                                     SPACE OPTIMIZATION
// ----------------------------------------------------------------------------------------------------------------
// int main()
// {
//     int days = 3;
//     vector<vector<int>> points = {{18, 11, 19}, {4, 13, 7}, {1, 8, 13}};
//     vector<int> prev(4,0);
//     prev[0] = max(points[0][1], points[0][2]);
//     prev[1] = max(points[0][2], points[0][0]);
//     prev[2] = max(points[0][0], points[0][1]);
//     prev[3] = max(points[0][1], max( points[0][2], points[0][0]));
    
//     for (int i = 1; i < days; i++)
//     {
//         vector<int>temp(4,0);
//         for (int last = 0; last <= 3; last++)
//         {
//             temp[last]=0;
//             for (int k = 0; k < 3; k++)
//             {
//                 if (k != last)
//                 {
//                     int point = points[i][k] + prev[k];
//                     temp[last] = max(temp[last], point);
//                 }
//             }
//         }
//         prev=temp;
//     }
    
//     cout<< prev[3];
// }