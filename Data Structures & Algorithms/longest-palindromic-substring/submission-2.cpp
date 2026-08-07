// class Solution {
// public:
//     bool isPalindrome(string &temp){
//         int i=0;
//         int j=temp.size()-1;
//         while(i<=j){
//             if(temp[i]!=temp[j]){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
//     string solve(string &s,string &ans,int index,int &maxLen){
//         int n=s.size();
//         if(index>=n){
//             return ans;
//         }
//         for(int j=index;j<n;j++){
//             string temp=s.substr(index,j-index+1);
//             int len=j-index+1;
//             if(isPalindrome(temp) && len>maxLen){
//                 ans=temp;
//                 maxLen=len;
//             }
//         }
//         solve(s,ans,index+1,maxLen);
//         return ans;
//     }
//     string longestPalindrome(string s) {
//        string ans="";
//        int maxLen=0;
//         solve(s,ans,0,maxLen);
//         return ans;
//     }
// };



class Solution {
public:

    void expand(string &s, int l, int r, string &ans, int &maxLen) {

        while(l >= 0 && r < s.size() && s[l] == s[r]) {

            int len = r - l + 1;

            if(len > maxLen) {
                maxLen = len;
                ans = s.substr(l, len);
            }

            l--;
            r++;
        }
    }


    string longestPalindrome(string s) {

        string ans = "";
        int maxLen = 0;

        int n = s.size();

        for(int i = 0; i < n; i++) {

            // Odd length palindrome
            expand(s, i, i, ans, maxLen);

            // Even length palindrome
            expand(s, i, i+1, ans, maxLen);
        }

        return ans;
    }
};
