//memoization
int f(int idx, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
    if(idx==0){
        return (int)((W/wt[0])) * val[0];
    }
    if(dp[idx][W]!=-1) return dp[idx][W];
    int notTake = f(idx-1, W, val, wt,dp);
    int take = 0;
    if(wt[idx]<=W) take = f(idx, W-wt[idx], val, wt,dp) + val[idx];
    
    return dp[idx][W] = max(notTake, take);
}
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int> (W+1,-1));
    return f(n-1,W,val,wt,dp);
}

//tabulation
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = ((int) i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int j=0; j<=W; j++){
            
            int notTaken = dp[ind-1][j];
            
            int taken = 0;
            if(wt[ind] <= j)
                taken = val[ind] + dp[ind][j - wt[ind]];
                
            dp[ind][j] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}


//space optimization 2 array 
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    //vector<vector<int>> dp(n,vector<int>(W+1,0));
    vector<int> prev(W+1,0), curr(W+1,0);
    for(int i=wt[0]; i<=W; i++){
        prev[i] = ((int) i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int j=0; j<=W; j++){
            
            int notTaken = prev[j];
            
            int taken = 0;
            if(wt[ind] <= j)
                taken = val[ind] + curr[j - wt[ind]];
                
            curr[j] = max(notTaken, taken);
        }
        prev=curr;
    }
    
    return prev[W];
}


//space optimization 1 array
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    //vector<vector<int>> dp(n,vector<int>(W+1,0));
    vector<int> prev(W+1,0);
    for(int i=wt[0]; i<=W; i++){
        prev[i] = ((int) i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int j=0; j<=W; j++){
            
            int notTaken = prev[j];
            
            int taken = 0;
            if(wt[ind] <= j)
                taken = val[ind] + prev[j - wt[ind]];
                
            prev[j] = max(notTaken, taken);
        }
    }
    
    return prev[W];
}

