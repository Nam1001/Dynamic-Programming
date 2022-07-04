#include <bits/stdc++.h>
using namespace std;
// here the range of arr[i] lies between 1 to 1000


// int count(vector<int>&arr,int index,int target)
// {
//     if(target==0) return 1;
//     if(index<0)
//     {
//         if(target==0) return 1;
//         return 0;
//     }
//     int notpick=count(arr,index-1,target);
//     int pick=0;
//     if(target>=arr[index]) pick=count(arr,index-1,target-arr[index]);
//     return(pick+notpick);
// }
// int main()
// {
//     vector<int>arr={1,2,3,4,5};
//     int n=arr.size();
//     int target=6;
//     cout<<count(arr,n-1,target);
// }
//                                                 DP approch
// ---------------------------------------------------------------------------------------------------------------
// int count(vector<int> &arr, int index, int target, vector<vector<int>> &dp)
// {
//     if (target == 0)
//         return 1;
//     if (index < 0)
//     {
//         if (target == 0)
//             return 1;
//         return 0;
//     }
//     if (dp[index][target] != -1)
//         return dp[index][target];
//     int notpick = count(arr, index - 1, target, dp);
//     int pick = 0;
//     if (target >= arr[index])
//         pick = count(arr, index - 1, target - arr[index], dp);
//     return dp[index][target] = (pick + notpick);
// }
// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 5};
//     int n = arr.size();
//     int target = 6;
//     vector<vector<int>> dp(n, vector<int>(target + 1, -1));
//     cout << count(arr, n - 1, target, dp);
// }
//                                                   TABULATION
// ---------------------------------------------------------------------------------------------------------

// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 5};
//     int n = arr.size();
//     int target = 6;
//     vector<vector<int>> dp(n, vector<int>(target + 1, 0));
//     for (int i = 0; i < n; i++)
//     {
//         dp[i][0] = 1;
//     }
//     if (arr[0] < target)
//         dp[0][arr[0]] = 1;
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 1; j <= target; j++)
//         {
//             int notpick = dp[i - 1][j];
//             int pick = 0;
//             if (j >= arr[i])
//                 pick = dp[i - 1][j - arr[i]];
//             dp[i][j] = (pick + notpick);
//         }
//     }
//    cout<< dp[n-1][target];
// }
//                                            Space optimization
// -------------------------------------------------------------------------------------------------------------

// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 5};
//     int n = arr.size();
//     int target = 6;
//     vector<int>front(target+1);
//     vector<int>curr(target+1,0);
//     for (int i = 0; i < n; i++)
//     {
//         front[0] = curr[0]=1;
//     }
//     if (arr[0] < target)
//         front[arr[0]] = 1;
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 1; j <= target; j++)
//         {
//             int notpick = front[j];
//             int pick = 0;
//             if (j >= arr[i])
//                 pick = front[j - arr[i]];
//             curr[j] = (pick + notpick);
//         }
//         front=curr;
//     }
//    cout<< front[target];
// }


// ------------------------------------------------------------------------------------------------------------

// here the range of arr[i] lies between 1 to 1000  

int count(vector<int>&arr,int index,int target)
{
    
    if(index==0)
    {
        if(target==0 && arr[0]==0) return 2;
        if(target==0 || arr[0]==target) return 1;
        return 0;
    }
    int notpick=count(arr,index-1,target);
    int pick=0;
    if(target>=arr[index]) pick=count(arr,index-1,target-arr[index]);
    return(pick+notpick);
}
int main()
{
    vector<int>arr={0,0,1};
    int n=arr.size();
    int target=1;
    cout<<count(arr,n-1,target);
}