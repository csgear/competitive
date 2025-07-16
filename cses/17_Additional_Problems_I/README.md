### 3105 Distinct Values Sum

Use contribution technique: instead of counting distinct values per subarray (O(n³)), count how many subarrays each element contributes to (O(n log n)).

Key insight: Element a[i] contributes to a subarray's distinct sum only if it's the first occurrence of its value in that subarray.

Formula: For each position i, count subarrays where a[i] is first occurrence = (i - lastIndex) × (n - i + 1)
