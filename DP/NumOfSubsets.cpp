//memoization
int f(vector<int> &num, int idx, int tar,vector<vector<int>> &dp){
    if(tar == 0) return 1;
    if(idx == 0) return num[0]==tar;
    if(dp[idx][tar]!=-1) return dp[idx][tar];
    int notTake = f(num, idx-1, tar,dp);
    int take = 0;
    if(num[idx]<=tar) take+=f(num, idx-1, tar-num[idx],dp);
    
    return dp[idx][tar] = take + notTake;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, -1));
    return f(num, n-1, tar, dp);
}


//tabulation
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));
    for(int i=0;i<n;i++) dp[i][0]=1;
    if(num[0]<=tar) dp[0][num[0]]=1;
    
    for(int idx=1;idx<n;idx++){
            for(int sum=0;sum<=tar;sum++){
            int notTake = dp[idx-1][sum];
            int take = 0;
            if(num[idx]<=sum) take=dp[idx-1][sum-num[idx]];

            dp[idx][sum] = take + notTake;     
        }
    }
    return dp[n-1][tar];
}


//space optimization
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    //vector<vector<int>> dp(n, vector<int>(tar+1, 0));
   vector<int> prev(tar+1,0), curr(tar+1,0);
   prev[0]=curr[0]=1;
    if(num[0]<=tar) prev[num[0]]=1;
    
    for(int idx=1;idx<n;idx++){
            for(int sum=0;sum<=tar;sum++){
            int notTake = prev[sum];
            int take = 0;
            if(num[idx]<=sum) take=prev[sum-num[idx]];

            curr[sum] = take + notTake;     
        }
        prev=curr;
    }
    return curr[tar];
}
