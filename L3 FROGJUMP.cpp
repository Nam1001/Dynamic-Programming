#include <bits/stdc++.h>
using namespace std;

//                                  NORMAL RECURSION
// -----------------------------------------------------------------------------------------------------------------
// int frogjump(vector<int> &arr, int index)
// {
//     if (index == 1)
//     {
//         return 0;
//     }
//     int r=INT_MAX;
//     int l = frogjump(arr, index - 1) + abs(arr[index] - arr[index - 1]);
//     if (index > 2)
//     {
//          r = frogjump(arr, index - 2) + abs(arr[index] - arr[index - 2]);
//     }
//     return min(l, r);
// }
// int main()
// {
//     vector<int> arr = {10, 20, 30, 10};
//     int a=frogjump(arr, arr.size());
//     cout<<a;
// }
//                              "BY USING DP "  MEMOIZATION TECHNIQUE
// --------------------------------------------------------------------------------------------------------------
// int frogjump(vector<int>&arr,int index,vector<int>& dp)
// {
//     if(index==0)
//     {
//         return 0;
//     }
//     if(dp[index]!=0)
//     {
//         return dp[index];
//     }
//     if(index==1)
//     {
//         return dp[index]=abs(arr[index]-arr[index-1]);
//     }
//     if(index>1)
//     {
//     return dp[index]=min(frogjump(arr,index-1,dp)+abs(arr[index]-arr[index-1]),frogjump(arr,index-2,dp)+abs(arr[index]-arr[index-2]));
//     }
// }
// int main()
// {
//     vector<int> arr = {10, 20, 30, 10};
//     vector<int> dp(arr.size(),0);
//    int a= frogjump(arr, arr.size() - 1,dp);
//    cout<<a;

// T.C=O(N);
//  S.C=O(N);
// }
//                               USING TABULATION METHOD(BOTTOM TO UP APPROCH)
// -----------------------------------------------------------------------------------------------------------------

// int frogjump(vector<int>&arr,vector<int>&dp)
// {

//     dp[0]=0;
//     for(int i=1;i<arr.size();i++)
//     {
//     int l=dp[i-1]+abs(arr[i]-arr[i-1]);
//     int r=INT_MAX;
//     if(i>1)
//     {
//         r=dp[i-2]+abs(arr[i]-arr[i-2]);
//     }
//      dp[i]=min(l,r);
//     }
//     return dp[arr.size()-1];

// }

// int main()
// {
//      vector<int> arr={10,20,30,10};
//      vector<int>dp(arr.size());
//      int a=frogjump(arr,dp);
//      cout<<a;

// }

//                                           SPACE OPTIMIZATION
// ----------------------------------------------------------------------------------------------------------------

// int frogjump(vector<int> &arr)
// {

//     int prev = 0;
//     int prev1 = 0;
//     for (int i = 1; i < arr.size(); i++)
//     {
//         int l = prev + abs(arr[i] - arr[i - 1]);
//         int r = INT_MAX;
//         if (i > 1)
//         {
//             r = prev1 + abs(arr[i] - arr[i - 2]);
//         }
//         int curri = min(l, r);
//         prev1 = prev;
//         prev = curri;
//     }
//     return prev;
// }

// int main()
// {
//     vector<int> arr = {10, 20, 30, 10};
    
//     int a = frogjump(arr);
//     cout << a;
// }
