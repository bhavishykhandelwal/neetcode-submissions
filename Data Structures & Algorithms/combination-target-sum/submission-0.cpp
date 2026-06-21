class Solution {
public:
    void solve(vector<int>& nums, vector<int>& res,
               vector<vector<int>>& ans, int tar, int i) {

        if (tar == 0) {
            ans.push_back(res);
            return;
        }

        if (i == nums.size() || tar < 0)
            return;

        res.push_back(nums[i]);
        solve(nums, res, ans, tar - nums[i], i);
        res.pop_back();

        solve(nums, res, ans, tar, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(nums, res, ans, target, 0);
        return ans;
    }
};



