class Solution {
public:

    bool pos(vector<vector<int>>& tasks, int energy)
    {
        for(auto task : tasks)
        {
            int req = task[1];
            int used = task[0];

            if(energy < req)
            {
                return false;
            }

            energy = energy - used;
        }

        return true;
    }

    struct cmp
    {
        bool operator()(const vector<int>& a,
                        const vector<int>& b) const
        {
            if(a[1]-a[0] == b[1]-b[0])
            {
                return a < b;
            }

            return a[1]-a[0] > b[1]-b[0];
        }
    };

    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(), cmp());

        int low = 1;
        int high = 1e9+7;

        int ans = 0;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(pos(tasks, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};