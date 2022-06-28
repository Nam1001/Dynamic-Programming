#include <bits/stdc++.h>
using namespace std;

// bool check(vector<int>&arr,int index,int target)
// {
//     if(target==0) return true;
//     if(index<0)
//     {
//         if(target==0) return true;
//         return false;
//     }
//     // if(dp[index][target]!=-1) return dp[index][target];
//     bool notpick=check(arr,index-1,target);
//     bool pick=false;
//     if(target>=arr[index]) pick=check(arr,index-1,target-arr[index]);
//     return pick||notpick;
// }

// int main()
// {
//     vector<int>arr={1,2,3,4,7};
//     int n=arr.size();
//     int s=accumulate(arr.begin(),arr.end(),0);
//     if(s%2==0) if(check(arr,n-1,s/2)==true) cout<< true;
//                else cout<< false;
//     else cout<< false;
// }
//                                             MEMOIZATION
// ---------------------------------------------------------------------------------------------------------------

// bool check(vector<int> &arr, int index, int target, vector<vector<int>> &dp)
// {
//     if (target == 0)
//         return true;
//     if (index < 0)
//     {
//         if (target == 0)
//             return true;
//         return false;
//     }
//     if (dp[index][target] != -1)
//         return dp[index][target];
//     bool notpick = check(arr, index - 1, target, dp);
//     bool pick = false;
//     if (target >= arr[index])
//         pick = check(arr, index - 1, target - arr[index], dp);
//     return dp[index][target] = pick || notpick;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 7};
//     int n = arr.size();
//     int s = accumulate(arr.begin(), arr.end(), 0);
//     vector<vector<int>> dp(n + 1, vector<int>(s / 2 + 1, -1));
//     if (s % 2 == 0)
//         if (check(arr, n - 1, s / 2, dp) == true)
//             cout << true;
//         else
//             cout << false;
//     else
//         cout << false;
// }
//                                              TABULATION
// ----------------------------------------------------------------------------------------------------------------
// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 7};
//     int n = arr.size();
//     int s = accumulate(arr.begin(), arr.end(), 0);
//     vector<vector<bool>> dp(n + 1, vector<bool>(s / 2 + 1, 0));
//     if (s % 2 == 0)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             dp[i][0] = true;
//         }

//         dp[0][arr[0]] = true;
//         for (int i = 1; i < n; i++)
//         {
//             for (int j = 1; j <= s / 2; j++)
//             {
//                 bool notpick = dp[i - 1][j];
//                 bool pick = false;
//                 if (j >= arr[i])
//                     pick = dp[i - 1][j - arr[i]];
//                 dp[i][j] = pick || notpick;
//             }
//         }
//         cout<<dp[n-1][s/2];
//     }

//     else
//         cout << false;
// }

//                                                   Space Optimization
// --------------------------------------------------------------------------------------------------------------


// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 7,1};
//     int n = arr.size();
//     int s = accumulate(arr.begin(), arr.end(), 0);
//     vector<bool> front(s/2+1,0);
//     vector<bool> curr(s/2+1,0);
//     if (s % 2 == 0)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             front[0] =curr[0]= true;
//         }

//         front[arr[0]] = true;
//         for (int i = 1; i < n; i++)
//         {
//             for (int j = 1; j <= s / 2; j++)
//             {
//                 bool notpick = front[j];
//                 bool pick = false;
//                 if (j >= arr[i])
//                     pick = front[j - arr[i]];
//                 curr[j] = pick || notpick;
//             }
//             front=curr;
//         }
//         cout<<front[s/2];
        
//     }

//     else
//         cout << false;
// }