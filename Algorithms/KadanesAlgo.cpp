//maximum subarray sum
// https://leetcode.com/problems/maximum-subarray/

int maxSubArray(vector<int>& nums) {
        int sum=0,maxSum=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>maxSum)
                maxSum=sum;
            if(sum<0)
                sum=0;
        }
        return maxSum;
    }
