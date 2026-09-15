class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> freq_s;
        unordered_map<char, int> freq_t;
        for (char x : s) {
            ++freq_s[x];
        }
        for (char y : t) {
            ++freq_t[y];
        }
        return freq_s == freq_t;
    }
};
