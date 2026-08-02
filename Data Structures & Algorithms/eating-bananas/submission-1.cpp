class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int res=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            int total=0;
            for(auto it:piles){
                total=total+(ceil((double)it/mid));
            }
            if(total<=h){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
};
