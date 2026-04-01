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
        long long deleted = 0;
        if (l > r) swap(l, r);

        // Find first interval that might overlap: iterator to first start > r
        auto it = segs.upper_bound(r);
        if (it != segs.begin()) {
            --it;
        } else {
            // begin is > r; nothing before
        }

        // Move left while intervals may still overlap (start could be <= r)
        vector<map<int,int>::iterator> to_erase;
        int nl = l, nr = r;

        // Ensure we start from an interval whose start <= r
        while (!segs.empty()) {
            if (it == segs.end()) break;
            if (it->first > r) {
                if (it == segs.begin()) break;
                --it;
                if (it->first > r) continue;
            }
            break;
        }

        // Sweep overlapping to the left
        for (;;) {
            if (segs.empty() || it == segs.end()) break;
            int a = it->first, b = it->second;
            if (b < l) break; // no overlap further left
            if (a > r) {
                // move left
                if (it == segs.begin()) break;
                --it;
                continue;
            }
            // Overlaps: [a,b] intersects [l,r]
            nl = min(nl, a);
            nr = max(nr, b);
            to_erase.push_back(it);
            if (it == segs.begin()) break;
            --it;
        }

        // Also check to the right from the first erased-right neighbor
        auto it2 = segs.upper_bound(r);
        while (it2 != segs.end()) {
            int a = it2->first, b = it2->second;
            if (a > nr) break; // since segs are ordered and non-overlapping
            if (a <= r && b >= l) {
                nl = min(nl, a);
                nr = max(nr, b);
                to_erase.push_back(it2);
                ++it2;
            } else if (a <= nr && a <= r && b < l) {
                ++it2;
            } else {
                break;
            }
        }

        // Deduplicate erase list (iterators unique but ensure order)
        sort(to_erase.begin(), to_erase.end(), [](auto x, auto y){ return x->first < y->first; });
        // Count deleted intervals
        deleted = (long long)to_erase.size();
        // Erase them
        for (auto &eit : to_erase) {
            segs.erase(eit);
        }

        // Insert merged interval
        segs[nl] = nr;
        return deleted;
    }

    long long count() const {
        return (long long)segs.size();
    }
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

