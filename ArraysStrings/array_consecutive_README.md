# Longest Consecutive Sequence

**Difficulty:** Medium | **Pattern:** Hashing

## Problem

Given an unsorted array of integers, find the length of the longest consecutive element sequence in **O(n)** time.

```
Input:  [2, 20, 4, 10, 3, 4, 5]
Output: 4   (sequence: 2 -> 3 -> 4 -> 5)
```

## Approaches

### 1. Brute Force — O(n^3) Time

For every number, repeatedly scan the entire array for the next consecutive number.

```
Pick 2 → search for 3 (scan all) → found
       → search for 4 (scan all) → found
       → search for 5 (scan all) → found
       → search for 6 (scan all) → not found → streak = 4
```

Three layers of work: pick a start (n) x extend streak (n) x linear search (n).

### 2. Sorting — O(n log n) Time

Sort the array. Now consecutive numbers are adjacent — one linear scan finds all streaks.

```
sorted: [2, 3, 4, 4, 5, 10, 20]
         ^--------^  skip dup
         streak = 4
```

Good, but sorting is O(n log n). We can do better.

### 3. HashSet — O(n) Time (Optimal)

**Two key ideas:**

1. **O(1) lookup:** Put everything in a HashSet. Now "does x exist?" costs O(1), not O(n).
2. **Only start from sequence heads:** A number is the head of a sequence if `num - 1` is NOT in the set. This avoids counting the same sequence multiple times.

```
Set = {2, 20, 4, 10, 3, 5}

2:  is 1 in set?  NO  → start here → 2,3,4,5 → streak = 4
20: is 19 in set? NO  → start here → 20      → streak = 1
4:  is 3 in set?  YES → skip (not a head)
10: is 9 in set?  NO  → start here → 10      → streak = 1
3:  is 2 in set?  YES → skip
5:  is 4 in set?  YES → skip

Answer: 4
```

**Why O(n)?** Each number is touched at most twice — once in the outer loop, once inside a streak extension. The `if (set.count(num - 1))` guard ensures no number participates in two separate streak-building passes.

## Complexity Summary

| Approach    | Time       | Space | Idea                          |
|-------------|------------|-------|-------------------------------|
| Brute Force | O(n^3)     | O(1)  | Linear search for every step  |
| Sorting     | O(n log n) | O(1)  | Sort, then scan               |
| HashSet     | O(n)       | O(n)  | Set + start from heads only   |

## When to Use This Pattern

- Problems asking for **consecutive / contiguous value sequences** in unsorted data.
- Anytime you need **O(1) membership checks** to replace repeated linear scans.
- Similar problems: Longest Consecutive Path in Binary Tree, Array Nesting.
