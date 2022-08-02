#include<bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1)); //shifting of indices
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;
        
        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=m;i2++){
                if(s1[i1-1]==s2[i2-1]) dp[i1][i2] = dp[i1-1][i2-1]+1;
                else dp[i1][i2] = max(dp[i1-1][i2] , dp[i1][i2-1]);
            }
        }
        
        int len = dp[n][m];
        string s = "";
        for(int i=0;i<len;i++) s+="$";
        int idx = len-1;
        while(n>0 && m>0){
        	if(dp[n-1]==dp[m-1]){
        		s[idx]=s1[n-1];
        		idx--;
        		n--,m--;
        	}
        	else if(dp[n-1]>dp[m-1]){
        		n--;
        	}
        	else{
        		m--;
        	}
        }
        cout<<s;

}
int main(){
	 string s1 = "abcde";
	 string s2 = "bdgek";

	 cout << "The Longest Common Subsequence is ";
	 lcs(s1, s2);
}



