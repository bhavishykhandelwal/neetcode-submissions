/*
class Solution {
public:
    bool isPalindrome(string &temp){
        int i=0;
        int j=temp.size()-1;
        while(i<=j){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s,int i){
        int total=0;
        for(int j=i;j<s.size();j++){
            string temp=s.substr(i,j-i+1);
            if(isPalindrome(temp)){
                total++;
            }
        }
        return total;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans += solve(s,i);
        }

        return ans;

    }
};
*/


class Solution {
public:
    int solve(string &s,int l,int r){
        int c=0;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            c++;
            l--;
            r++;
        }
        
        return c;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=solve(s,i,i);
            ans+=solve(s,i,i+1);
        }
        return ans;
    }
};








