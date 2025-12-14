class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        for(auto &it : points) {
            int dist = it[0]*it[0] + it[1]*it[1];
            pq.push({dist, {it[0], it[1]}});
        }

        vector<vector<int>> ans;
        while(k--) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            ans.push_back({x, y});
            pq.pop();
        }

        return ans;
    }
};
