//memoization
int f(int idx, int prevInd, vector<int>& nums,int n,vector<vector<int>> &dp){
        if(idx==n) return 0;
        if(dp[idx][prevInd+1]!=-1) return dp[idx][prevInd+1];
        int len = f(idx+1,prevInd,nums,n,dp);
        if(prevInd==-1 || nums[idx]>nums[prevInd]) {
            len = max(1+f(idx+1,idx,nums,n,dp),len);
        }
        
        return dp[idx][prevInd+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return f(0,-1,nums,n,dp);
    }



//tabulation
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int idx=n-1;idx>=0;idx--){
            for(int prevInd=idx-1;prevInd>=-1;prevInd--){
            int len = dp[idx+1][prevInd+1];
            if(prevInd==-1 || nums[idx]>nums[prevInd]) {
                len = max(1+dp[idx+1][idx+1],len);
            }

            dp[idx][prevInd+1]=len;   
            }
        }
        return dp[0][0];
    }


//space optimization
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       vector<int> next(n+1,0), curr(n+1,0);
        for(int idx=n-1;idx>=0;idx--){
            for(int prevInd=idx-1;prevInd>=-1;prevInd--){
            int len = next[prevInd+1];
            if(prevInd==-1 || nums[idx]>nums[prevInd]) {
                len = max(1+next[idx+1],len);
            }

            curr[prevInd+1]=len;   
            }
            next=curr;
        }
        return curr[0];
    }


//another way
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int pre=0;pre<i;pre++){
                if(nums[pre]<nums[i]) {
                    dp[i]=max(dp[i],1+dp[pre]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
