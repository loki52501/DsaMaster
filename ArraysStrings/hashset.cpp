#include <iostream>
#include <vector>
#include <list>
using namespace std;

// ============================================================
// HOW A HASHSET WORKS INTERNALLY
// ============================================================
//
// A HashSet is just an array of "buckets". Each bucket is a list.
//
// To INSERT a value:
//   1. Compute: bucket_index = hash(value) % num_buckets
//   2. Go to that bucket (a linked list)
//   3. If value already exists in the list, do nothing (no duplicates)
//   4. Otherwise, append value to the list
//
// To COUNT (check existence):
//   1. Compute: bucket_index = hash(value) % num_buckets
//   2. Search that one small list — NOT the entire data
//
// WHY IS IT O(1)?
//   If we have n items and n buckets, each bucket has ~1 item on average.
//   So searching a bucket is O(1) on average, not O(n).
//
// VISUAL EXAMPLE (7 buckets, inserting 2, 20, 4, 10, 3, 5):
//
//   bucket[0]: -> 7  (7 % 7 = 0)
//   bucket[1]:
//   bucket[2]: -> 2  (2 % 7 = 2)
//   bucket[3]: -> 3 -> 10  (3 % 7 = 3, 10 % 7 = 3)  ← collision!
//   bucket[4]: -> 4  (4 % 7 = 4)
//   bucket[5]: -> 5 -> 12  (5 % 7 = 5, 12 % 7 = 5)  ← collision!
//   bucket[6]: -> 20 (20 % 7 = 6)
//
// Collisions are handled by chaining (multiple items in one bucket's list).
// ============================================================

class HashSet {
private:
    int numBuckets;
    vector<list<int>> buckets;    // array of linked lists

    // Hash function: maps any integer to a valid bucket index
    int getBucket(int key) {
        // abs() handles negative numbers
        // % numBuckets keeps index within array bounds
        return abs(key) % numBuckets;
    }

public:
    HashSet(int size = 10) : numBuckets(size), buckets(size) {}

    // ---- INSERT ----
    // 1. Find which bucket this key belongs to
    // 2. Check if key already exists (no duplicates allowed)
    // 3. If not found, add it to the bucket's list
    void insert(int key) {
        int idx = getBucket(key);

        // Check for duplicates in this bucket
        for (int val : buckets[idx]) {
            if (val == key) {
                cout << "  insert(" << key << "): already exists in bucket["
                     << idx << "], skipping" << endl;
                return;
            }
        }

        buckets[idx].push_back(key);
        cout << "  insert(" << key << "): hash=" << idx
             << " → placed in bucket[" << idx << "]" << endl;
    }

    // ---- COUNT ----
    // Returns 1 if key exists, 0 if not (mirrors unordered_set::count)
    // 1. Find which bucket to look in
    // 2. Search ONLY that bucket — this is why it's O(1) average
    int count(int key) {
        int idx = getBucket(key);

        for (int val : buckets[idx]) {
            if (val == key) return 1;   // found
        }
        return 0;                        // not found
    }

    // Print the internal state of all buckets
    void display() {
        cout << "\n--- Internal State ---" << endl;
        for (int i = 0; i < numBuckets; i++) {
            cout << "  bucket[" << i << "]: ";
            if (buckets[i].empty()) {
                cout << "(empty)";
            } else {
                for (int val : buckets[i])
                    cout << val << " -> ";
                cout << "NULL";
            }
            cout << endl;
        }
        cout << "----------------------\n" << endl;
    }
};

int main() {
    // Use 7 buckets so we can see collisions clearly
    HashSet set(7);

    // === INSERTION ===
    cout << "=== Inserting elements ===" << endl;
    set.insert(2);
    set.insert(20);     // 20 % 7 = 6
    set.insert(4);
    set.insert(10);     // 10 % 7 = 3 → same bucket as 3!
    set.insert(3);      // 3 % 7 = 3  → collision with 10
    set.insert(5);
    set.insert(4);      // duplicate — should be skipped

    set.display();

    // === COUNT (existence check) ===
    cout << "=== Checking existence ===" << endl;
    int queries[] = {2, 3, 4, 5, 6, 10, 20, 99};
    for (int q : queries) {
        cout << "  count(" << q << ") = " << set.count(q)
             << (set.count(q) ? "  (found)" : "  (not found)") << endl;
    }

    // === WHY THIS MATTERS FOR LONGEST CONSECUTIVE SEQUENCE ===
    cout << "\n=== Using our HashSet for Longest Consecutive Sequence ===" << endl;
    int nums[] = {2, 20, 4, 10, 3, 4, 5};
    int n = 7;

    // Build set
    HashSet s(20);
    for (int i = 0; i < n; i++)
        s.insert(nums[i]);

    // Find longest consecutive sequence using our HashSet
    int best = 0;
    for (int i = 0; i < n; i++) {
        // Only start from heads: num-1 should NOT exist
        if (s.count(nums[i] - 1)) continue;

        int streak = 1;
        while (s.count(nums[i] + streak))
            streak++;

        best = max(best, streak);
    }
    cout << "\n  Longest Consecutive Sequence: " << best << endl;

    return 0;
}
