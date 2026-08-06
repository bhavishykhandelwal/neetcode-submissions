class PrefixTree {
public:
    unordered_map<string, bool> mp;

    PrefixTree() {

    }

    void insert(string word) {
        mp[word] = true;
    }

    bool search(string word) {
        return mp.find(word) != mp.end();
    }

    bool startsWith(string prefix) {
        int n = prefix.size();

        for(auto it : mp) {
            string s = it.first;

            if(s.size() >= n) {
                string pre = s.substr(0, n);

                if(pre == prefix) {
                    return true;
                }
            }
        }

        return false;
    }
};