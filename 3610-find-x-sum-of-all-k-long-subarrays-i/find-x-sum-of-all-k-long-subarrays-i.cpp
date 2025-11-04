#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freq;

            // Step 1: Count frequencies in current window
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            // Step 2: Make a max-heap (priority queue)
            // pair<frequency, number> — greater frequency first
            priority_queue<pair<int,int>> pq;

            for (auto &it : freq) {
                pq.push({it.second, it.first});
            }

            // Step 3: Take top x elements from heap
            int xsum = 0;
            for (int l = 0; l < x && !pq.empty(); l++) {
                auto top = pq.top();
                pq.pop();
                xsum += top.first * top.second;  // freq * number (depends on problem)
            }

            ans.push_back(xsum);
        }

        return ans;
    }
};


