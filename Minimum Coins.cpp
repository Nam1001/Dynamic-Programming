#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&coin,int target,int index)
{
    if(target==0) return 0;
    if(index<0)
    {
        if(target==0) return 0;
        else return 1e9;
    }
    int notpick=0+solve(coin,target,index-1);
    int pick=1e9;
    if(target>=coin[index]) pick=1+solve(coin,target-coin[index],index) ;
    return  min(pick,notpick);
}
// int main()
// {
//     vector<int>coin={17,10,5};
//     int target=6;
//     int n=coin.size();
//    cout<< solve(coin,target,n-1);
// }

//                                              DP APPROCH
// --------------------------------------------------------------------------------------------------------------
// int solve(vector<int>&coin,int target,int index,vector<vector<int>>&dp)
// {
//     if(target==0) return 0;
//     if(index<0)
//     {
//         if(target==0) return 0;
//         else return 1e9;
//     }
//     if(dp[index][target]!=-1) return dp[index][target];
//     int notpick=0+solve(coin,target,index-1,dp);
//     int pick=1e9;
//     if(target>=coin[index]) pick=1+solve(coin,target-coin[index],index,dp) ;
//     return dp[index][target]= min(pick,notpick);
// }
// int main()
// {
//     vector<int>coin={17,10,5};
//     int target=6;
//     int n=coin.size();
//     vector<vector<int>>dp(n,vector<int>(target+1,-1));
//    cout<< solve(coin,target,n-1,dp);
// }


//                                                  Tabulation
// -------------------------------------------------------------------------------------------------------------
int solve(vector<int>&coin,int target,int index,vector<vector<int>>&dp)
{
    if(target==0) return 0;
    if(index<0)
    {
        if(target==0) return 0;
        else return 1e9;
    }
    if(dp[index][target]!=-1) return dp[index][target];
    int notpick=0+solve(coin,target,index-1,dp);
    int pick=1e9;
    if(target>=coin[index]) pick=1+solve(coin,target-coin[index],index,dp) ;
    return dp[index][target]= min(pick,notpick);
}
int main()
{
    vector<int>coin={17,10,5};
    int target=6;
    int n=coin.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    for(int i=0; i<n;i++)
    {
        dp[i][0]=0;
    }
    
}