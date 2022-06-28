#include <bits/stdc++.h>
using namespace std;
// bool subsetsum1(vector<int> &arr, int target, int index)
// {
//     if (target == 0)
//         return true;
//     if (index == 0)
//     {
//         if (arr[0] == target)
//             return true;
//         else
//             return false;
//     }
//     bool notpick = subsetsum1(arr, target, index - 1);
//     bool pick = false;
//     if (target >= arr[index])
//         pick = subsetsum1(arr, target - arr[index], index - 1);
//     return notpick or pick;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 4, 5, 6};
//     int target = 10;
//     int n = arr.size();
//     cout << subsetsum1(arr, target, n - 1);
// }
//                                           MEMOIZATION
// ----------------------------------------------------------------------------------------------------------------

// bool subsetsum1(vector<int> &arr, int target, int index, vector<vector<int>> &dp)
// {
//     if (target == 0)
//         return true;
//     if (index == 0)
//     {
//         if (arr[0] == target)
//             return true;
//         else
//             return false;
//     }
//     if (dp[index][target] != -1)
//         return dp[index][target];
//     bool notpick = subsetsum1(arr, target, index - 1, dp);
//     bool pick = false;
//     if (target >= arr[index])
//         pick = subsetsum1(arr, target - arr[index], index - 1, dp);
//     return dp[index][target] = notpick or pick;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 4, 5, 6};
//     int target = 10;
//     int n = arr.size();
//     vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
//     cout << subsetsum1(arr, target, n - 1, dp);
// }

//                                              TABULATION
// ---------------------------------------------------------------------------------------------------------------

// int main()
// {
//     vector<int> arr = {1, 2, 4, 5, 6};
//     int target = 10;
//     int n = arr.size();
//     vector<vector<bool>> dp(n + 1,vector<bool>(target + 1, 0));
//     for (int i = 0; i < n; i++)
//     {
//         dp[i][0] = true;
//     }

//     dp[0][arr[0]] = true;

//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 1; j <= target; j++)
//         {
//             bool notpick = dp[i-1][ j];
//             bool pick = false;
//             if (j >= arr[i])
//                 pick = dp[i- 1][ j - arr[i]];
//             dp[i][j]= notpick or pick;
//         }
//     }
//     cout<<dp[n-1][target];
// }
//                                               Space Optimization
// --------------------------------------------------------------------------------------------------------------

int main()
{
    vector<int> arr = {1, 2, 4, 5, 6};
    int target = 10;
    int n = arr.size();
    vector<bool> front(target+1,0);
    vector<bool> curr(target+1,0); 
    for (int i = 0; i < n; i++)
    {
        front[0] = true;
    }

    front[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notpick = front[ j];
            bool pick = false;
            if (j >= arr[i])
                pick = front[ j - arr[i]];
            curr[j]= notpick or pick;
        }
        front=curr;
    }
    cout<<front[target];
}