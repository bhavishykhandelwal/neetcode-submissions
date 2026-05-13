class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        for(int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];

            int dis = x*x + y*y;
            pq.push({dis, {x, y}});
        }

        vector<vector<int>> ans;

        while(k--){
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            ans.push_back({x, y});
            pq.pop();
        }

        return ans;
    }
};
