class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> maxi;
        priority_queue<int, vector<int>, greater<int>> mini;

        auto addNum = [&](int num) {
            if (maxi.empty() || num <= maxi.top())
                maxi.push(num);
            else
                mini.push(num);

            // Balance the heaps
            if (maxi.size() > mini.size() + 1) {
                mini.push(maxi.top());
                maxi.pop();
            } else if (mini.size() > maxi.size()) {
                maxi.push(mini.top());
                mini.pop();
            }
        };

        for (int x : nums1)
            addNum(x);

        for (int x : nums2)
            addNum(x);

        if (maxi.size() == mini.size())
            return (maxi.top() + mini.top()) / 2.0;

        return maxi.top();
    }
};