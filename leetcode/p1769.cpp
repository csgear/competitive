

class Solution {
   public:
    std::vector<int> minOperationsn2(std::string boxes) {
        int n = boxes.length();
        std::vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (boxes[j] == '1') {
                    res[i] += abs(i - j);
                }
            }
        }
        return res;
    }

    std::vector<int> minOperations(std::string boxes) {
        int n = boxes.length();
        std::vector<int> answer(n, 0);
        int balls_to_left = 0;
        int moves_to_left = 0;
        int balls_to_right = 0;
        int moves_to_right = 0;

        for (int i = 0; i < n; i++) {
            answer[i] += moves_to_left;
            balls_to_left += (boxes[i] - '0');
            moves_to_left += balls_to_left;
        }

        for (int i = n - 1; i >= 0; i--) {
            answer[i] += moves_to_right;
            balls_to_right += (boxes[i] - '0');
            moves_to_right += balls_to_right;
        }

        return answer;
    }
};
