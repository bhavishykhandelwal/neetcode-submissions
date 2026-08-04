class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,int i){
        int n=nums.size();
        if(i==n){
          ans.push_back(nums);
          return;
        }
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            solve(nums,ans,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums,ans,0);
        return ans;
    }
};
