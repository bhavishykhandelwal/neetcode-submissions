class Solution {
public:
    void solve(vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,int i,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || i==nums.size()){
            return;
        }
        if(nums[i]<=target){
            temp.push_back(nums[i]);
            solve(nums,temp,ans,i,target-nums[i]);
            temp.pop_back();
        }
        solve(nums,temp,ans,i+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,temp,ans,0,target);
        return ans;
    }
};
