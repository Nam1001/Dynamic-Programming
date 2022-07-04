#include <bits/stdc++.h>
using namespace std;
// int count(vector<int>&arr,int index,int target)
// {

//     if(index==0)
//     {
//         if(target==0 && arr[0]==0) return 2;
//         if(target==0 || arr[0]==target) return 1;
//         return 0;
//     }
//     int notpick=count(arr,index-1,target);
//     int pick=0;
//     if(target>=arr[index]) pick=count(arr,index-1,target-arr[index]);
//     return(pick+notpick);
// }
// int main()
// {
//     vector<int>arr={5,2,5,1};
//     int n=arr.size();
//     int totalsum =accumulate(arr.begin(),arr.end(),0);
//     int D=3;
//     if(totalsum-D<0 || (totalsum-D)%2) return 0;
//     cout<<count(arr,n-1,(totalsum-D)/2);  // here sum of subset1-sum of subset2=D such that s1>s2;
//                                           //   s1-s2=D ,  s1+s2=totalsum, s1-(totalsum-s1)=D ,s1=totalsum-D/2;
//                                         //   therefore our target is s1
// }

//                                             DP approch
// ---------------------------------------------------------------------------------------------------------------

// int count(vector<int>&arr,int index,int target,vector<vector<int>>&dp)
// {

//     if(index==0)
//     {
//         if(target==0 && arr[0]==0) return 2;
//         if(target==0 || arr[0]==target) return 1;
//         return 0;
//     }
//     if(dp[index][target]!=-1) return dp[index][target];
//     int notpick=count(arr,index-1,target,dp);
//     int pick=0;
//     if(target>=arr[index]) pick=count(arr,index-1,target-arr[index],dp);
//     return dp[index][target]=(pick+notpick);
// }

// int main()
// {
//     vector<int>arr={5,2,5,1};
//     int n=arr.size();
//     int totalsum =accumulate(arr.begin(),arr.end(),0);
//     int D=3;
//     vector<vector<int>>dp(n,vector<int>((totalsum-D)/2+1,-1));
//     if(totalsum-D<0 || (totalsum-D)%2) return 0;
//     cout<<count(arr,n-1,(totalsum-D)/2,dp);  // here sum of subset1-sum of subset2=D such that s1>s2;
//                                           //   s1-s2=D ,  s1+s2=totalsum, s1-(totalsum-s1)=D ,s1=totalsum-D/2;
//                                         //   therefore our target is s1
// }
//                                           Tabulation
// -------------------------------------------------------------------------------------------------------------

//  int mod =(int)1e9+7;

// int findWays(vector<int> &num, int tar){
//      int n = num.size();

//     vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
//     if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
//     else dp[0][0] = 1;  // 1 case - not pick
    
//     if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
//     for(int ind = 1; ind<n; ind++){
//         for(int target= 0; target<=tar; target++){
            
//             int notTaken = dp[ind-1][target];
    
//             int taken = 0;
//                 if(num[ind]<=target)
//                     taken = dp[ind-1][target-num[ind]];
        
//             dp[ind][target]= (notTaken + taken)%mod;
//         }
//     }
//     return dp[n-1][tar];
// }

// int countPartitions(int n, int d, vector<int>& arr){
//     int totSum = 0;
//     for(int i=0; i<n;i++){
//         totSum += arr[i];
//     }
    
//     //Checking for edge cases
//     if(totSum-d <0 || (totSum-d)%2 ) return 0;
    
//     return findWays(arr,(totSum-d)/2);
// }
  

// int main() {

//   vector<int> arr = {5,2,6,4};
//   int n = arr.size();
//   int d=3;
                                 
//   cout<<"The number of subsets found are " <<countPartitions(n,d,arr);
// }



//                                              Space optimization
// ------------------------------------------------------------------------------------------------------------

// int mod =(int)1e9+7;

// int findWays(vector<int> &num, int tar){
//      int n = num.size();

//     vector<int> front(tar+1,0);
//     vector<int>curr(tar+1,0);
    
//     if(num[0] == 0) front[0] =2;  // 2 cases -pick and not pick
//     else front[0] = 1;  // 1 case - not pick
    
//     if(num[0]!=0 && num[0]<=tar) front[num[0]] = 1;  // 1 case -pick
    
//     for(int ind = 1; ind<n; ind++){
//         for(int target= 0; target<=tar; target++){
            
//             int notTaken = front[target];
    
//             int taken = 0;
//                 if(num[ind]<=target)
//                     taken = front[target-num[ind]];
        
//             curr[target]= (notTaken + taken)%mod;
//         }
//         front=curr;
//     }
//     return front[tar];
// }

// int countPartitions(int n, int d, vector<int>& arr){
//     int totSum = 0;
//     for(int i=0; i<n;i++){
//         totSum += arr[i];
//     }
    
//     //Checking for edge cases
//     if(totSum-d <0 || (totSum-d)%2 ) return 0;
    
//     return findWays(arr,(totSum-d)/2);
// }
  

// int main() {

//   vector<int> arr = {5,2,6,4};
//   int n = arr.size();
//   int d=3;
                                 
//   cout<<"The number of subsets found are " <<countPartitions(n,d,arr);
// }
