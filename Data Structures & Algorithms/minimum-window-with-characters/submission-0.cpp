class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp1;

        for(auto it : t){
            mp1[it]++;
        }

        int minLen = INT_MAX;
        string ans = "";

        for(int i = 0; i < s.size(); i++) {

            unordered_map<char, int> mp2;
            unordered_map<char, int> temp = mp1;

            for(int j = i; j < s.size(); j++) {

                char ch = s[j];
                mp2[ch]++;

                if(temp.find(ch) != temp.end()){
                    temp[ch]--;
                    if(temp[ch] == 0){
                        temp.erase(ch); 
                    }
                }

                // if all chars matched
                if(temp.size() == 0){
                    if(j - i + 1 < minLen){
                        minLen = j - i + 1;
                        ans = s.substr(i, j - i + 1);
                    }
                    break; 
                }
            }
        }

        return ans;
    }
};