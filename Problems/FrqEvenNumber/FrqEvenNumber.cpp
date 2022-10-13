#include <vector>
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        
        map<int,int> m;
        
        for(auto x: nums){
            if(x%2==0){
                m[x]++;
            }
        }
        
        int freq=0, ans=-1;
        for(auto x: m)
            if(x.second>freq)
                ans=x.first,
                freq=x.second;
            
            return ans;
        }
};
