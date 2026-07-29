class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=1;
        int c=1;
        if(nums.size()==0){
            return 0;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            else if(nums[i]==nums[i-1]+1){
                c++;
            }
            else{
                c=1;
            }
            maxi=max(maxi,c);
        }
        return maxi;
    }
};
