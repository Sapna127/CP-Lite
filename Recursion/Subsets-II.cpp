void helper(vector<vector<int>> &ans, vector<int> &nums,vector<int> &ds,int idx){
        ans.push_back(ds);
         for (int i = idx; i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            helper(ans,nums,ds,i+1);
            ds.pop_back();
         }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        helper(ans,nums,ds,0);
        return ans;
    }
