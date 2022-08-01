int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1),cnt(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int pre=0;pre<i;pre++){
                if(nums[i]>nums[pre] && 1+dp[pre] > dp[i]) {
                    dp[i]=1+dp[pre];
                    cnt[i]=cnt[pre];
                }
                else if(nums[i]>nums[pre] && 1+dp[pre] == dp[i]){
                    cnt[i] += cnt[pre];
                }
            } 
            maxi=max(maxi,dp[i]);
        }
        int num=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) num+=cnt[i];
        }
        return num;
    }
