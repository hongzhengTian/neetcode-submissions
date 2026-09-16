class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for (string str : strs) {
            encoded_string = encoded_string + str + "||";
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strings;
        string tmp_string;
        int size_s = static_cast<int>(s.size());
        for (int i = 0; i < size_s; ++i) {
            if (s[i] == '|' && s[i + 1] == '|'){
                decoded_strings.push_back(tmp_string);
                tmp_string = "";
                i = i + 1;
            }
            else {
                tmp_string = tmp_string + s[i];
            }
        }
        return decoded_strings;
    }
};
