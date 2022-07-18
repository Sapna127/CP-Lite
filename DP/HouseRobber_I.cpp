// Memoization
int f(vector<int> &nums, int idx, vector<int> &dp){
        if(idx==0) return nums[idx];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick = nums[idx] + f(nums, idx-2,dp);
        int notPick = 0 + f(nums, idx-1,dp);
        return dp[idx] = max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(nums,n-1,dp);
    }



// Tabulation 
int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        int neg  = 0;
        for(int i=1;i<n;i++){
            int take = nums[i]; 
            if(i>1) take += dp[i-2];
            int nonTake = 0+dp[i-1];
            dp[i] = max(take,nonTake);
        }
        return dp[n-1];
    }

// Space optimization
 int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2= 0;
        for(int i=1;i<n;i++){
            int take = nums[i]; 
            if(i>1) take += prev2;
            int notTake = 0+ prev1;
            int curri = max(take,notTake);
            prev2 = prev1;
            prev1 = curri;
        }
        return prev1;
    }
