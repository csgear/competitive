# CSES 13 Bitwise Operations Problems

## 1146 - Counting Bits

Count the total number of 1-bits in binary representations of all numbers from 0 to n.

**Key insight**: Use bit position analysis. For each bit position i, count how many numbers from 0 to n have that bit set. The pattern repeats every 2^(i+1) numbers with 2^i consecutive 1s followed by 2^i consecutive 0s.

**Algorithm**: For each bit position, calculate complete blocks and handle remainder separately.
Time complexity: O(log n)

## 1655 - Maximum XOR Subarray

Find the subarray with maximum XOR value.

**Key insight**: Use prefix XOR with trie optimization. XOR of subarray [i,j] = prefix[j] ⊕ prefix[i-1]. For each prefix, find the previous prefix that maximizes XOR using binary trie.

**Algorithm**:

1. Build binary trie storing all previous prefix XORs
2. For each new prefix, greedily find the stored prefix that gives maximum XOR
3. Use array-based trie implementation for better performance

Time complexity: O(n log(max_value))
