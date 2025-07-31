class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int> result;
        unordered_set<int> current;
        for(int val:arr){
            unordered_set<int> next;
            next.insert(val);
            for(int prev : current){
                next.insert(prev|val);
            }
            for(int val:next )
            {
                result.insert(val);
            }
            current=next;
        }

        return result.size();
    }
};