# DSA PROBLEMS I SOLVE DAILY

Today 26/09/2025 , I completed bubble sort, one step close to working in Google or Meta or Apple or Microsoft or Netflix.

I really want to use my programming skills in movie industry.

# DSA Log

*Use: Difficulty = Easy/Hard. Status = Done/Skipped.*

| Date       | Problem Type | Difficulty | Status | Notes |
| ---------- | ------------ | ---------- | ------ | ----- |
| 2025-09-23 | Binary Search|super easy  |✅     |basic binary search finding the number|
| 2025-09-24 |    Sorting   |super easy |   doing     |   Find three largest number in a unsorted array    |
| 2025-09-25 |   Sorting   |super easy |   ✅     |   Find three largest number in a unsorted array            |            |        |       |
| 2025-09-26 |    Sorting   |Super easy|    ✅    |   sort using bubble sort algorithm   |
| 2025-09-27 |      strings        | easy           |   ✅     |     caesar-cipher and compress string  |
| 2025-09-28 |      Strings       |    easy        | ✅       |      gets a list of common characters in all the arrays and returns it. |
| 2025-09-29 |   had other works           |            |        |       |
| 2025-09-30 |       wasted       |            |        |       |
| 2025-10-01 |      strings        | easy           | ✅       |   checks if characters are present in document matches with characters, along with the number of occurence    |
| 2025-10-02 |      strings        |  easy          | ✅       |   semordinalp    |
| 2025-10-02 |      strings        |      easy      |   ✅     |    distinct character count   |
| 2025-10-03 |        graph  and Greedy algorithm    |      easy      |  ✅      |    depth first search and shortest wait time  |
| 2025-10-04 |   easy and the last one was hard           |    ✅        |   greedy algorithm -- using mostly sorting .     |       |
| 2025-10-06 |              |            |        |       |

# Sorting Algorithms

Bubble sort: it's a basic swap and switch ;
Insertion sort: it's inserting a element into the sorted array by traversing through elements and locating the right place for the inserted element.
Selection sort: it's assuming that there is two subset of an array, one is sorted and the other is unsorted, we insert element one by one from unsorted array to sorted array by finding out the min/max depending on asc/desc order. 

everything here has the worst time complexity of O(n^2)

# Strings

1) caesar cipher -- easy
2) encodestring -- i was struggling here though it's easy, all it took was a small change in if condition.
3) semordnilap -- finding out if string has same word in the reverse order in the list of strings, and returning it
4) distinct char coutner == in a string, count the no of occurance of a character and sendiing the position of the first letter that is distinct.

# Greedy Algorithm
 
 First few problems were easy, since they were based on sorting, the last problem, with maximum profit was a little hard because it used dictionary method of finding the profit.. i lastly learned it in 8 math with permutation,, though it's a little different from that, but they use the same concept. assuming 7 days, and entering a loop to find the right point.

 # Arrays

 ### Problem5: 
 I tried to implement 3 sum algorithm within O(n^2) using hare and rabbit method.. like head keeping track of the front, and tail keeping track of the end, it sorta of binary search tree, but in arrays. 
# binary trees
 ### problem of min height


### Example Input

`array = [1, 2, 3, 4, 5, 6, 7]`

---

### Recursive Stack & Returned Values

```
constructTree(0,6) → mid=3 → node(4)
│
├── treeLeft = constructTree(0,2) → mid=1 → node(2)
│   │
│   ├── treeLeft = constructTree(0,0) → mid=0 → node(1)
│   │   ├── treeLeft  = constructTree(0,-1) → nullptr
│   │   └── treeRight = constructTree(1,0)  → nullptr
│   │   → returns node(1)
│   │
│   └── treeRight = constructTree(2,2) → mid=2 → node(3)
│       ├── treeLeft  = constructTree(2,1) → nullptr
│       └── treeRight = constructTree(3,2) → nullptr
│       → returns node(3)
│   │
│   → node(2) now has left=node(1), right=node(3)
│   → returns node(2)
│
└── treeRight = constructTree(4,6) → mid=5 → node(6)
    │
    ├── treeLeft = constructTree(4,4) → mid=4 → node(5)
    │   ├── treeLeft  = constructTree(4,3) → nullptr
    │   └── treeRight = constructTree(5,4) → nullptr
    │   → returns node(5)
    │
    └── treeRight = constructTree(6,6) → mid=6 → node(7)
        ├── treeLeft  = constructTree(6,5) → nullptr
        └── treeRight = constructTree(7,6) → nullptr
        → returns node(7)
    │
    → node(6) now has left=node(5), right=node(7)
    → returns node(6)
│
→ node(4) now has left=node(2), right=node(6)
→ returns node(4)
```

---

### 🧩 Final BST Returned (`tree` from constructTree(0,6))

```
        4
      /   \
     2     6
    / \   / \
   1  3  5  7
```

---

✅ **Summary (Return Flow)**

* Each call creates a `tree` node with value = `array[mid]`.
* Then gets:

  * `treeLeft` from the recursive call on the left half,
  * `treeRight` from the recursive call on the right half.
* When both are returned, it connects:
  `tree->left = treeLeft;`
  `tree->right = treeRight;`
  and then returns `tree` upward.

So when recursion unwinds, the **entire BST** is formed from bottom to top.
