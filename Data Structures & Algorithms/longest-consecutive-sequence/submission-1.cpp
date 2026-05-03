class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi=1;
        sort(nums.begin(),nums.end());
        int c=1;
        if(nums.size()==0){
            return 0;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i - 1]) {
                continue; 
            }
            if(nums[i]-1==nums[i-1]){
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
