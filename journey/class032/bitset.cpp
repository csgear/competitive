// https://leetcode.cn/problems/design-bitset/

#include <bits/stdc++.h>

using namespace std;

class Bitset {
   private:
    int ones;
    int zeros;
    bool reversed;
    int size;
    vector<int> data;

   public:
    Bitset(int n) {
        this->size = n;
        this->ones = 0;
        this->zeros = size;
        this->reversed = false;
        int capacity = (size + 31) / 32;
        data.resize(capacity, 0);
    }

    void fix(int i) {
        int index = i / 32;
        int bit = i % 32;
        if (!reversed) {
            if ((data[index] & (1 << bit)) == 0) {
                zeros--;
                ones++;
                data[index] |= (1 << bit);
            }
        } else {
            if ((data[index] & (1 << bit)) != 0) {
                zeros--;
                ones++;
                data[index] &= ~(1 << bit);
            }
        }
    }

    void unfix(int i) {
        int index = i / 32;
        int bit = i % 32;
        if (!reversed) {
            if ((data[index] & (1 << bit)) != 0) {
                zeros++;
                ones--;
                // clear the bit
                data[index] &= ~(1 << bit);
            }
        } else {
            if ((data[index] & (1 << bit)) == 0) {
                zeros++;
                ones--;
                data[index] |= (1 << bit);
            }
        }
    }

    void flip() {
        reversed = !reversed;
        int tmp = ones;
        ones = zeros;
        zeros = tmp;
    }

    bool all() { return (ones == size); }

    bool one() { return ones > 0; }

    int count() { return ones; }

    string toString() {
        string result;
        for (int i = 0; i < size; ++i) {
            int index = i / 32;
            int bit = i % 32;
            int status = (data[index] >> bit) & 1;
            if (reversed) {
                status = !status;
            }
            result += '0' + status;
        }
        return result;
    }
};
