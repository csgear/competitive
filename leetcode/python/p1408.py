from typing import List


class Solution:
    """
    https://leetcode.com/problems/string-matching-in-an-array
    """

    def stringMatching(self, words: List[str]) -> List[str]:
        words.sort(key=len)
        res = []
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if words[i] in words[j]:
                    res.append(words[i])
                    break
        return res


if __name__ == "__main__":
    s = Solution()
    print(s.stringMatching(["mass", "as", "hero", "superhero"]))
