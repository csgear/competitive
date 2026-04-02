

class Solution {
   public:
    bool isPrefixAndSuffix(const std::string& str1, const std::string& str2) {
        if (str1.length() > str2.length()) return false;
        return str2.substr(0, str1.length()) == str1 &&
               str2.substr(str2.length() - str1.length()) == str1;
    }

    int countPrefixSuffixPairs(std::vector<std::string>& words) {
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
