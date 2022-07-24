//memoization
 int f(int idx, vector<int> &coins, int amt, vector<vector<int>> &dp){
        if(idx==0){
            if(amt % coins[0] == 0) return amt / coins[0];
            else return 2e9;
        }
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int notTake = f(idx-1, coins, amt,dp);
        int take = INT_MAX;
        if(coins[idx]<=amt) take=f(idx,coins,amt-coins[idx],dp) + 1;
        
        return dp[idx][amt] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(n-1, coins, amount, dp);
        if(ans>=1e9) return -1;
        return ans;
    }

//Tabulation
 int coinChange(vector<int>& arr, int T) {
        int n = arr.size();
          vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
    }

//Space optimization
int coinChange(vector<int>& arr, int T) {
        int n = arr.size();
         // vector<vector<int>> dp(n,vector<int>(T+1,0));
        vector<int> prev(T+1,0) , curr(T+1,0);
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            prev[i] = i/arr[0];
        else prev[i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + prev[target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + curr[target - arr[ind]];
                
             curr[target] = min(notTake, take);
        }
        prev=curr;
    }
    
    int ans = prev[T];
    if(ans >=1e9) return -1;
    return ans;
    }
