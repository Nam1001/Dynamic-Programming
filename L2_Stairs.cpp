#include<bits/stdc++.h>
using namespace std;
//                                       NORMAL RECURSION
// ------------------------------------------------------------------------------------------------------------------------------------
// int stair(int index)
// {
//     if(index==1) return 1;
//     if(index==0) return 1;
   
//     int l=stair(index-1);
//     int m=stair(index-2);
//     return l+m;
// }
// int main()
// {
//     int n;
//     cin>>n;
//    int a= stair(n);
//    cout<<a;
    
// }
// T.C=O(2^N)
// S.C=O(N);
//                                      BY USING DP MEMIOZATION TECHNIQUE
// ----------------------------------------------------------------------------------------------------------


// int stair(int index,vector<int>&dp)
// {
//     if(index==1) return 1;
//     if(index==0) return 1;
//    if(dp[index]!=-1)
//     {
//         return dp[index];
//     }
//     return dp[index]=stair(index-1,dp)+stair(index-2,dp);
// }

// int main()
// {
//     int n;
//     cin>>n;
//    vector<int>dp(n+1,-1);
//    int a= stair(n,dp);
//    cout<<a;
    
// }
// t.c=O(n)
// s.c=O(2N)
//                                        TABULATION TECHNIQUE(BOTTOM TO UP)
// -----------------------------------------------------------------------------------------------------------------
// int stair(int n,vector<int>&dp)
// { 
//     dp[0]=1;
//     dp[1]=1;
//     for(int i=2;i<=n;i++)
//     {
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     return dp[n];

// }
// int main()
// {
//     int n;
//     cin>>n;
//    vector<int>dp(n+1);
//    int a= stair(n,dp);
//    cout<<a;
    
// }
//                                         SPACE OPTIMIZATION
// -----------------------------------------------------------------------------------------------------------------
int stair(int n)
{ 
   int prev1=1;
    int prev=1;
    for(int i=2;i<=n;i++)
    {
        int curr=prev+prev1;
        prev1=prev;
        prev=curr;
    }
    return prev;

}
int main()
{
    int n;
    cin>>n;
   int a= stair(n);
   cout<<a;
    
}