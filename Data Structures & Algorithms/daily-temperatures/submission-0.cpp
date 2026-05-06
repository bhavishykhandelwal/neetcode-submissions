class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
        for(int i=0;i<temperatures.size();i++){
            int c=1;
            int j=i+1;
            while(j<temperatures.size()){
                if(temperatures[j]>temperatures[i]){
                    break;
                }
                else{
                    c++;
                    j++;
                }
            }

            if(j==n){
                c=0;    
            }
            ans[i]=c;
        }
        return ans;
    }
};
