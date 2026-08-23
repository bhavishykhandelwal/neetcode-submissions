class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) {
            return false;
        }
        map<int, int> mp;
        for(auto it : hand) {
            mp[it]++;
        }

        while(!mp.empty()) {
            int curr = mp.begin()->first;
            for(int i = 0; i < groupSize; i++) {

                if(mp.find(curr + i) == mp.end()) {
                    return false;
                }

                mp[curr + i]--;

                if(mp[curr + i] == 0) {
                    mp.erase(curr + i);
                }
            }
        }

        return true;
    }
};
// [1,2,4,2,3,5,3,4]
// k=4
// 1->1
// 2->2
// 3->2;
// 4->2
// 5->1

// 1,2,3,4

// 2->1
// 3->1;
// 4->1
// 5->1

// 2,3,4,5

// now size is 0->true

