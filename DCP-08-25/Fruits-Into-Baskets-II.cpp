class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int rem = 0;
        int n = baskets.size();

        for (auto& fruit : fruits) {
            int var = 1;

            for (int i = 0; i < n; i++) {
                if (fruit <= baskets[i]) {
                    baskets[i] = 0;
                    var = 0;
                    break;
                }
            }

            rem += var;
        }

        return rem;
    }
};