from typing import List


class Solution:
    def isPrefixAndSuffix(self, str1, str2):
        return str2.startswith(str1) and str2.endswith(str1)

    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        n = len(words)
        ans = 0
        for i in range(n):
            for j in range(i+1, n):
                if self.isPrefixAndSuffix(words[i], words[j]):
                    ans += 1
        return ans


if __name__ == "__main__":
    solution = Solution()
    print(solution.countPrefixSuffixPairs(["a", "aba", "ababa", "aa"]))
