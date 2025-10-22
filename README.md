# DSA PROBLEMS I SOLVE DAILY

Today 26/09/2025 , I completed bubble sort, one step close to working in Google or Meta or Apple or Microsoft or Netflix.

I really want to use my programming skills in movie industry.


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

#Tries

I have been struggling with this for 3 days.. just because i don't know how to implemement it right in c++.. but i came through it, and finished the solution, albeit easy, just need a little way of correctly initializing. I was just too focused on making it look exactly look like input example, but it should be done a little different.
this algorithm is self explanatory when you read the code, but just a overview:
a trie is used to traverse suffix of words.. that is to find if the existing dictionary contains a suffix . it keeps track of words by making sure, the prefix pattern mostly matches before it diverges. so normally the tree could have 26 children , that is from root.. and each 26 letters could in turn have another 26 letters .. and so on and so on. 

It's not exactly like hashmaps, it's tries, hashmaps could be used for pointing to the right value with the right key, but in tries there is no right value or no right key, it just traverses untill the end to see if there is a suffix of the word with the existing word.

This is more summarized version" 
# HashMap vs Trie — Quick Reference

## 1. Core Idea

| Concept           | HashMap                                  | Trie                                                       |
| ----------------- | ---------------------------------------- | ---------------------------------------------------------- |
| Structure         | Key–value pairs stored via hash function | Tree-like structure where each node represents a character |
| Key Access        | Entire key hashed into a single lookup   | Key decomposed into characters traversed sequentially      |
| Lookup Complexity | **O(1)** average                         | **O(m)**, where *m* = key length                           |
| Space Usage       | High (hash overhead)                     | Higher for sparse data (stores every prefix)               |

---

## 2. When to Use

* **HashMap**:
  Use when you only need fast lookup of *complete keys* (e.g., ID → value, dictionary word check).

* **Trie**:
  Use when you need operations on *prefixes or patterns* (e.g., autocomplete, spell-check, IP routing, suffix search).

---

## 3. Advantages of Tries

1. **Prefix Search** — Efficiently find all words starting with a prefix.
2. **Lexicographical Ordering** — Natural sorting of stored strings.
3. **Space Optimization with Shared Prefixes** — Common prefixes are stored once.
4. **Predictive Typing / Autocomplete** — Fast retrieval of related keys.
5. **Security/Filtering** — Useful for pattern matching (e.g., detecting banned words).

---

## 4. Limitations of Tries

* High memory use for sparse datasets.
* Slower insertion/lookup than hashmaps when keys are long and few in number.
* Harder to serialize or persist compared to flat key–value pairs.

---

### Summary

> **Use HashMap** for direct key lookups.
> **Use Trie** when *prefix intelligence* or *pattern matching* matters.

