class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxHeap; 

        for (int i = 0; i < arr.size(); i++) {
            int dist = abs(arr[i] - x);
            maxHeap.push({dist, arr[i]});

            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<int> ans;
        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        sort(ans.begin(), ans.end()); 
        return ans;
    }
};