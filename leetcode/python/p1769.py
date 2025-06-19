from typing import List


class Solution:
    """
    https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box
    """

    def minOperationsn2(self, boxes: str) -> List[int]:
        n = len(boxes)
        res = [0] * n
        for i in range(n):
            for j in range(n):
                if boxes[j] == '1':
                    res[i] += abs(i - j)
        return res

    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        answer = [0] * n
        balls_to_left = 0
        moves_to_left = 0
        balls_to_right = 0
        moves_to_right = 0
        for i in range(len(boxes)):
            answer[i] += moves_to_left
            balls_to_left += int(boxes[i])
            moves_to_left += balls_to_left

        for i in range(len(boxes) - 1, -1, -1):
            answer[i] += moves_to_right
            balls_to_right += int(boxes[i])
            moves_to_right += balls_to_right

        return answer


if __name__ == "__main__":
    s = Solution()
    print(s.minOperations("110"))
