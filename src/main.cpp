#include <bits/stdc++.h>
using namespace std;

// We maintain a set of disjoint, non-adjacent closed intervals [l, r].
// Operations:
//  - A l r: Insert a mandatory class interval [l, r]; delete all existing
//            activities that overlap with [l, r] and return the number deleted.
//            After deletions, we add [l, r] as a blocking interval.
//  - B: Return the current count of remaining activities.
//
// Interpretation:
//  Each prior A inserts an "activity" interval. When a new A arrives,
//  we must remove all existing intervals overlapping the new one and then
//  add the new interval. The total number of intervals is requested by B.
//
// To satisfy constraints (n up to 2e5, l,r up to 1e5), we use an ordered map
// keyed by interval start to store disjoint intervals. On insertion, we merge
// any overlapping or adjacent intervals with the new one. The deleted count
// equals how many pre-existing intervals overlapped and were removed.

struct IntervalSet {
    // map of start -> end for disjoint, non-overlapping intervals
    map<int,int> segs;

    // Insert [l,r]; remove and count overlapping intervals; merge to keep disjoint
    long long insert_and_count_deleted(int l, int r) {
        if (l > r) swap(l, r);
        long long deleted = 0;

        // Find first candidate that could overlap: start from lower_bound(l)
        auto it = segs.lower_bound(l);
        if (it != segs.begin()) {
            auto pit = prev(it);
            if (pit->second >= l) it = pit; // pit overlaps into [l,r]
        }

        // Erase all intervals that overlap [l,r] (inclusive endpoints)
        while (it != segs.end() && it->first <= r && it->second >= l) {
            it = segs.erase(it);
            ++deleted;
        }

        // Insert the new interval as-is
        segs[l] = r;
        return deleted;
    }

    long long count() const { return (long long)segs.size(); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    IntervalSet S;
    for (int i = 0; i < n; ++i) {
        char op;
        cin >> op;
        if (op == 'A') {
            int l, r;
            cin >> l >> r;
            cout << S.insert_and_count_deleted(l, r) << '\n';
        } else if (op == 'B') {
            cout << S.count() << '\n';
        } else {
            // Unknown op, consume possible rest of line silently
            string rest;
            getline(cin, rest);
        }
    }
    return 0;
}
