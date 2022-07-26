int lcs(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        //vector<vector<int>> dp(n+1, vector<int>(m+1, -1)); //shifting of indices
        vector<int> prev(m+1,0) , curr(m+1,0);
        
        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=m;i2++){
                if(s1[i1-1]==s2[i2-1]) curr[i2] = prev[i2-1]+1;
                else curr[i2] = max(prev[i2] , curr[i2-1]);
            }
            prev=curr;
        }
        return curr[m];
    }

int canYouMake(string &str, string &ptr)
{
    return str.size()+ptr.size()-2*lcs(str,ptr);
}
