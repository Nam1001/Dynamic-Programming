#include <bits/stdc++.h>
using namespace std;
// int sum(vector<int>&arr,int index)
// {
//     if(index==0)
//     {
//         return arr[index];
//     }
//     if(index<0)
//     {
//         return 0;
//     }
//     int pick=arr[index]+sum(arr,index-2);
//     int notpick=0+sum(arr,index-1);
//     return max(pick,notpick);
// }
// int main()
// {
//     vector<int> arr={10,20,30,10};
//     int n=arr.size();
//     int a=sum(arr,n-1);
//     cout<<a;
// }
//                                        MEMOIZATION
// ----------------------------------------------------------------------------------------------------------------
// int sum(vector<int>&arr,int index,vector<int>&dp)
// {
//     if(index==0)
//     {
//         return arr[index];
//     }
//     if(index<0)
//     {
//         return 0;
//     }
//     if(dp[index]!=-1)
//     {
//         return dp[index];
//     }
//     int pick=arr[index]+sum(arr,index-2,dp);
//     int notpick=0+sum(arr,index-1,dp);
//     dp[index]= max(pick,notpick);
//     return dp[index-1];
// }
// int main()
// {
//     vector<int> arr={10,20,30,10};
//     int n=arr.size();
//     vector<int>dp(n,-1);
//     int a=sum(arr,n-1,dp);
//     cout<<a;
// }
// 
//                                         TABULATION(BUTTOM TO UP APPROCH)
// -----------------------------------------------------------------------------------------------------------------
// int sum(vector<int> &arr, int index, vector<int> &dp)
// {
//     dp[0] = arr[0];
//     for (int i = 1; i < arr.size(); i++)
//     {
//         int pick = INT_MIN;
//         if (i - 2 >= 0)
//         {
//             pick = arr[i] + dp[i - 2];
//         }
//         int notpick = 0 + dp[i - 1];
//         dp[i] = max(pick, notpick);
//     }
//     return dp[arr.size()-1];
// }
// int main()
// {
//     vector<int> arr = {10, 20, 30, 10};
//     int n = arr.size();
//     vector<int> dp(n);
//     int a = sum(arr, n - 1, dp);
//     cout << a;
// }
//                                           SPACE OPTIMIZATION
// ---------------------------------------------------------------------------------------------------------------

int sum(vector<int> &arr, int index)
{
    int prev=arr[0];
    int prev2=0;
    for (int i = 1; i < arr.size(); i++)
    {
        
        int take=arr[i]+prev2;
        int nottake=0+prev;
        int curri=max(take,nottake);

        prev2=prev;
        prev=curri;
    }
    return prev;
}
int main()
{
    vector<int> arr = {10, 20, 30, 10};
    int n = arr.size();
    int a = sum(arr, n - 1);
    cout << a;
}