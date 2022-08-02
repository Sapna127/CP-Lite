int longestBitonicSequence(vector<int>& nums, int n) {
        vector<int> dp1(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int pre=0;pre<i;pre++){
                if(nums[i]>nums[pre] && 1+dp1[pre] > dp1[i]) {
                    dp1[i]=1+dp1[pre];
                }
            } 
        }
        
       vector<int> dp2(n,1);
       for(int i=n-1;i>=0;i--){
            for(int pre=n-1;pre>i;pre--){
                if(nums[i]>nums[pre] && 1+dp2[pre] > dp2[i]) {
                    dp2[i]=1+dp2[pre];
                }
            } 
           maxi=max(maxi, dp1[i]+dp2[i]-1);
        }
    return maxi;
} 

//TC O(n^n) + O(n^n) + O(n)
//SC O(n)
