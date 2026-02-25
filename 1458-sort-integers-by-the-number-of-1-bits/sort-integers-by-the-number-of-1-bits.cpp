class Solution {
public:
struct compare {
    bool operator()(int a, int b) const {
        int bitsA = __builtin_popcount(a);
        int bitsB = __builtin_popcount(b);

        if(bitsA == bitsB)
            return a < b;   

        return bitsA < bitsB;
    }
};
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare());
        return arr;
        
    }
};