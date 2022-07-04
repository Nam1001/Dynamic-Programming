#include <bits/stdc++.h>
using namespace std;

// int slove(vector<int> &w, vector<int> &v, int index, int maxweight)
// {
//     if(index==0)
//     {
//         if(w[index]<=maxweight) return v[index];
//         else return 0;
//     }
//     int notpick=slove(w,v,index-1,maxweight)+0;
//     int pick=INT_MIN;
//     if(w[index]<=maxweight) pick=slove(w,v,index-1,maxweight-w[index])+v[index];
//     return max(pick,notpick);
// }
// int main()
// {
//     vector<int>weight={1,2,4,5};
//     vector<int> values={5,4,8,6};
//     int bagweight=5;
//     int n=weight.size();
//    cout<< slove(weight,values,n-1,bagweight);
// }

//                                            DP approch
// -----------------------------------------------------------------------------------------------------------
// int slove(vector<int> &w, vector<int> &v, int index, int maxweight,vector<vector<int>>&dp)
// {
//     if(index==0)
//     {
//         if(w[index]<=maxweight) return v[index];
//         else return 0;
//     }
//     if(dp[index][maxweight]!=-1) return dp[index][maxweight];
//     int notpick=slove(w,v,index-1,maxweight,dp)+0;
//     int pick=INT_MIN;
//     if(w[index]<=maxweight) pick=slove(w,v,index-1,maxweight-w[index],dp)+v[index];
//     return dp[index][maxweight]= max(pick,notpick);
// }
// int main()
// {
//     vector<int>weight={1,2,4,5};
//     vector<int> values={5,4,8,6};
//     int bagweight=5;
//     int n=weight.size();
//     vector<vector<int>>dp(n,vector<int>(bagweight+1,-1));
//    cout<< slove(weight,values,n-1,bagweight,dp);
// }
//                                                 TABULATION
// -------------------------------------------------------------------------------------------------------------
// int main()
// {
//     vector<int> weight = {1, 2, 4, 5};
//     vector<int> values = {5, 4, 8, 6};
//     int bagweight = 5;
//     int n = weight.size();
//     vector<vector<int>> dp(n, vector<int>(bagweight + 1, 0));
//     for(int i=weight[0];i<=bagweight;i++)
//     {
//         dp[0][i]=values[0];
//     }
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 1; j <= bagweight; j++)
//         {
//             int notpick = dp[i - 1][ j] + 0;
//             int pick = INT_MIN;
//             if (weight[i] <= j)
//                 pick = dp[ i - 1][ j - weight[i]] + values[i];
//             dp[i][j] = max(pick, notpick);
//         }
//     }
//     cout<<dp[n-1][bagweight];
// }
// int main()
// {
//     vector<int> weight = {1, 2, 4, 5};
//     vector<int> values = {5, 4, 8, 6};
//     int bagweight = 5;
//     int n = weight.size();
//     vector<int>front(bagweight+1,0);
//     vector<int>curr(bagweight+1,0);
//     for(int i=weight[0];i<=bagweight;i++)
//     {
//         front[i]=values[0];
//     }
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 1; j <= bagweight; j++)
//         {
//             int notpick = front[ j] + 0;
//             int pick = INT_MIN;
//             if (weight[i] <= j)
//                 pick = front[ j - weight[i]] + values[i];
//             curr[j] = max(pick, notpick);
//         }
//         front=curr;
//     }
//     cout<<front[bagweight];
// }
//
//                                        MORE SPACE OPTIMIZATION
//------------------------------------------------------------------------------------------------------------------ 
int main()
{
    vector<int> weight = {1, 2, 4, 5};
    vector<int> values = {5, 4, 8, 6};
    int bagweight = 5;
    int n = weight.size();
    vector<int>front(bagweight+1,0);
    for(int i=bagweight;i>=weight[0];i--)
    {
        front[i]=values[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= bagweight; j++)
        {
            int notpick = front[ j] + 0;
            int pick = INT_MIN;
            if (weight[i] <= j)
                pick = front[ j - weight[i]] + values[i];
            front[j] = max(pick, notpick);
        }
        
    }
    cout<<front[bagweight];
}