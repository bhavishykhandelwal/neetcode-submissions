class Solution {
public:
    void solve(string &s,int l,int r,string &ans,int &maxLen){
        
        while(l>=0 && r<s.size() && s[l]==s[r]){
            int len=r-l+1;
            if(len>maxLen){
                maxLen=len;
                ans=s.substr(l,len);
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        string ans="";
        int maxLen=0;
        for(int i=0;i<s.size();i++){
            solve(s,i,i,ans,maxLen);
            solve(s,i,i+1,ans,maxLen);
        }
        return ans;
    }
};
