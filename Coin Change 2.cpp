#include <bits/stdc++.h>
using namespace std;
// long solve(vector<int> &arr,int index,int target)
// {
//     if(target==0) return 1;
//     if(index<0)
//     {
//         if(target==0) return 1;
//         else return 0;

//     }
//     long notpick=0+solve(arr,index-1,target);
//     long pick=0;
//     if(target>=arr[index]) pick=solve(arr,index,target-arr[index]);
//     return pick+notpick;
// }
// int main()
// {
//     vector<int>arr={1,3,4,5};
//     int target=4;
//     int n=arr.size();
//     cout<<solve(arr,n-1,target);

// }
//                                               DP APPROCH
// ---------------------------------------------------------------------------------------------------------------

// long solve(vector<int>&arr,int index,int target,vector<vector<long>>&dp)
// {
//     if(target==0) return 1;
//     if(index<0)
//     {
//         if(target==0) return 1;
//         else return 0;

//     }
//     if(dp[index][target]!=-1) return dp[index][target];
//     long notpick=0+solve(arr,index-1,target,dp);
//     long pick=0;
//     if(target>=arr[index]) pick=solve(arr,index,target-arr[index],dp);
//     return dp[index][target]=pick+notpick;
// }
// int main()
// {
//     vector<int>arr={1,3,4,5};
//     int target=4;
//     int n=arr.size();
//     vector<vector<long>>dp(n,vector<long>(target+1,-1));
//     cout<<solve(arr,n-1,target,dp);

// }
//                                          TABULATION
// --------------------------------------------------------------------------------------------------------------

int main()
{
    vector<int> arr = {1, 3, 4, 5};
    int target = 4;
    int n = arr.size();
    vector<vector<long>> dp(n, vector<long>(target + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    // dp[0][arr[0]] = 2;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            long notpick = 0 + dp[i - 1][j];
            long pick = 0;
            if (j >= arr[i])
                pick = dp[i][j - arr[i]];
            dp[i][j] = pick + notpick;
        }
    }
    cout << dp[n - 1][target];
}