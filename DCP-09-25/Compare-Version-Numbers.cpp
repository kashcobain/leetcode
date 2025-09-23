class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        stringstream ss2(version2);
        char del='.';
        string s1;
        string s2;
        vector<int> ans1;
        vector<int> ans2;
        while(getline(ss1,s1,del))
        {
            ans1.push_back(stoi(s1));
        }
        while(getline(ss2,s2,del))
        {
            ans2.push_back(stoi(s2));
        }
        int n=max(ans1.size(),ans2.size());
     for (int i = 0; i < n; i++) {
    int v1 = (i < ans1.size()) ? ans1[i] : 0;
    int v2 = (i < ans2.size()) ? ans2[i] : 0;

    if (v1 > v2) return 1;
    else if (v1 < v2) return -1;
}
return 0;



        


        
    }
};