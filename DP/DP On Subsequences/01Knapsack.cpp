//memoization

int f(int idx, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){
    if(idx==0){
        if(wt[0]<=W) return val[0];
        return 0;
    }
    if(dp[idx][W]!=-1) return dp[idx][W];
    int notTake = f(idx-1,W,wt,val,dp);
    int take= INT_MIN;
    if(wt[idx]<=W) take = val[idx] + f(idx-1,W-wt[idx],wt,val,dp);
    
    return dp[idx][W] = max(take,notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int> (maxWeight+1,-1));
    return f(n-1,maxWeight,weight,value,dp);
}

//TC O(n*w)
//Sc O(n*w) + O(n)

//tabulation
int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
	vector<vector<int>> dp(n, vector<int> (W+1, 0));
    for(int w=wt[0];w<=W;w++) dp[0][w] = val[0];
    
    for(int i=1;i<n;i++){
        for(int w=0;w<=W;w++){
        int notTake = dp[i-1][w];
        int take= INT_MIN;
        if(wt[i]<=w) take = val[i] + dp[i-1][w-wt[i]];

        dp[i][w] = max(take,notTake);      
        }
    }
    return dp[n-1][W];
}
//TC O(n*w)
//Sc O(n*w)

//space optimization 2 rows
int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
	//vector<vector<int>> dp(n, vector<int> (W+1, 0));
    vector<int> prev(W+1,0) , curr(W+1,0);
    for(int w=wt[0];w<=W;w++) prev[w] = val[0];
    
    for(int i=1;i<n;i++){
        for(int w=0;w<=W;w++){
        int notTake = prev[w];
        int take= INT_MIN;
        if(wt[i]<=w) take = val[i] + prev[w-wt[i]];

        curr[w] = max(take,notTake);      
        }
        prev=curr;
    }
    return prev[W];
}

//TC O(n*w)
//Sc O(w) + O(w)

//space optimization - 1 row

int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
	//vector<vector<int>> dp(n, vector<int> (W+1, 0));
    vector<int> prev(W+1,0);
    for(int w=wt[0];w<=W;w++) prev[w] = val[0];
    
    for(int i=1;i<n;i++){
        for(int w=W;w>=0;w--){
        int notTake = prev[w];
        int take= INT_MIN;
        if(wt[i]<=w) take = val[i] + prev[w-wt[i]];

        prev[w] = max(take,notTake);      
        }
    }
    return prev[W];
}
//TC O(n*w)
//Sc O(w)
