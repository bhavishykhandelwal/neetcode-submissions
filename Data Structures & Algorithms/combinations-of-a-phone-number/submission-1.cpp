class Solution {
public:
    void solve(string digits,string curr,vector<string>&ans,int i){
        map<int,string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";

        if(curr.size()==digits.size()){
            ans.push_back(curr);
            return;
        }
        string ch=mp[digits[i]-'0'];
        for(auto it:ch){
            solve(digits,curr+it,ans,i+1);
        }


    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
      
        if(digits.empty()){
            return ans;
        }
        solve(digits,"",ans,0);
        return ans;
    }
};
