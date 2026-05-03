class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum==target){
                return {i+1,j+1};
            }
            else if(sum>target){
                j--;
            }
            else{
                i++;
            }
        }
        return {-1,-1};
    }
};

/*
since we are traversing each element only once so the time complexity will be O(n) & the space comp. would be O(1).
*/
