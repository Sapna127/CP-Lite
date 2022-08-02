//memoization
 int f(int idx, int amt, vector<int> &coins,vector<vector<int>> &dp){
        if(idx==0){
            return amt%coins[0]==0;
        }
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int notTake = f(idx-1, amt, coins, dp);
        int take = 0;
        if(coins[idx]<=amt) take = f(idx, amt-coins[idx], coins, dp);
        return dp[idx][amt] = take + notTake;
    }
    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amt+1, -1));
        return f(n-1, amt, coins,dp);
    }

//tabulation
    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amt+1, 0));
        for(int i=0;i<=amt;i++) dp[0][i]=(i%coins[0]==0);
        
        for(int idx=1;idx<n;idx++){
            for(int j=0;j<=amt;j++){
                int notTake = dp[idx-1][j];
                int take = 0;
                if(coins[idx]<=j) take = dp[idx][j-coins[idx]];
                dp[idx][j] = take + notTake;
            }
        }
        return dp[n-1][amt];
    }

//space optimization
int change(int amt, vector<int>& coins) {
        int n = coins.size();
        //vector<vector<int>> dp(n, vector<int>(amt+1, 0));
        vector<int> prev(amt+1, 0), curr(amt+1, 0);
        for(int i=0;i<=amt;i++) prev[i]=(i%coins[0]==0);
        
        for(int idx=1;idx<n;idx++){
            for(int j=0;j<=amt;j++){
                int notTake = prev[j];
                int take = 0;
                if(coins[idx]<=j) take = curr[j-coins[idx]];
                curr[j] = take + notTake;
            }
            prev=curr;
        }
        return prev[amt];
    }
