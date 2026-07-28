class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string original=strs[i];
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(original);
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
