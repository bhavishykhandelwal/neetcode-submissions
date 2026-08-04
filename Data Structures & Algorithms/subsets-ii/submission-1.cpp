class Solution {
public:
    void solve(vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,int i){
        int n=nums.size();
        ans.push_back(temp);
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1]){
                continue;
            }
            temp.push_back(nums[j]);
            solve(nums,temp,ans,j+1);
            temp.pop_back();
        }


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>temp;
        solve(nums,temp,ans,0);
        return ans;
    }
};
