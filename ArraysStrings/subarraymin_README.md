# 907. Sum of Subarray Minimums

## Problem
Given an array of integers, find the sum of `min(b)` where `b` ranges over every contiguous subarray. Return answer modulo `10^9 + 7`.

## Three Approaches

### 1. Brute Force — O(n^3) time, O(1) space
- Generate every subarray `(i, j)`.
- For each subarray, scan with a third loop `k` to find the minimum.
- Add that minimum to the total sum.
- **Why it's slow:** Three nested loops. For `n = 30000`, that's 2.7 * 10^13 operations.

### 2. Optimized Brute Force — O(n^2) time, O(1) space
- **Key insight:** When you extend subarray `[i..j]` to `[i..j+1]`, the new minimum is just `min(old_min, arr[j+1])`. No need to rescan.
- Eliminates the innermost loop by carrying the minimum forward.
- **Still too slow** for `n = 30000` (9 * 10^8 operations).

### 3. Monotonic Stack — O(n) time, O(n) space

#### The Mental Shift

**Naive thinking:** Look at each subarray, find its minimum.
**Optimal thinking:** Look at each element, ask "how many subarrays am I the boss (minimum) of?"

Then: `answer = sum of arr[i] * count[i]` for all i.

#### Building intuition with `[3, 1, 2, 4]`

Pick element `2` at index 2. Where can a subarray start and end such that `2` is the smallest?
```
arr:   3   1   2   4
                ↑
               [2]    ← I'm the minimum here
               [2, 4] ← I'm still the minimum
    Can I expand left to include 1?
    NO — 1 < 2, so 1 would become the minimum, not me.
```
So `2` is the minimum of exactly **2** subarrays: `[2]` and `[2,4]`.
Contribution = `2 * 2 = 4`.

Now pick element `1` at index 1:
```
arr:   3   1   2   4
       ↑   ↑   ↑   ↑
      [3,  1]        ← I'm the minimum
           [1]       ← I'm the minimum
           [1, 2]    ← I'm the minimum
      [3,  1, 2]     ← I'm the minimum
           [1, 2, 4] ← I'm the minimum
      [3,  1, 2, 4]  ← I'm the minimum
```
`1` can expand left 1 step (3 > 1, fine) and right 2 steps (2 > 1 and 4 > 1, fine).
That gives **2** start choices (index 0 or 1) x **3** end choices (index 1, 2, or 3).
Total = `2 * 3 = 6` subarrays. Contribution = `1 * 6 = 6`.

#### So how do you find those boundaries?

For each element, you need:
- **left[i]:** How far left can I go before hitting something smaller?
- **right[i]:** How far right can I go before hitting something smaller?
```
arr:     3    1    2    4

For 1:   3>1       1       2>1     4>1
         ← OK    HERE     OK →    OK →
         left = 2          right = 3

For 2:        1<2    2    4>2
              STOP  HERE   OK →
         left = 1    right = 2
```
`count[i] = left[i] * right[i]` — pick any start in the left range, any end in the right range.

Finding these naively is O(n) per element = O(n^2) total. A **monotonic stack** finds ALL of them in one pass — O(n) total — because each element is pushed and popped at most once.

#### The stack acts as a memory

As you scan left to right, the stack remembers "elements still waiting to find something smaller to their right." When a new smaller element arrives, it "defeats" the bigger ones (pops them) and becomes their boundary.
```
Processing [3, 1, 2, 4]:

i=0 (3): stack empty, push 3.       stack: [3]
i=1 (1): 1 < 3, pop 3. Push 1.     stack: [1]
         (3's right boundary found = index 1)
i=2 (2): 2 > 1, no pop. Push 2.    stack: [1, 2]
i=3 (4): 4 > 2, no pop. Push 4.    stack: [1, 2, 4]
End: remaining elements have no right boundary
     (they're the min all the way to the end)
```

#### Why `>` on left and `>=` on right?
To handle **duplicates**. If two elements have the same value, one must "own" the overlapping subarrays and the other must not. Using strict `>` on one side and `>=` on the other ensures each subarray is counted exactly once.

#### Monotonic Stack Walkthrough for `[3, 1, 2, 4]`

**Left pass (previous less-or-equal):**
```
i=0 (val=3): stack empty        → left[0] = 0+1 = 1  | stack: [0]
i=1 (val=1): pop 3 (3>1)       → left[1] = 1+1 = 2  | stack: [1]
i=2 (val=2): 1 not > 2, stop   → left[2] = 2-1 = 1  | stack: [1,2]
i=3 (val=4): 2 not > 4, stop   → left[3] = 3-2 = 1  | stack: [1,2,3]
```

**Right pass (next strictly less):**
```
i=3 (val=4): stack empty        → right[3] = 4-3 = 1 | stack: [3]
i=2 (val=2): pop 4 (4>=2)      → right[2] = 4-2 = 2 | stack: [2]
i=1 (val=1): pop 2 (2>=1)      → right[1] = 4-1 = 3 | stack: [1]
i=0 (val=3): 1 not >= 3, stop  → right[0] = 1-0 = 1 | stack: [0,1]
```

**Final calculation:**
```
arr[0]=3: 3 * 1 * 1 =  3
arr[1]=1: 1 * 2 * 3 =  6
arr[2]=2: 2 * 1 * 2 =  4
arr[3]=4: 4 * 1 * 1 =  4
                Total = 17 ✓
```

## Complexity Summary

| Approach | Time | Space | Passes constraint? |
|---|---|---|---|
| Brute Force | O(n^3) | O(1) | No |
| Better Brute | O(n^2) | O(1) | No |
| Monotonic Stack | O(n) | O(n) | Yes |
