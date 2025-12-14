class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        unordered_map<string,int> businessOrder = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        int n = code.size();
        vector<pair<int,string>> ans;

        for (int i = 0; i < n; i++) {

            if (!isActive[i]) continue;

            if (businessOrder.find(businessLine[i]) == businessOrder.end())
                continue;

            if (code[i].empty()) continue;

            bool valid = true;
            for (char c : code[i]) {
                if (!(isalnum(c) || c == '_')) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;

            ans.push_back({businessOrder[businessLine[i]], code[i]});
        }

        sort(ans.begin(), ans.end());

        vector<string> fin;
        for (auto &p : ans) {
            fin.push_back(p.second);
        }

        return fin;
    }
};
