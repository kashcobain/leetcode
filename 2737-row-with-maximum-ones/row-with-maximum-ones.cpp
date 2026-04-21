class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> onecount{};
        int cnt = 0;
        for(size_t row = 0; row < mat.size(); ++row)
        {
            cnt = 0;
            for(size_t col = 0; col < mat[0].size(); ++col)
            {
                if(mat[row][col] == 1)
                    ++cnt;
            }
            onecount.push_back(cnt);
        }
        int mx = *max_element(onecount.begin(), onecount.end());
        for(int i = 0; i < onecount.size(); ++i)
        {
            if(onecount[i] == mx)
                return {i, mx};
        }
        return {0, 0};
    }
};