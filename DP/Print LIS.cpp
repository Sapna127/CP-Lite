int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), hash(n);
        int maxi=1, lastI=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int pre=0;pre<i;pre++){
                if(nums[pre]<nums[i] && 1+dp[pre] > dp[i]) {
                    dp[i]=1+dp[pre];
                    hash[i]=pre;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastI=i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastI]);
        while(hash[lastI]!=lastI){
            lastI = hash[lastI];
            temp.push_back(nums[lastI]);
        }
        reverse(temp.begin(),temp.end());
        
        for(auto &i : temp) cout<<i<<" ";
        cout<<endl;
        
        return maxi;
    }
