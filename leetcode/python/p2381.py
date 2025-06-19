class Solution(object):
    """
    https://leetcode.com/problems/shifting-letters-ii/
    """

    def shiftingLetters(self, s, shifts):
        """
        :type s: str
        :type shifts: List[List[int]]
        :rtype: str
        """
        n = len(s)
        prefix_sum = [0] * (n + 1)
        for shift in shifts:
            start, end, direction = shift
            if direction == 0:
                prefix_sum[start] -= 1
                prefix_sum[end + 1] += 1
            else:
                prefix_sum[start] += 1
                prefix_sum[end + 1] -= 1
        for i in range(1, n + 1):
            prefix_sum[i] += prefix_sum[i - 1]
        result = []
        for i in range(n):
            result.append(
                chr((ord(s[i]) - ord('a') + prefix_sum[i]) % 26 + ord('a')))
        return ''.join(result)


if __name__ == '__main__':
    s = "abc"
    shifts = [[0, 1, 0], [1, 2, 1], [0, 2, 1]]
    print(Solution().shiftingLetters(s, shifts))
