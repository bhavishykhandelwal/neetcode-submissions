class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int target,
               vector<int>& temp, int idx) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]){
                continue;
            }
            if (nums[i] > target){
                break;
            }

            temp.push_back(nums[i]);
            solve(nums, target - nums[i], temp, i + 1);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, target, temp, 0);
        return ans;
    }
};