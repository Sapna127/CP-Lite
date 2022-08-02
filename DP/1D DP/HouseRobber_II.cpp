int rob1(vector<int>& nums) {
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
    int rob(vector<int>& v) {
        int n = v.size();
        if(n==1) return v[0];
        vector<int> temp1, temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(v[i]);
            if(i!=(n-1)) temp2.push_back(v[i]);
        }
        return max(rob1(temp1), rob1(temp2));
    }
