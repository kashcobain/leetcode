#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freq;

            // Step 1: count frequency in window
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            // Step 2: make min-heap (keep top x elements)
            // Heap sorted by frequency (smallest on top)
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

            for (auto &it : freq) {
                pq.push({it.second, it.first});  // {freq, num}
                if (pq.size() > x) pq.pop();     // pop smallest freq
            }

            // Step 3: sum top x (remaining in heap)
            int xsum = 0;
            while (!pq.empty()) {
                auto top = pq.top(); pq.pop();
                xsum += top.first * top.second;  // freq * num (as per problem)
            }

            ans.push_back(xsum);
        }

        return ans;
    }
};


