//memoization
int f(int idx, int n, vector<int> &cuts, vector<vector<int>> &dp){
        if(idx==0) {
            return n*cuts[0];
        }
        if(dp[idx][n]!=-1) return dp[idx][n];
        int notTake = f(idx-1, n, cuts,dp);
        int take = INT_MIN;
        int rodLength = idx+1;
        if(rodLength <= n) take = f(idx, n-rodLength, cuts, dp) + cuts[idx];
        return dp[idx][n] = max(take, notTake);
   }
int cutRod(vector<int> &cuts, int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1, 0));
    for(int i=0;i<=n;i++) dp[0][i] = i*cuts[0];
    
    for(int idx=1;idx<n;idx++){
        for(int i=0;i<=n;i++){
        int notTake = dp[idx-1][i];
        int take = INT_MIN;
        int rodLength = idx+1;
        if(rodLength <= i) take = dp[idx][i-rodLength] + cuts[idx];
        dp[idx][i] = max(take, notTake);     
        }
    }
	return dp[n-1][n];
}


//tabulation
int cutRod(vector<int> &cuts, int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1, 0));
    for(int i=0;i<=n;i++) dp[0][i] = i*cuts[0];
    
    for(int idx=1;idx<n;idx++){
        for(int i=0;i<=n;i++){
        int notTake = dp[idx-1][i];
        int take = INT_MIN;
        int rodLength = idx+1;
        if(rodLength <= i) take = dp[idx][i-rodLength] + cuts[idx];
        dp[idx][i] = max(take, notTake);     
        }
    }
	return dp[n-1][n];
}


//space optimization 1 array
int cutRod(vector<int> &cuts, int n)
{
    //vector<vector<int>> dp(n, vector<int>(n+1, 0));
    vector<int> prev(n+1,0), curr(n+1,0);
    for(int i=0;i<=n;i++) prev[i] = i*cuts[0];
    
    for(int idx=1;idx<n;idx++){
        for(int i=0;i<=n;i++){
        int notTake = prev[i];
        int take = INT_MIN;
        int rodLength = idx+1;
        if(rodLength <= i) take = curr[i-rodLength] + cuts[idx];
        curr[i] = max(take, notTake);     
        }
        prev = curr;
    }
	return curr[n];
}



//space optimization 2 array 
int cutRod(vector<int> &cuts, int n)
{
    //vector<vector<int>> dp(n, vector<int>(n+1, 0));
    vector<int> prev(n+1,0);
    for(int i=0;i<=n;i++) prev[i] = i*cuts[0];
    
    for(int idx=1;idx<n;idx++){
        for(int i=0;i<=n;i++){
        int notTake = prev[i];
        int take = INT_MIN;
        int rodLength = idx+1;
        if(rodLength <= i) take = prev[i-rodLength] + cuts[idx];
        prev[i] = max(take, notTake);     
        }
    }
	return prev[n];
}
