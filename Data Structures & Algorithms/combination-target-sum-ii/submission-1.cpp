class Solution {
public:
    void solve(vector<int>& candidates,
               vector<int>& temp,
               vector<vector<int>>& ans,
               int i,
               int target) {

        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(target < 0 || i == candidates.size()){
            return;
        }
        for(int j = i; j < candidates.size(); j++){
            if(j > i && candidates[j] == candidates[j-1]){
                continue;
            }
            if(candidates[j] > target){
                break;
            }

            temp.push_back(candidates[j]);
            solve(candidates, temp, ans, j+1, target-candidates[j]);
            temp.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates,temp,ans,0,target);

        return ans;
    }
};