/*

You are given an array ‘ARR’ of ‘N’ integers and a target number, ‘TARGET’.
Your task is to build an expression out of an array by adding one of the symbols '+' and '-'
before each integer in an array,
and then by concatenating all the integers, you want to achieve a target.
You have to return the number of ways the target can be achieved.

*/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> arr, int index, int target)
{
    if (target == 0)
        return 1;
    if (index < 0)
    {
        if (target == 0)
            return 1;
        return 0;
    }
    int notpick=0+solve(arr,index-1,target);
    int pick=0;
    if(target>=arr[index]) pick=solve(arr,index-1,target-arr[index]);
    return(notpick+pick);
}

int main()
{
    vector<int> arr = {1, 1,1,1,1};
    int target = 3;
    int total = accumulate(arr.begin(), arr.end(), 0);
    if (total - target < 0 || (total - target) % 2)
        return 0;
   cout<< solve(arr, arr.size() - 1, (total - target) / 2); // s1-s2=target,s1+s2=total hence s1=total-target/2
}


// The rest approch will be as same as count partition with a given difference.