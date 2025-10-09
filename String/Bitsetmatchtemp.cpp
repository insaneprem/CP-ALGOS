#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

// For each character, we keep a bitset telling where it appears
bitset<N> mask[26];

int main() {
    string text;
    cin >> text;
    int n = text.size();

    // Build the mask array
    for (int i = 0; i < n; i++) {
        mask[text[i] - 'a'][i] = 1;
    }

    int q;
    cin >> q;
    while (q--) {
        string pattern;
        cin >> pattern;

        // Step 1: Build occurrence mask for the pattern
        bitset<N> occ;
        occ.set(); // initially allow all positions

        for (int i = 0; i < (int)pattern.size(); i++) {
            int c = pattern[i] - 'a';
            occ &= (mask[c] >> i); // align and AND
        }

        // Step 2: Print total number of occurrences
        cout << occ.count() << "\n";

        // Step 3: Print all positions of occurrences
        vector<int> positions;
        int pos = occ._Find_first();
        while (pos < N) {
            positions.push_back(pos);
            pos = occ._Find_next(pos);
        }

        for (int p : positions) cout << p << " ";
        cout << "\n";

        // Step 4: Query for number of occurrences in a range [l, r] (1-indexed)
        int l, r;
        cin >> l >> r;

        int m = pattern.size();
        if (m > r - l + 1) {
            cout << 0 << "\n"; // pattern longer than range
        } else {
            // Using prefix-like trick with shifted counts
            int total = (occ >> (l - 1)).count() - (occ >> (r - m + 1)).count();
            cout << total << "\n";
        }
    }

    return 0;
}
