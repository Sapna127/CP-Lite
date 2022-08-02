//Recursion
#include<bits/stdc++.h>
int f(vector<int> &height, int idx){
    if(idx==0) return 0;
    int left = f(height,idx-1) + abs(height[idx-1]-height[idx]);
    int right = INT_MAX;
    if(idx>1) right = f(height,idx-2) + abs(height[idx-2]- height[idx]);
    return min(left,right);
}

int frogJump(int n, vector<int> &height)
{
    // Write your code here.
    return f(height,n-1);
}


//Memoization 
#include<bits/stdc++.h>
int f(vector<int> &height, int idx, vector<int> &dp){
    if(idx==0) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int left = f(height,idx-1,dp) + abs(height[idx-1]-height[idx]);
    int right = INT_MAX;
    if(idx>1) right = f(height,idx-2,dp) + abs(height[idx-2]- height[idx]);
    return dp[idx] = min(left,right);
}

int frogJump(int n, vector<int> &height)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    return f(height,n-1,dp);
}

//Tabulation
#include<bits/stdc++.h>
int frogJump(int n, vector<int> &height)
{
    // Write your code here.
    vector<int> dp(n,0);
    dp[0]=0;
   for(int i=1;i<n;i++){
       int fs = dp[i-1] + abs(height[i]-height[i-1]);
       int ss = INT_MAX;
       if(i>1) ss = dp[i-2] + abs(height[i]-height[i-2]);
       dp[i]=min(fs,ss);
   }
    return dp[n-1];
}

//Space Optimization
#include<bits/stdc++.h>
int frogJump(int n, vector<int> &height)
{
    // Write your code here.
   int prev1 = 0, prev2 = 0;
   for(int i=1;i<n;i++){
       int fs = prev1 + abs(height[i]-height[i-1]);
       int ss = INT_MAX;
       if(i>1) ss = prev2 + abs(height[i]-height[i-2]);
       int curri =min(fs,ss);
       prev2 = prev1;
       prev1 = curri;
   }
    return prev1;
}
