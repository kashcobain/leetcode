class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n = colors.size();
        int total = 0;
        int prev = time[0];

        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                total += min(prev, time[i]);
                prev = max(prev, time[i]);
            } else {
                prev = time[i];
            }
        }
        return total;
    }
};
