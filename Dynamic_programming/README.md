
# 🔹 Worked Example – `aplothm` → `algorithm`

We want to convert:

```
str1 = "aplothm"   (len = 7)
str2 = "algorithm" (len = 9)
```

### Step 1: Build the table

We’ll make a grid of size `(len(str1)+1) × (len(str2)+1)` = `8 × 10`.

* Rows = characters of `str1` + empty prefix
* Columns = characters of `str2` + empty prefix

Base case filling:

* `dp[i][0] = i` (cost of deleting all chars from `str1`)
* `dp[0][j] = j` (cost of inserting all chars into `str1`)

### Step 2: Fill in transitions

Here’s a **partial visualization** (not full 8×10, but enough to show the pattern):

```
      ""  a  l  g  o  r  i  t  h  m
   ---------------------------------
"" |  0  1  2  3  4  5  6  7  8  9
a  |  1  0  1  2  3  4  5  6  7  8
p  |  2  1  1  2  3  4  5  6  7  8
l  |  3  2  1  2  3  4  5  6  7  8
o  |  4  3  2  2  2  3  4  5  6  7
t  |  5  4  3  3  3  3  4  4  5  6
h  |  6  5  4  4  4  4  4  5  4  5
m  |  7  6  5  5  5  5  5  5  5  4
```

### Step 3: Read the result

The bottom-right corner (`dp[7][9] = 4`) tells us:

👉 It takes **4 edits** to transform `"aplothm"` into `"algorithm"`.
(Insert `g`, replace `p` with `r`, insert `i`, and reorder/align `h m`.)

---

# 🔹 Space-Optimized Algorithm

We don’t actually need the whole 2D table — only the **previous row** to compute the current row.
This reduces **space complexity from O(nm) → O(min(n, m))**.

### Pseudocode

```python
def levenshtein(str1, str2):
    if len(str1) < len(str2):
        str1, str2 = str2, str1  # make sure str1 is the longer one

    prev = list(range(len(str2) + 1))  # dp[0][j]
    curr = [0] * (len(str2) + 1)

    for i in range(1, len(str1) + 1):
        curr[0] = i  # base case for row
        for j in range(1, len(str2) + 1):
            if str1[i-1] == str2[j-1]:
                curr[j] = prev[j-1]  # no edit needed
            else:
                curr[j] = 1 + min(
                    prev[j],    # delete
                    curr[j-1],  # insert
                    prev[j-1]   # replace
                )
        prev, curr = curr, prev  # swap rows

    return prev[len(str2)]
```

---

# 🔹 Key Takeaways

* **Classic DP:** Easy to understand, builds a full matrix.
* **Optimized DP:** Same logic but uses only 2 arrays (previous + current row).
* **Real-world usage:** Spell check, auto-complete, fuzzy matching, DNA sequencing.


