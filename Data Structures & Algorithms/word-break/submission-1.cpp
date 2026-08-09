// class Solution {
// public:
//     bool solve(vector<string>& wordDict,set<string>&st,int i,string &s){
//         int n=wordDict.size();
//         if(i>=s.size()){
//             return true;
//         }
//         bool flag=false;
//         for(int j=i;j<s.size();j++){
//             string temp=s.substr(i,j-i+1);
//             if(st.find(temp)!=st.end()){
//                 flag=solve(wordDict,st,j+1,s);
//             }
//         }
//         if(flag){
//             return true;
//         }else{
//             return false;
//         }


//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         set<string>st;
//         for(int i=0;i<wordDict.size();i++){
//             st.insert(wordDict[i]);
//         }
//         bool ans=solve(wordDict,st,0,s);
//         if(ans){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };



class Solution {
public:

    bool solve(string &s, unordered_set<string>& st, int i, vector<int>& dp) {

        if(i == s.size()) {
            return true;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        for(int j = i; j < s.size(); j++) {

            string temp = s.substr(i, j-i+1);

            if(st.find(temp) != st.end()) {

                if(solve(s, st, j+1, dp)) {
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st;

        for(auto word : wordDict) {
            st.insert(word);
        }

        vector<int> dp(s.size(), -1);

        return solve(s, st, 0, dp);
    }
};
