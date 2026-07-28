class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // set<int>st;
        // for(auto it:nums){
        //     st.insert(it);
        // }
        // if(st.size()==nums.size()){
        //     return false;
        // }
        // else{
        //     return true;
        // }
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
               return true;
            }

        }
        return false;


    }
};