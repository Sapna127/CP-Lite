   vector<string> letterCombinations(string digits) {
       vector<string> ans;
        if(!digits.size()) return ans;
        possibleCombination(digits,0,ans,"");
        return ans;
    }
    vector<string> v= {".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void possibleCombination(string digits,int idx, vector<string>&ans,string s){
         if(idx==digits.length()){
             ans.push_back(s);
             return;
         }
        string a = v[digits[idx]-'1'];
        for(int i=0;i<a.size();i++){
            possibleCombination(digits,idx+1,ans,s+a[i]);
        }
    }
