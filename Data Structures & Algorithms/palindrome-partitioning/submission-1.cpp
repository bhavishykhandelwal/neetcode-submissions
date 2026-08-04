class Solution {
public:
    bool isPalindrome(string &temp){
        int i = 0;
        int j = temp.size() - 1;
        while(i < j){
            if(temp[i] != temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string s,
               vector<string>& res,
               vector<vector<string>>& ans,
               int i){

        int n = s.size();
        if(i == n){
            ans.push_back(res);
            return;
        }
        for(int j = i; j < n; j++){
            string temp = s.substr(i, j - i + 1);
            if(isPalindrome(temp)){
                res.push_back(temp);
                solve(s, res, ans, j + 1);
                res.pop_back(); 
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        solve(s, res, ans, 0);
        return ans;
    }
};
