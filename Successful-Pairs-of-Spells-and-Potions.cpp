#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binary(vector<int>& potions, long long strength, long long success) {
        int pos = -1;
        int low = 0;
        int high = potions.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (1LL * potions[mid] * strength >= success) {
                pos = mid;
                high = mid - 1;   // left side mein aur chhota valid dhundo
            } else {
                low = mid + 1;
            }
        }
        return pos;  // ✅ loop ke baad return
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int index = binary(potions, spells[i], success);
            if (index != -1) {
                ans.push_back(m - index);  // ✅ sahi calculation
            } else {
                ans.push_back(0);
            }
        }

        return ans;
    }
};
