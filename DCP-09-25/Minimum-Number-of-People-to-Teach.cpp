class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> st;

        // Step 1: Find all users who need to learn a new language
        for (auto p : friendships) {
            int u = p[0] - 1;
            int v = p[1] - 1;
            bool real = false;

            // Check if u and v share a language
            for (int x : languages[u]) {
                for (int y : languages[v]) {
                    if (x == y) {
                        real = true;
                        break;
                    }
                }
                if (real) break; // dono loop se nikal ja
            }

            // Agar koi common language nahi hai
            if (!real) {
                st.insert(u);
                st.insert(v);
            }
        }

        // Step 2: Try teaching each language and minimize
        int ans = languages.size() + 1;
        for (int i = 1; i <= n; i++) {
            int count = 0;
            for (int v : st) {
                bool found = false;
                for (int c : languages[v]) {
                    if (c == i) {
                        found = true;
                        break;
                    }
                }
                if (!found) count++; // agar user ko ye language nahi aati
            }
            ans = min(ans, count);
        }

        return ans;
    }
};
