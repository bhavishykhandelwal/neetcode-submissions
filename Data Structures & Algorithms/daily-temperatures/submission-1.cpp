class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        int n=temperatures.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int temp=temperatures[i];
            while(!st.empty() && temp>st.top().first){
                auto topTemp=st.top();
                st.pop();
                ans[topTemp.second]=i-topTemp.second;

            }
            st.push({temp,i});
        }
        return ans;
    }
};
