#include<bits/stdc++.h>
using namespace std;
// bool check(vector<int>&arr,int index,int target,vector<vector<bool>>&dp)
// {
//     if(target==0) return true;
//     if(index==0) return(arr[0]==target);
//     bool notpick=check(arr,index-1,target);
//     bool pick=false;
//     if(target>=arr[index]) pick=check(arr,index-1,target-arr[index]);
//     return (pick) or (notpick);
// }
int main()
{
    vector<int>arr={12,9,2,13};
    int s=accumulate(arr.begin(),arr.end(),0);
    int n=arr.size();
    vector<vector<bool>>dp(n,vector<bool>(s+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
 if(arr[0]<s)   dp[0][arr[0]]=true;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            bool notpick=dp[i-1][j];
            bool pick=false;
            if(j>=arr[i]) pick=dp[i-1][j-arr[i]];
            dp[i][j]= (pick) or (notpick);
        }
    }
    int mini=1e9;
    for(int i=0;i<=s;i++)
    {
        if(dp[n-1][i]==true)
        {
            int s1=i;
            int s2=s-i;
            mini=min(mini,abs(s1-s2));
        }
    }
    cout<<mini;
}