class Solution(object):
    """
    https://leetcode.com/problems/counting-words-with-a-given-prefix/
    """

    def prefixCount1(self, words, pref):
        """
        :type words: List[str]
        :type pref: str
        :rtype: int
        """
        count = 0
        for word in words:
            if word.startswith(pref):
                count += 1
        return count

    def prefixCount(self, words, pref):
        """
        :type words: List[str]
        :type pref: str
        :rtype: int
        """
        trie = self._Trie()
        for word in words:
            trie._add_word(word)
        return trie._count_prefix(pref)

    class _Trie:
        # Node class represents each character in Trie
        class _Node:
            def __init__(self):
                # Links to child nodes
                self.links = [None] * 26
                # Number of strings having prefix till this node
                self.count = 0

        def __init__(self):
            self.root = self._Node()

        # Add word to trie and update prefix counts
        def _add_word(self, word: str) -> None:
            curr = self.root
            for c in word:
                idx = ord(c) - ord("a")
                if curr.links[idx] is None:
                    curr.links[idx] = self._Node()
                curr = curr.links[idx]
                curr.count += 1  # Increment count for this prefix

        # Return count of strings having pref as prefix
        def _count_prefix(self, pref: str) -> int:
            curr = self.root
            for c in pref:
                idx = ord(c) - ord("a")
                if curr.links[idx] is None:
                    return 0  # Prefix not found
                curr = curr.links[idx]
            return curr.count  # Return count at last node


if __name__ == "__main__":
    words = ["pay", "attention", "practice", "attend"]
    pref = "at"
    print(Solution().prefixCount(words, pref))
