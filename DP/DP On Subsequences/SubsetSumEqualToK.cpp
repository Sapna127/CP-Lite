//memoization

bool f(int idx, int k, vector<int> &a, vector<vector<int>> &dp){
    if(k==0) return true;
    if(idx==0) return a[0]==k;
    if(dp[idx][k]!=-1) return dp[idx][k];
    bool notTake = f(idx-1, k , a, dp);
    bool take = false;
    if(a[idx]<=k) take = f(idx-1, k-a[idx], a, dp);
    return dp[idx][k] = (take || notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}

//TC O(n*k)
//Sc O(n*k) + O(n)

//Tabulation
bool subsetSumToK(int n, int k, vector<int> &a) {
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k+1,0));
    for(int i=0;i<n;i++) dp[i][0] = true;
    dp[0][a[0]] = true;
    for(int idx=1; idx<n; idx++){
        for(int target=1; target<=k; target++){
            bool notTake = dp[idx-1][target];
            bool take = false;
            if(a[idx]<=target) take = dp[idx-1][target-a[idx]];
            dp[idx][target] = (take || notTake);
        }
    }
    return dp[n-1][k];
}
//TC O(n*k)
//Sc O(n*k) 


//Space Optimization

bool subsetSumToK(int n, int k, vector<int> &nums) {
    // Write your code here.
        vector<bool> prev(k+1,0), curr(k+1,0);
        prev[0]=curr[0]=true;
        prev[nums[0]] = true;
        for(int i=1;i<n;i++){
            for(int target =1 ; target<=k; target++){
                bool notTake = prev[target];
                bool take = false;
                if(target >= nums[i]) take = prev[target-nums[i]];
                curr[target] = take || notTake;
            }
            prev=curr;
        }
        return prev[k];
}
