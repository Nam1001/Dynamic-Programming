#include <bits/stdc++.h>

using namespace std; 
int solve(vector<int>&coin,int target,int index)
{
    if(target==0) return 0;
    if(index<0)
    {
        if(target==0) return 0;
         return 0;
    }
    int notpick=0+solve(coin,target,index-1);
    int pick=-1e9;
    if(target>=coin[index]) pick=coin[index]+solve(coin,target-coin[index],index) ;
    return  max(pick,notpick);
}

int unboundedKnapsack(int k, vector<int> &arr) {
    int n=arr.size();
    return solve(arr,k,n-1);

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            int u;
            cin>>u;
            arr.push_back(u);
        }
        int a=unboundedKnapsack(k,arr);
        cout<<a<<endl;
    }
}
        
        
